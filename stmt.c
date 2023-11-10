#include "stmt.h"
#include <stdlib.h>


struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next ){

	struct stmt *d = calloc(1, sizeof(struct stmt));
	d->kind = kind;
	d->decl = decl;
	d->init_expr = init_expr;
	d->expr = expr;
	d->next_expr = next_expr;
	d->body = body;
	d->else_body = else_body;
	d->next = next;
	return d;
}

void stmt_print(struct stmt *s, int indents ){
	extern void indent(int indents);
	if (!s) return;	

	if (s->kind != STMT_BLOCK) {
		indent(indents);
	}

	switch (s->kind) {
		case STMT_NULL:
			printf("null");
			break;
		case STMT_DECL:
			decl_print(s->decl, 0);
			// printf("out");
			// printf("post");
            break;
        case STMT_EXPR:
			expr_print(s->expr);
			printf(";\n");
            break;
        case STMT_IF_ELSE:
            printf("if (");
			expr_print(s->expr);
			printf(")");
			if (s->body->kind != STMT_BLOCK){
				printf("\n");
				stmt_print(s->body, indents+ 1);
			}
			else{
				stmt_print(s->body, indents);
			}
			if (s->else_body){
				indent(indents);
				printf("else");
				if (s->body->kind != STMT_BLOCK){
					printf("\n");
					stmt_print(s->body, indents + 1);
				}
				else{
					stmt_print(s->body, indents);
				}
			}
            break;
        case STMT_FOR:
			printf("for(");
			expr_print(s->init_expr);
			printf(";");
			expr_print(s->expr);
			printf(";");
			expr_print(s->next_expr);
            printf(")");
			if (s->body->kind != STMT_BLOCK){
				printf("\n");
				stmt_print(s->body, indents+ 1);
			}
			else{
				stmt_print(s->body, indents);
			}
            break;
        case STMT_PRINT:
			printf("print ");
			expr_print(s->expr);
			printf(";\n");
            break;
        case STMT_RETURN:
			printf("return");
			if (s->expr) {
				printf(" ");
				expr_print(s->expr);
			}
			
			printf(";");
			printf("\n");
            break;
        case STMT_BLOCK:
            printf("{\n");
			stmt_print(s->body, indents + 1);
			indent(indents);
			printf("}\n");
            break;

        default:
            break;
    }

	
	// printf("s->next");
	if (s->next){
        stmt_print(s->next, indents);
    }
	
}

void stmt_resolve(struct stmt * s){

	if (!s) return;
	switch (s->kind) {
		case STMT_DECL:
			
			decl_resolve(s->decl);
            break;
        case STMT_EXPR:
			
			expr_resolve(s->expr);
            break;
        case STMT_IF_ELSE:
			expr_resolve(s->expr);
			stmt_resolve(s->body);
			stmt_resolve(s->else_body);
            break;
        case STMT_FOR:
			expr_resolve(s->init_expr);
			expr_resolve(s->expr);
			expr_resolve(s->next_expr);
			stmt_resolve(s->body);
            break;
        case STMT_PRINT:
			
			expr_resolve(s->expr);
            break;
        case STMT_RETURN:
			
			if (s->expr) {
				expr_resolve(s->expr);
			}
            break;
        case STMT_BLOCK:
			
			scope_enter();
			stmt_resolve(s->body);
			scope_exit();
            break;
        default:
            break;
    }

	if (s->next){


		stmt_resolve(s->next);
    }
}
