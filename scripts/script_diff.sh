# test function
FUNCTION=nm


# test files in
if [ "$1" = "" ]
then
	DIR=../examples
else
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
echo diff check $FUNCTION v ft_$FUNCTION on all files in $DIR/


# Iterate files
for f in $DIR/*;
do
	# do ft_ and system function.
	$FUNCTION $f 2>&- >> $FT;
	../ft_$FUNCTION $f 2>&- >> $SY;


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
	echo "\x1b[32mdiff OK"
else
	echo "\x1b[31mdiff FAILED"
	cat $REPORT
	exit 1
fi
