# Report files
REPORT=diff_report
VAL_REPORT=valgrind_report

# Colors
RED="\033[0;31m"
WHITE="\033[0;37m"
GREEN="\033[0;32m"

STATUS=0
FAILED_TESTS=0

# Tmp variables
FT=sys
SY=mine
DIFF_LOG=diff_log
VAL_LOG=valgrind_log

# Clean report files
rm -rf $REPORT
rm -rf $VAL_REPORT

# Set default valgrind use
if [ -z "$USE_VALGRIND" ]
then
	USE_VALGRIND=0
fi

# Set default test function
if [ -z "$FUNCTION" ]
then
	FUNCTION=nm
fi

# Check if $FUNCTION exists
if ! [ -x "$(command -v $FUNCTION)" ]
then
	echo "${RED}${FUNCTION} not found"
	exit 1
fi

# Check good directory
if [ -f ../ft_$FUNCTION ]
then
	FUNCTIONPATH=../ft_$FUNCTION
	DIR=../examples
else
	FUNCTIONPATH=./ft_$FUNCTION
	DIR=./examples
fi

# Check if $FUNCTIONPATH exists
if ! [ -f $FUNCTIONPATH ]
then
	echo "${RED}${FUNCTIONPATH} not found"
	exit 1
fi

# Check if valgrind is installed
if [ $USE_VALGRIND -eq 1 ] && ! [ -x "$(command -v valgrind)" ]
then
	echo "${RED}valgrind is not installed"
	exit 1
fi

# Test files in
if ! [ "$1" = "" ]
then
	DIR=$1
fi

# Print initial info
echo "Testing all files in ${DIR}/\n"

# Iterate files
for f in $DIR/*;
do
	# Do ft_ and system function.
	$FUNCTION $OPTIONS $f 2>&- >> $SY;
	$FUNCTIONPATH $OPTIONS $f 2>&- >> $FT;

	# Reset diff status
	DIFF_STATUS=0

	# Check diff
	if ! diff $FT $SY > $DIFF_LOG
	then
		echo "${RED}KO: ${WHITE}$f"
		FAILED_TESTS=$((FAILED_TESTS + 1))

		# Add failure to diff_report
		echo ********************START $f >> $REPORT;
		cat $DIFF_LOG >> $REPORT
		echo ********************END\\n\\n\\n\\n\\n\\n\\n\\n\\n $f >> $REPORT;
		STATUS=1
		DIFF_STATUS=1
	fi

	if [ $DIFF_STATUS -eq 0 ] && [ $USE_VALGRIND -eq 1 ]
	then
		# Check errors with valgrind
		valgrind -v --leak-check=full  \
			--track-origins=yes \
			--error-exitcode=2 \
			--log-file=$VAL_LOG \
			$FUNCTIONPATH $OPTIONS $f > /dev/null 2>&1

		# Check exit status of valgrind
		if [ $? -eq 2 ]
		then
			echo "${RED}KO: ${WHITE}$f"
			FAILED_TESTS=$((FAILED_TESTS + 1))

			# Add failure to valgrind_report
			echo ********************START $f >> $VAL_REPORT;
			cat $VAL_LOG >> $VAL_REPORT
			echo ********************END\\n\\n\\n\\n\\n\\n\\n\\n\\n $f >> $VAL_REPORT;
			STATUS=1
		fi
	fi

	# Remove garbage
	rm -rf $FT
	rm -rf $SY
	rm -rf $DIFF_LOG
	rm -rf $VAL_LOG
done

# Check final test status
if [ $STATUS -eq 0 ]
then
	echo "${GREEN}Tests passed!"
else
	echo "${RED}$FAILED_TESTS Tests failed! For more details look at ./${REPORT} and ./${VAL_REPORT}"
	exit 1
fi
