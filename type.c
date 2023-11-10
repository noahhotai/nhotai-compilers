
#include <stdlib.h>
#include "type.h"


struct type * type_create( type_t kind, struct type *subtype, struct param_list* params, struct expr* array_size){
    struct type *d = malloc(sizeof(struct type));
    d->kind = kind;
    d->subtype = subtype;
    d->params = params;
    d->array_size = array_size;
    return d;
}

void type_print(struct type *t ){
    // printf("type_print");
    switch (t->kind) {
        case TYPE_VOID:
            // Code for handling TYPE_VOID
            printf("void");
            break;
        case TYPE_BOOLEAN:
            printf("boolean");
            // Code for handling TYPE_BOOLEAN
            break;
        case TYPE_CHAR:
            printf("char");
            // Code for handling TYPE_CHAR
            break;
        case TYPE_FLOAT:
            printf("float");
            // Code for handling TYPE_FLOAT
            break;
        case TYPE_INTEGER:
            printf("integer");
            // Code for handling TYPE_INTEGER
            break;
        case TYPE_STRING:
            printf("string");
            // Code for handling TYPE_STRING
            break;
        case TYPE_ARRAY:
            if (t->array_size){
                printf("array [");
                expr_print(t->array_size);
                printf("] ");
            }
            else{
                printf("array [] "); 
            } 
    
            type_print(t->subtype);
            // Code for handling TYPE_ARRAY
            break;

        case TYPE_FUNCTION:
            printf("function ");
	        type_print(t->subtype);
            printf(" (");
            param_list_print(t->params);
            printf(")");
            // Code for handling TYPE_FUNCTION
            break;
        default:
            printf("unknown");
            // Code for handling unknown enum values (if necessary)
        break;
    }
}

int type_check(struct type* type_1, struct type* type_2){

    if (!type_1 && !type_2){
        return 1;
    }
    else if (!type_1 || !type_2){
        return 0;
    }
    else{
        if (type_1->kind == type_2->kind){
            return type_check(type_1->subtype, type_2->subtype);
        }
        else{
            return 0;
        }
    }
}
