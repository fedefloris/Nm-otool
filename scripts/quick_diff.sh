# Test file
if [ "$1" = "" ]
then
	echo "usage: ./quick_test /some_dir/binary_to_test"
	exit 1
fi

nm "$1" > quick_sys
../ft_nm "$1" > quick_ft
if ! diff quick_sys quick_ft > quick_diff_report
then
	vim quick_diff_report
else
	echo "DIFF OK"
fi
rm -rf quick_sys quick_ft
rm -rf quick_diff_report
