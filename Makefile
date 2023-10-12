CFLAGS = -Wall -Wextra -lm
TEST_DIR = test

.PHONY: all run test test-encode test-decode test-scan clean

all: bminor

run: bminor
	./bminor --parse "parser/good0.bminor"


#SCANNER STAGE -----------------------------------------------------------------------------------------

bminor.o: bminor.c
	gcc $(CFLAGS) -c $< -o $@

scanner.c: scanner.flex
	flex -oscanner.c scanner.flex

scanner.o: scanner.c 
	gcc $(CFLAGS) -c scanner.c -o scanner.o


# PARSER STAGE ----------------------------------------------------------------------------------------
parser.c: token.h parser.bison
	bison --defines=token.h --output=parser.c parser.bison

parser.o: parser.c
	gcc $(CFLAGS) -c $< -o $@

bminor: bminor.o scanner.o parser.o
	gcc $(CFLAGS) $^ -o $@
#----------------------------------------------------------------------------------------------------

test-encode: bminor
	./runtest-encode.sh

test-scan: bminor scanner.c
	./runtest-scanner.sh

test-parser: bminor
	./runtest-parser.sh


#----------------------------------------------------------------------------------------------------
clean:
	rm -f bminor
	rm -f bminor.o
	rm -f scanner.c
