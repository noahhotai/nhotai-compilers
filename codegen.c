#include "codegen.h"


bool reg_scratch_list[7] = {1};
const char* reg_name_list[7] = {"%%rbx", "%%r10", "%%r11", "%%r12", "%%r13", "%%r14", "%%r15"};
int global_label_counter = 0;

int scratch_alloc(){
    int i;
    for(i = 0; i < 7; i++){
        if (reg_scratch_list[i] == 1){
            reg_scratch_list[i] = 0;
            return i;
        }
    }
    printf("no more free registers\n");
    return i;
}
void scratch_free( int r ){
    reg_scratch_list[r] = 1;
}

const char * scratch_name( int r ){
    return reg_name_list[r];
}
int label_create(){
    global_label_counter++;
    return global_label_counter;
}

const char *label_name(int label) {
    char temp[BUFSIZ] = {0};
    sprintf(temp, ".L%d:", label);
    return strdup(temp);
}


const char * symbol_codegen(struct symbol * sym){
    if (sym->kind == SYMBOL_GLOBAL){
        return sym->name;
    }
    else if (sym->kind == SYMBOL_PARAM){
        char temp[BUFSIZ] = {0};
        sprintf(temp, "-%d(%%rbp)", 8+(sym->which * 8));
        return strdup(temp);
    }
    else if (sym->kind == SYMBOL_LOCAL){
        // if ()
        char temp[BUFSIZ] = {0};
        sprintf(temp, "-%d(%%rbp)", 8+(syms->which * 8));
        return strdup(temp);
    }
}


void callee_preamble(){
    printf("pushq %%rbx\n");
    printf("pushq %%r12\n");
    printf("pushq %%r13\n");
    printf("pushq %%r14\n");
    printf("pushq %%r15\n");
}


void callee_postamble(){
    printf("popq %%rbx\n");
    printf("popq %%r12\n");
    printf("popq %%r13\n");
    printf("popq %%r14\n");
    printf("popq %%r15\n");
}
// r 0 1 2 3 4 5 6
// name %rbx %r10 %r11 %r12 %r13 %r14 %r15

int char_decode2(char* c){
    if (strlen(c) == 3){
        return c[1];
    }
    if (strlen(c) == 4){
        switch (c[3]){
            case 'a':
                return '\a';
            case 'b':
                return '\b';
            case 'e':
                return '\e';
            case 'f':
                return '\f';
            case 'n':
                return '\n';
            case 'r':
                return '\r';
            case 't':
                return '\t';
            case 'v':
                return '\v';
            case '\\':
                return '\\';
            case '\'':
                return '\'';
            default:
                return '\0';
        }
    }
    // in case of hex code
    char hex_values[3] = {*(c+4), *(c+5), '\0'};
    return (char) strtol(hex_values, NULL, 16);

}