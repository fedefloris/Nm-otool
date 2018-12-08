# variables
REPORT=diff_report
VAL_REPORT=valgrind_report
DIFF_LOG=diff_log
VAL_LOG=valgrind_log

# colors
RED="\033[0;31m"
WHITE="\033[0;37m"
GREEN="\033[0;32m"

STATUS=0

FT=sys
SY=mine

# Clean reports
rm -rf $REPORT
rm -rf $VAL_REPORT

# Default test function
if [ -z "$FUNCTION" ]
then
	FUNCTION=nm
fi

# Checks if $FUNCTION exists
if ! [ -x "$(command -v $FUNCTION)" ]
then
	echo "${RED}${FUNCTION} not found"
	exit 1
fi

# Checks good directory
if [ -f ../ft_$FUNCTION ]
then
	FUNCTIONPATH=../ft_$FUNCTION
	DIR=../examples
else
	FUNCTIONPATH=./ft_$FUNCTION
	DIR=./examples
fi

# Checks if $FUNCTIONPATH exists
if ! [ -f $FUNCTIONPATH ]
then
	echo "${RED}${FUNCTIONPATH} not found"
	exit 1
fi

# Checks if valgrind is installed
if ! [ -x "$(command -v valgrind)" ]
then
	echo "${RED}valgrind is not installed"
	exit 1
fi

# TestS files in
if ! [ "$1" = "" ]
then
	DIR=$1
fi

# Prints initial info
echo "Testing all files in ${DIR}/\n"

# Iterates files
for f in $DIR/*;
do
	# Do ft_ and system function.
	$FUNCTION $OPTIONS $f 2>&- >> $SY;
	$FUNCTIONPATH $OPTIONS $f 2>&- >> $FT;

	echo -n "${WHITE}$FUNCTIONPATH $OPTIONS $f "

	# Checks diff
	if ! diff $FT $SY > $DIFF_LOG
	then
		echo "${RED}KO"

		# Adds failure to diff_report
		echo ********************START $f >> $REPORT;
		cat $DIFF_LOG >> $REPORT
		echo ********************END\\n\\n\\n\\n\\n\\n\\n\\n\\n $f >> $REPORT;
		STATUS=1
	else
		echo "${GREEN}OK"
	fi

	# Checks errors with valgrind
	valgrind -v --leak-check=full  \
     --track-origins=yes \
     --error-exitcode=2 \
		 --log-file=$VAL_LOG \
     $FUNCTIONPATH $OPTIONS $f > /dev/null 2>&1

	EXIT_STATUS=$?
	if [ $EXIT_STATUS -eq 2 ]
	then
		# Adds failure to valgrind_report
		echo ********************START $f >> $VAL_REPORT;
		cat $VAL_LOG >> $VAL_REPORT
		echo ********************END\\n\\n\\n\\n\\n\\n\\n\\n\\n $f >> $VAL_REPORT;
		STATUS=1
	fi

	#remove shite
	rm -rf $FT
	rm -rf $SY
	rm -rf $DIFF_LOG
	rm -rf $VAL_LOG
done

# Check final test state
if [ $STATUS -eq 0 ]
then
	echo "${GREEN}Tests passed!"
else
	echo "${RED}Tests failed! For more details look at ./${REPORT} and ./${VAL_REPORT}"
	exit 1
fi
