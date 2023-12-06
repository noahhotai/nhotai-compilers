#ifndef CODEGEN_H
#define CODEGEN_H
#include <stdlib.h>
#include "symbol.h"

int char_decode2(char* c);
int scratch_alloc();
void scratch_free( int r );
const char * scratch_name( int r );
const char * label_name( int label );
const char * symbol_codegen( struct symbol * sym);
int label_create();
void string_data_handler(char* string_literal, char* function_name);
char *create_string_label();
void callee_preamble();
void callee_postamble();

// r 0 1 2 3 4 5 6
// name %rbx %r10 %r11 %r12 %r13 %r14 %r15
#endif