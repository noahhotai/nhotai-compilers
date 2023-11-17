#ifndef TYPE_H
#define TYPE_H

#include "param_list.h"
#include "expr.h"
#include <stdbool.h>

typedef enum {
	TYPE_VOID,
	TYPE_BOOLEAN,
	TYPE_CHAR,
	TYPE_FLOAT,
	TYPE_INTEGER,
	TYPE_STRING,
	TYPE_ARRAY,
	TYPE_FUNCTION,
} type_t;

struct type{
	type_t kind;
	struct param_list* params;
	struct type *subtype;
	struct expr* array_size;
} ;

struct type * type_create( type_t kind, struct type *subtype, struct param_list* params, struct expr* array_size );
bool func_arguments_type_check(struct expr* func_call_expr, struct param_list* func_param_list, char* func_name);
void          type_print(struct type *t );
int type_check(struct type* type_1, struct type* type_2);
bool expr_list_check( struct expr* expr_list, struct type* type_benchmark);
struct type* array_access_func(struct type * left_type, struct expr* right_expr);
void type_delete( struct type *t );
struct type * type_copy( struct type *t );
void type_print_error(struct type *t );
bool array_content_check(struct type * left_type, struct expr * array_expr);
#endif
