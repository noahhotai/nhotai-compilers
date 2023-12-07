make
./bminor --codegen test.txt myprogram.s
gcc -g myprogram.s library.c -o myprogram
./myprogram 