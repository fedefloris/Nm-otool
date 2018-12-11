# variables
REPORT=diff_report
VAL_REPORT=valgrind_report
DIFF_LOG=diff_log
VAL_LOG=valgrind_log
FAILED_TESTS=0

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

	# Checks diff
	if ! diff $FT $SY > $DIFF_LOG
	then
		echo "${RED}KO: ${WHITE}$f"
		FAILED_TESTS=$((FAILED_TESTS + 1))

		# Adds failure to diff_report
		echo ********************START $f >> $REPORT;
		cat $DIFF_LOG >> $REPORT
		echo ********************END\\n\\n\\n\\n\\n\\n\\n\\n\\n $f >> $REPORT;
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
	echo "${RED}$FAILED_TESTS Tests failed! For more details look at ./${REPORT}"
	exit 1
fi
