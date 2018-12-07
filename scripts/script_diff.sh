# default test function
if [ -z "$FUNCTION" ]
then
	FUNCTION=nm
fi

# directory for function
if [ -f ../ft_$FUNCTION ]
then
	FUNCTIONPATH=../ft_$FUNCTION
	DIR=../examples
else
	FUNCTIONPATH=./ft_$FUNCTION
	DIR=./examples
fi

# test files in
if ! [ "$1" = "" ]
then
	DIR=$1
fi

# variables
REPORT=report
DIFF=diff
TMP=tmp

STATUS=0

FT=sys
SY=mine

# Clean report and diff
rm -rf $REPORT
rm -rf $DIFF

# print intro:
echo diff check $FUNCTION $OPTIONS vs ft_$FUNCTION $OPTIONS on all files in $DIR/

# Iterate files
for f in $DIR/*;
do
	# do ft_ and system function.
	$FUNCTION $OPTIONS $f 2>&- >> $SY;
	$FUNCTIONPATH $OPTIONS $f 2>&- >> $FT;

	# check diff
	if ! diff $FT $SY > $TMP
	then

		# create failure to report
		echo $f >> $REPORT;

		# add failure to diff
		echo ********************START $f >> $DIFF;
		cat $TMP >> $DIFF
		echo ********************END\\n\\n\\n\\n\\n\\n\\n\\n\\n $f >> $DIFF;
		STATUS=1
	fi

	#remove shite
	rm -rf $FT
	rm -rf $SY
	rm -rf $TMP
done

# tests success
if [ $STATUS -eq 0 ]
then
	echo "diff \033[0;32mOK"
else
	echo "\033[0;31mdiff FAILED"
	cat $REPORT
	exit 1
fi
