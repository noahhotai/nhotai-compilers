#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner_func.c"
#include "string_encode.c"

int main(int argc, char* argv[]){
    if (!strcmp(argv[1], "--scan")){
        yyin = fopen(argv[2], "r");
        if (scanner()) {
            printf("ERROR: Failure scanning\n");
            return 1;
        };
    }
    else if (!strcmp(argv[1], "--encode")){
            FILE* fp = fopen(argv[2], "r");
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
    }
    else{
        return 1;
    }

    return 0;
}
