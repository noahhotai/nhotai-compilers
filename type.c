
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
    // if (!t) return;
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

void type_print_error(struct type *t ){
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
            // printf(" (");
            // param_list_print(t->params);
            // printf(")");
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
            return type_check(type_1->subtype, type_2->subtype) && param_check(type_1->params, type_2->params);
        }
        else{
            return 0;
        }
    }
}

bool atomic_type(struct type* t){
    if (t->kind != TYPE_ARRAY && t->kind != TYPE_FUNCTION){
        return true;
    }
    else {
        return false;
    }
}

bool func_arguments_type_check(struct expr* arg_list_expr, struct param_list* func_param_list, char* func_name){

    if (!arg_list_expr){
        if (func_param_list){
            printf("wrong amouhnt of arguments given\n");
            return false;
        }
        else{
            return true;
        }
    }
    struct expr* curr_expr_list = arg_list_expr;
    struct expr* curr_expr = arg_list_expr->left;
    struct param_list*  curr_param = func_param_list;


    while (curr_expr && curr_param){
        if (!type_check(expr_typecheck(curr_expr), curr_param->type)){
            printf("type error: argument of type ");
            type_print(expr_typecheck(curr_expr));
            printf(" does not match parameter %s of type ", curr_param->name);
            type_print(curr_param->type);
            printf(" of function %s.\n", func_name);
            return false;
        }
        curr_expr_list = curr_expr_list->right;
        if (curr_expr_list){
            curr_expr = curr_expr_list->left;
        }
        else{
            curr_expr = 0;
        }
        curr_param = curr_param->next;
    }
    if ((curr_expr) || (curr_param)){
        printf("paramater error: wrong number of arguments given to the function %s.\n", func_name);
        return false;
    }
    else{
        return true;
    }
}


struct type* array_access_func(struct type * left_type, struct expr* right_expr){

    extern int typecheck_error;
    while(right_expr && left_type){
        left_type = left_type->subtype;
        right_expr = right_expr->right;
    }
    // printf("herrreeeee\n\n");

    // printf("after\n\n");
    if (right_expr){
        typecheck_error = 1;
        printf("type error: over referencing array with index (\n\n\n\n");
        expr_print(right_expr);
        printf(")\n");
    }
    if (!left_type){
        typecheck_error = 1;
        return type_create(TYPE_INTEGER, 0, 0, 0);
    }
    else{
        return type_copy(left_type); 
    }
   
}
    //array_type;

// bool type_equals( struct type *a, struct type *b ) {
//     if( a->kind == b->kind ) {
//         if(atomic_type(a)){
//             return true;
//         }
//         else if (a->kind == TYPE_ARRAY) {
//             if subtype is recursively equal{
//                 return true 
//             }
//             else{
//                 return false;
//             }
//         } 
//         else if (a->kind == TYPE_FUNCTION) {
//             if (param_check(a->params, b->params)){
//                 return true;//both subtype and params
//             }    // are recursively equal
//             else{
//                 return false;
//             }
//         }
//     } 
//     else {
//         return false;
//     }
// }

struct type * type_copy( struct type *t )
{
    if (!t) {
        return 0;
    }
    else{
        return type_create(t->kind, type_copy(t->subtype), param_copy(t->params), t->array_size);
    }   
    
// Return a duplicate copy of t, making sure
// to duplicate subtype and params recursively.

// }
}
void type_delete( struct type *t ){   
    if (!t){
        return;
    }
    // printf("1");
    // type_print(t);
    type_delete(t->subtype);
    param_delete(t->params);
    free(t);
// Free all the elements of t recursively.
}


bool array_content_check(struct type * left_type, struct expr * array_expr){
    // extern int typecheck_error;

    // printf("here\n\n\n\n\n\n\n\n\n\n\n");
    if (!left_type || !array_expr){
        // return_val = 1;

        return 1;
        // printf("chelsea")
        // printf("here");
    }
    if (array_expr->kind == EXPR_NESTED_BRACES || array_expr->kind == EXPR_ARRAY_BRACES ){
        // return_val = 1;
        if (array_content_check(left_type->subtype, array_expr->left)){
            return 1;
        }
    }
    else if  (array_expr->kind == EXPR_LIST){
        if (expr_list_check(left_type, array_expr)){
            return 1;
        }
        // return_val 
    }
    
    if (array_expr->right){
        return array_content_check(left_type, array_expr->right);
    }
    return 0;
    // array_content_check(left_type->subtype, array_expr->left);

}


bool expr_list_check( struct type* type_benchmark, struct expr* expr_list){
    // extern int typecheck_error;
    // temp_expr = 

    while (expr_list && expr_list->left){

        if (!type_check(expr_typecheck(expr_list->left), type_benchmark)){
            // typecheck_error = 1;
            // printf("type error: wrong type given in array (");
            // type_print(expr_list->symbol->type);
            // printf("), where type (");
            // type_print(type_benchmark);
            // printf("),expected.");
            return 1;
        }
        expr_list = expr_list->right;
    }
    return 0;
 }