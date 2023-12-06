#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "scanner_func.c"
#include "string_encode.c"
#include "string_decode.c"
#include "decl.h"
#include "hash_table.h"
#include "scope.h"


struct decl *parser_result;
extern int yyparse();
int resolve_error;
int typecheck_error;
int func_local_count;
int global_count;
FILE* file;

// bool reg_scratch_list[7] = {1};
// char* reg_name_list[7] = {"%%rbx", "%%r10", "%%r11", "%%r12", "%%r13", "%%r14", "%%r15"};


void indent(int indents){
    for (int i = 0; i < indents; i++){
        printf("    ");
    }
}

int scanner_caller(char * file_name){
    yyin = fopen(file_name, "r");  
    if (scanner()) {
        printf("ERROR: Failure scanning\n");
        return 1;
    }
    return 0;
}

int encoder_caller(char* file_name){ 
    FILE* fp = fopen(file_name, "r");
    if (!fp){
        fprintf(stderr, "ERROR: Unable to open file.\n");
    }

    char buffer[BUFSIZ] = {0};
    if (!fgets(buffer, BUFSIZ, fp)){
        fprintf(stderr, "ERROR: Could not read from file.");
        fclose(fp);
        return 1;
    }
    char decode_string[255] = {0};
    char encode_string[255] = {0};
    if (string_decode((const char*) buffer, decode_string)) return 1;
    string_encode((const char*) decode_string, encode_string);
    fprintf(stdout, "Decoded line: %s\n", decode_string);
    fprintf(stdout, "Encoded line: %s\n", encode_string);
    return 0;
}

int parser_caller(char * file_name){
    if (!(yyin = fopen(file_name, "r"))) {
        fprintf(stderr, "Could not open %s\n", file_name);
        return 1;
    };
    if (yyparse()) {
        return 1;
    } 
    else {
        fprintf(stdout, "Program parsed successfully.\n");
    }
    fclose(yyin);
    return 0;
}

int resolver_caller(){
    the_stack = scope_stack_creator();
    func_local_count = -1;
    global_count = -1;
    resolve_error = 0;
    decl_resolve(parser_result);
    if (!resolve_error){
        fprintf(stdout, "Program resolved successfully.\n");
        return 0;
    }
    else{
        fprintf(stdout, "Program failed to resolve.\n");
        return 1;
    }
}

int typecheck_caller(){
    typecheck_error = 0;
    decl_typecheck(parser_result);
    if (!typecheck_error){
        fprintf(stdout, "Program type checked successfully.\n");
        return 0;
    }
    else{
        fprintf(stdout, "Program failed to typecheck.\n");
        return 1;
    }
}

int main(int argc, char* argv[]){
    if (!strcmp(argv[1], "--encode")){
        if (encoder_caller(argv[2])){
            return 1;
        }
    }
    else if (!strcmp(argv[1], "--scan")){
        if (scanner_caller(argv[2])){
            return 1;
        }
    }
    else if (!strcmp(argv[1], "--parse")) {
        if (parser_caller(argv[2])){
            return 1;
        }
    }
    else if (!strcmp(argv[1], "--print")) {
        if (parser_caller(argv[2])){
            return 1;
        }
        decl_print(parser_result, 0);
    }
    else if (!strcmp(argv[1], "--resolve")) {
        if (parser_caller(argv[2])){
            return 1;
        }

        return resolver_caller();
    }
    else if (!strcmp(argv[1], "--typecheck")) {
        if (parser_caller(argv[2])){
            return 1;
        }
        int return_val = 0;
        if (resolver_caller()){
            return_val = 1;
        }
        if (typecheck_caller()){
            return_val = 1;
        }
        return return_val;
    }
    else if (!strcmp(argv[1], "--codegen")) {
        if (parser_caller(argv[2])){
            return 1;
        }
        int return_val = 0;
        if (resolver_caller()){
            return_val = 1;
        }
        if (typecheck_caller()){
            return_val = 1;
        }
        if (return_val) return 1;
        file = fopen(argv[3], "w");
        fprintf(file, ".file \"%s\"\n", argv[3]);
        decl_codegen(parser_result);
        fclose(file);
    }
    else{
        return 1;
    }
    return 0;
}

