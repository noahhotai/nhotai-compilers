#!/bin/sh

for testfile in encode_hidden/good*.bminor
do
	if ./bminor --parse $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in encode_hidden/bad*.bminor
do
	if ./bminor --parse $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done
