#include "stmt.h"
#include <stdlib.h>


struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next ){

	struct decl *d = malloc(sizeof(struct stmt));
	d->kind = kind;
	d->init_expr = init_expr;
	d->expr = expr;
	d->next_expr = next_expr;
	d->body = body;
	d->else_body = else_body;
	d->next = next;

    return d;

}

void stmt_print(struct stmt *s, int indent ){


}