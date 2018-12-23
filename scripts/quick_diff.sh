# Test file
if [ "$1" = "" ]
then
	echo "usage: ./quick_test /some_dir/binary_to_test"
	exit 1
fi


# Set default test function
if [ -z "$FUNCTION" ]
then
	FUNCTION=nm
fi

$FUNCTION $OPTIONS "$1" > quick_sys
../ft_$FUNCTION $OPTIONS "$1" > quick_ft
if ! diff quick_sys quick_ft > quick_diff_report
then
	vim quick_diff_report
else
	echo "DIFF OK"
fi
rm -rf quick_sys quick_ft
rm -rf quick_diff_report
