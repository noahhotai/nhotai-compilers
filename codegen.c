#include "codegen.h"


bool reg_scratch_list[7] = {1, 1, 1, 1, 1, 1, 1};
const char* reg_name_list[7] = {"%rbx", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};
int global_label_counter = 0;
extern FILE* file;
int scratch_alloc(){
    int i;
    for(i = 0; i < 7; i++){
        if (reg_scratch_list[i] == 1){
            reg_scratch_list[i] = 0;
            return i;
        }
    }
    fprintf(file, "no more free registers\n");
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
    sprintf(temp, ".L%d", label);
    return strdup(temp);
}


const char * symbol_codegen(struct symbol * sym){
    if (sym->kind == SYMBOL_GLOBAL){
        return sym->name;
    }
    else if (sym->kind == SYMBOL_PARAM){
        char temp[BUFSIZ] = {0};
        sprintf(temp, "-%d(%%rbp)", 8 + (sym->which * 8));
        return strdup(temp);
    }
    else{ 
        char temp[BUFSIZ] = {0};
        sprintf(temp, "-%d(%%rbp)", 56+(sym->which * 8));
        return strdup(temp);
    }
}


void callee_preamble(){
    fprintf(file, "PUSHQ %%rbx\n");
    fprintf(file, "PUSHQ %%r12\n");
    fprintf(file, "PUSHQ %%r13\n");
    fprintf(file, "PUSHQ %%r14\n");
    fprintf(file, "PUSHQ %%r15\n");
}


void callee_postamble(){
    fprintf(file, "POPQ %%rbx\n");
    fprintf(file, "POPQ %%r12\n");
    fprintf(file, "POPQ %%r13\n");
    fprintf(file, "POPQ %%r14\n");
    fprintf(file, "POPQ %%r15\n");
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

void string_data_handler(struct expr * e, char* function_name){

        fprintf(file, ".data\n");
        int label_num = label_create();
        fprintf(file, "%s:\n", label_name(label_num));
        fprintf(file, ".string %s\n", e->string_literal); 
        fprintf(file, ".text\n");
        e->reg = scratch_alloc();
        fprintf(file, "MOVQ $%s, %s\n", label_name(label_num), scratch_name(e->reg));

}
