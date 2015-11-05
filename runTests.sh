#! /bin/bash
make
if [ $? = 0 ] 
then
	test/Source/testTbUT
else
	echo "Please fix compiler errors!" 
fi
