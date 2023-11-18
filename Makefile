CC=      gcc
LD=      gcc
CFLAGS=  -g -Wall -Wextra #-Werror #-std=gnu99 

.PHONY: test



bminor : bminor.o scanner.o parser.o expr.o stmt.o type.o param_list.o decl.o symbol.o hash_table.o scope.o
	$(LD) -o $@ $^

scanner.o: scanner.c 
	$(CC) $(CFLAGS) -c $< -o $@

hash_table.o: hash_table.c 
	$(CC) $(CFLAGS) -c $< -o $@

expr.o: expr.c 
	$(CC) $(CFLAGS) -c $< -o $@

scope.o: scope.c 
	$(CC) $(CFLAGS) -c $< -o $@

stmt.o: stmt.c 
	$(CC) $(CFLAGS) -c $< -o $@

type.o: type.c 
	$(CC) $(CFLAGS) -c $< -o $@


param_list.o: param_list.c 
	$(CC) $(CFLAGS) -c $< -o $@

decl.o: decl.c 
	$(CC) $(CFLAGS) -c $< -o $@

symbol.o: symbol.c 
	$(CC) $(CFLAGS) -c $< -o $@

bminor.o : bminor.c
	$(CC) $(CFLAGS) -c $< -o $@

scanner.c: scanner.flex
	flex -o $@ $<

parser.c token.h: parser.bison
	bison --defines=token.h --output=parser.c $^ -v

parser.o: parser.c token.h
	$(CC) $(CFLAGS) -c $^

test:
	./run_encoder_tests.sh
	./run_scanner_tests.sh
	./run_parser_tests.sh
	./run_printer_tests.sh
	./run_resolver_tests.sh
	./run_typechecker_tests.sh

clean: 
	rm -f *.o bminor scanner.c test/*/*.out

