#ifndef TYPE_H
#define TYPE_H

#include "param_list.h"
#include "expr.h"

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
void          type_print(struct type *t );
int type_check(struct type* type_1, struct type* type_2);

#endif
