#!/bin/sh

# for testfile in test/codegen/good*.bminor
# do
# 	if ./bminor --codegen $testfile $testfile.s > $testfile.out
# 	then
# 		gcc -g $testfile.s library.c -o $testfile.exe
# 		./$testfile.exe > $testfile.codegenout
# 		echo "$testfile success (as expected)"
# 	else
# 		echo "$testfile failure (INCORRECT)"
# 	fi
# done
#!/bin/sh

for testfile in test/codegen/good*.bminor
do
    if ./bminor --codegen $testfile $testfile.s > $testfile.out
    then
        gcc -g $testfile.s library.c -o $testfile.exe
        if [ $? -eq 0 ]; then
            ./$testfile.exe > $testfile.codegenout
            echo "$testfile success (as expected)"
        else
            echo "Compilation of $testfile.s failed"
        fi
    else
        echo "$testfile failure (INCORRECT)"
    fi
done
