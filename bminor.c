
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int string_decode(const char *es, char *s){
    int i = 0;
    int j = 0;
    int es_length = strlen(es);
    if (es_length > 255){
        fprintf(stderr, "ERROR: String length exceeds maximum.\n");
        return 1;
    }   
    if (es[0] != '\"'|| es[es_length -1] != '\"'){
        fprintf(stderr, "ERROR: String not surrounded by quotes.\n");
        return 1;
    }

    while (i < strlen(es)) {
        if (i == 0 || i == (strlen(es) - 1)){
            i++;
        }
        else if ((es_length - 2 == i) && es[i] == '\\'){
            fprintf(stderr, "ERROR: Invalid backslash at end of string.\n");
            return 1;
        }
        else if (es[i] == '\\' && i < (strlen(es) - 1)){
            if ((i < (strlen(es) - 5)) && es[i+1] == '0' && es[i+2] == 'x'){
                char* end_ptr = NULL;
                char hex_values[3] = {es[i+3], es[i+4], '\0'};
                s[j] = (char)strtol(hex_values, &end_ptr, 16);
                i += 5;
                j +=2;
                if (*end_ptr) {
                    fprintf(stderr, "ERROR: Invalid hexadecimal backslash code: 0x%s.\n", hex_values);
                    return 1;
                }
            } 
            else {
                switch (es[i +1]){
                    case 'a':
                        s[j] = 7;
                        break;
                    case 'b':
                        s[j] = 8;
                        break;
                    case 'e':
                        s[j] = 27;
                        break;
                    
                    case 'f':
                        s[j] = 12;
                        break;
                    
                    case 'n':
                        s[j] = 10;
                        break;
                    
                    case 'r':
                        s[j] = 13;
                        break;
                    
                    case 't':
                        s[j] = 9;
                        break;
                    
                    case 'v':
                        s[j] = 11;
                        break;
                    case '\\':
                        s[j] = 92;
                        break;
                    case '\'':
                        s[j] = 39;
                        break;
                    
                    case '\"':
                        s[j] = 34;
                        break;
                    default:
                        fprintf(stderr, "ERROR: Invalid backslash code.\n");
                        return 1;
                        break;
                } 
                i += 2;
                j += 1;
            }
        }
        
        else if (es[i] == '\"'){
            fprintf(stderr, "ERROR: Invalid quote in middle of string");
            return 1;
        }
        else {
            s[j] = es[i];
            i ++;
            j ++;
        }
    }
    return 0;
}

int string_encode(const char *es, char *s){

    
    int i = 0;
    *s = '\"';
    int j = 1;
    
    while (i < strlen(es)) {
        switch (es[i]){
            case '\a':
                s[j] = '\\';
                s[j+1] = 'a';
                i += 1;
                j += 2;
                break;
            case '\b':
                s[j] = '\\';
                s[j+1] = 'b';
                i += 1;
                j += 2;
                break;
            case '\e':
                s[j] = '\\';
                s[j+1] = 'e';
                i += 1;
                j += 2;
                break;
            case '\f':
                s[j] = '\\';
                s[j+1] = 'f';
                i += 1;
                j += 2;
                break;
            case '\n':
                s[j] = '\\';
                s[j+1] = 'n';
                i += 1;
                j += 2;
                break;
            case '\r':
                s[j] = '\\';
                s[j+1] = 'r';
                i += 1;
                j += 2;
                break;
            case '\t':
                s[j] = '\\';
                s[j+1] = 't';
                i += 1;
                j += 2;
                break;        
            case '\v':
                s[j] = '\\';
                s[j+1] = 'v';
                i += 1;
                j += 2;
                break;
            case '\\':
                s[j] = '\\';
                s[j+1] = '\\';
                i += 1;
                j += 2;
                break;
            case '\'':
                s[j] = '\\';
                s[j+1] = '\'';
                i += 1;
                j += 2;
                break;
            case '\"':
                s[j] = '\\';
                s[j+1] = '\"';
                i += 1;
                j += 2;
                break;
            default:
                s[j] = es[i];
                i ++;
                j ++;
                break;
        }
    }
    s[j] = '\"';
    return 0;



}
int main(int argc, char* argv[]){
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

    if (string_decode((const char*) buffer, decode_string)) return 1;;
    string_encode((const char*) decode_string, encode_string);
    fprintf(stdout, "Decoded line: %s\n", decode_string);
    fprintf(stdout, "Encoded line: %s\n", encode_string);


    return 0;
}
