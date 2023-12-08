#!/bin/sh

for testfile in test/codegen/good*.bminor
do
	if ./bminor --codegen $testfile $testfile.s > $testfile.out
	then
		gcc -g myprogram.s library.c -o myprogram
		./myprogram > $testfile.codegenout
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done
