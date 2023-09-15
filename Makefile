CC= gcc
LD= gcc
CELAGS= -g -Wall -std=gnu99

.PHONY: test
bminor : bminor.o scanner.o
	$(LD) -o $@ $^
scanner.o: scanner.c
	$(CC) $(CFLAGS) -c $^ -o $@

bminor.o: bminor.c
	$(CC) $(CFLAGS) -c $^ -o $@

scanner.c: scanner.flex 
	flex -o $@ $<

clean:
	rm -f *.o bminor scanner.c test/*/*.out
test:
	./runtest.sh
	./runscantest.sh
