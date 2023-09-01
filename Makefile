.PHONY:test
bminor : bminor.c
	gcc bminor.c -o bminor


make test :
	./runtest.sh

make clean :
	rm bminor
