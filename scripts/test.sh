# default test function
if [ -z "$FUNCTION" ]
then
	FUNCTION=nm
fi

# Checking if $FUNCTION exists
if ! [ -x "$(command -v $FUNCTION)" ]
then
	echo "\033[0;31m${FUNCTION} not found"
	exit 1
fi

# Checking good directory
if [ -f ../ft_$FUNCTION ]
then
	FUNCTIONPATH=../ft_$FUNCTION
	DIR=../examples
else
	FUNCTIONPATH=./ft_$FUNCTION
	DIR=./examples
fi

# Checking if $FUNCTIONPATH exists
if ! [ -f $FUNCTIONPATH ]
then
	echo "\033[0;31m${FUNCTIONPATH} not found"
	exit 1
fi

# Checking if valgrind is installed
if ! [ -x "$(command -v valgrind)" ]
then
	echo "\033[0;31mvalgrind is not installed"
	exit 1
fi

# test files in
if ! [ "$1" = "" ]
then
	DIR=$1
fi

# variables
DIFF=diff
TMP=tmp

# colors
RED="\033[0;31m"
WHITE="\033[0;37m"
GREEN="\033[0;32m"

STATUS=0

FT=sys
SY=mine

# Clean diff
rm -rf $DIFF

# print intro:
echo diff check $FUNCTION $OPTIONS vs ft_$FUNCTION $OPTIONS on all files in $DIR/

# Iterate files
for f in $DIR/*;
do
	# do ft_ and system function.
	$FUNCTION $OPTIONS $f 2>&- >> $SY;
	$FUNCTIONPATH $OPTIONS $f 2>&- >> $FT;

	echo -n "${WHITE}Testing: $FUNCTIONPATH $OPTIONS $f "

	# check diff
	if ! diff $FT $SY > $TMP
	then
		echo "${RED}KO"

		# add failure to diff
		echo ********************START $f >> $DIFF;
		cat $TMP >> $DIFF
		echo ********************END\\n\\n\\n\\n\\n\\n\\n\\n\\n $f >> $DIFF;
		STATUS=1
	else
		echo "${GREEN}OK"
	fi

	#remove shite
	rm -rf $FT
	rm -rf $SY
	rm -rf $TMP

	# Check errors with valgrind
	valgrind -v --leak-check=full  \
     --track-origins=yes \
     --error-exitcode=2 \
		 --log-file=valgrind_log \
     $FUNCTIONPATH $OPTIONS $f > /dev/null 2>&1

	rm -rf valgrind_log

	EXIT_STATUS=$?
	if [ $EXIT_STATUS -eq 2 ]
	then
		echo "error"
		exit 1
	fi

done

# tests success
if [ $STATUS -eq 0 ]
then
	echo "${GREEN}Tests passed!"
else
	echo "${RED}Tests failed! For more details look at ./${DIFF}"
	exit 1
fi
