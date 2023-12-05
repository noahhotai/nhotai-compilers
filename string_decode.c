
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int char_decode(char* c){
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