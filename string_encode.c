
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
