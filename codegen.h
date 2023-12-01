#ifndef CODEGEN_H
#define CODEGEN_H
#include <stdlib.h>
#include "symbol.h"


bool reg_scratch_list[7] = {1};
char* reg_name_list[7] = {"%%rbx", "%%r10", "%%r11", "%%r12", "%%r13", "%%r14", "%%r15"};
int global_label_counter;

int scratch_alloc();
void scratch_free( int r );
const char * scratch_name( int r );
int label_create();
const char * label_name( int label );
const char * symbol_codegen( struct symbol *s );
// r 0 1 2 3 4 5 6
// name %rbx %r10 %r11 %r12 %r13 %r14 %r15
#endif