#include "stmt.h"
#include <stdlib.h>

extern FILE* file;
extern int global_func_counter_codegen;
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
				if (s->else_body->kind != STMT_BLOCK){
					printf("\n");
					// printf("STMTBLOCk\n");
					stmt_print(s->else_body, indents + 1);
				}
				else{
					// printf("penis\n");
					stmt_print(s->else_body, indents);
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

void stmt_typecheck(struct stmt *s, struct type *decl_subtype, int returned, char* func_name){
	if (!s) return;	

	extern int typecheck_error;
	struct type *t;
	switch (s->kind) {
		case STMT_DECL:
			decl_typecheck(s->decl);
			break;
        case STMT_EXPR:
			t = expr_typecheck(s->expr);
			type_delete(t);
			break;
			struct type *t;
        case STMT_IF_ELSE:
			// printf("\nif else\n");
			if (s->expr){
				t = expr_typecheck(s->expr);
				if (t->kind != TYPE_BOOLEAN){
					typecheck_error = 1;
					printf("if condition must be boolean");
				}
			}
			type_delete(t);
			stmt_typecheck(s->body, decl_subtype, returned, func_name);
			stmt_typecheck(s->else_body, decl_subtype, returned, func_name);
			break;

        case STMT_FOR:
			t = expr_typecheck(s->init_expr);
			type_delete(t);
			t = expr_typecheck(s->expr);
			type_delete(t);
			t = expr_typecheck(s->next_expr);
			type_delete(t);
			stmt_typecheck(s->body, decl_subtype, returned, func_name);
			break;
        case STMT_PRINT:
            break;
        case STMT_RETURN:
			// printf("case return\n");
			if (s->expr) {
				// printf("inside if \n");
				// struct type *expr_type = expr_typecheck(s->expr, 0, 0);
				struct type *expr_type = expr_typecheck(s->expr);
				if (!type_check(decl_subtype, expr_type)){
            		//type error: cannot return a boolean (x<5) in a function (fibonnacci) that returns integer
					typecheck_error = 1;
            		printf("type error: cannot return a ");
					type_print(expr_type);
            		expr_print(s->expr);
					printf(" in a function (%s) that returns ", func_name);
					type_print(decl_subtype);
        		}
				returned = 1;
			}
			break;
        case STMT_BLOCK:
			stmt_typecheck(s->body, decl_subtype, returned, func_name);
            break;
			
        default:
            break;
    }

	
	if (s->next){
        stmt_typecheck(s->next, decl_subtype, returned, func_name);
    }
	else{

	}
	
}



void stmt_codegen_print(struct expr * e, char * function_name){
	if (!e) return;
	if (e->kind == EXPR_LIST){
		stmt_codegen_print(e->left, function_name);
		stmt_codegen_print(e->right, function_name);
	}
	else{
		switch (expr_typecheck(e)->kind){
			case TYPE_ARRAY:
				break;
			case TYPE_INTEGER:
				expr_codegen(e, function_name);
				fprintf(file, "MOVQ %s, %%rdi\n", scratch_name(e->reg));
				fprintf(file, "CALL print_integer\n");
				scratch_free(e->reg);
				break;
			case TYPE_CHAR:
				expr_codegen(e, function_name);
				fprintf(file, "MOVQ %s, %%rdi\n", scratch_name(e->reg));
				fprintf(file, "CALL print_character\n");
				scratch_free(e->reg);
				break;
			case TYPE_STRING:
				expr_codegen(e, function_name);
				fprintf(file, "MOVQ %s, %%rdi\n", scratch_name(e->reg));
				fprintf(file, "CALL print_string\n");
				scratch_free(e->reg);
				break;
			case TYPE_FLOAT:
				fprintf(file, "cannot handle float operations\n");
				break;
			case TYPE_BOOLEAN:
				expr_codegen(e, function_name);
				fprintf(file, "MOVQ %s, %%rdi\n", scratch_name(e->reg));
				fprintf(file, "CALL print_boolean\n");
				scratch_free(e->reg);
				break;
			default:
				break;
		}
	}
}

void stmt_codegen(struct stmt *s, char* function_name){

	if (!s) return;	
	int top_label;
	int else_label;
	int done_label;
	switch (s->kind) {
		case STMT_NULL:
			break;
		case STMT_DECL:
			decl_codegen(s->decl);
            break;
        case STMT_EXPR:
			expr_codegen(s->expr, function_name);
			scratch_free(s->expr->reg);
            break;
        case STMT_IF_ELSE:
			else_label = label_create();
			done_label = label_create();
			expr_codegen(s->expr, function_name);
			fprintf(file, "CMP $0, %s\n",scratch_name(s->expr->reg));
			fprintf(file, "JE %s\n",label_name(else_label));
			stmt_codegen(s->body, function_name);
			fprintf(file, "JMP %s\n",label_name(done_label));
			fprintf(file, "%s:\n",label_name(else_label));
			stmt_codegen(s->else_body, function_name);
			fprintf(file, "%s:\n",label_name(done_label));
			scratch_free(s->expr->reg);
			break;

        case STMT_FOR:

			
			if (s->init_expr){
				expr_codegen(s->init_expr, function_name);
				scratch_free(s->init_expr->reg);
			}
			top_label = label_create();
			done_label = label_create();

			fprintf(file, "%s:\n",label_name(top_label));
			
			if (s->expr){
				expr_codegen(s->expr, function_name);
				fprintf(file, "CMP $0, %s\n",scratch_name(s->expr->reg));
				scratch_free(s->expr->reg);
			}
			
			
			fprintf(file, "JE %s\n",label_name(done_label));
			stmt_codegen(s->body, function_name);

			if (s->next_expr){
				expr_codegen(s->next_expr, function_name);
				scratch_free(s->next_expr->reg);
			}
			
			fprintf(file, "JMP %s\n",label_name(top_label));
			fprintf(file, "%s:\n",label_name(done_label));
            break;
        case STMT_PRINT:
			stmt_codegen_print(s->expr, function_name);
            break;
        case STMT_RETURN:
			if (s->expr) {
				expr_codegen(s->expr, function_name);
				fprintf(file, "MOV %s, %%rax\n",scratch_name(s->expr->reg));
				// fprintf(file, "JMP .%s_epilogue\n", function_name);
				fprintf(file, "ADDQ $%d, %%rsp\n", 8 *global_func_counter_codegen);
        		func_postamble();
				fprintf(file, "RET\n");
				scratch_free(s->expr->reg);
			}
			else{
				fprintf(file, "ADDQ $%d, %%rsp\n", 8 *global_func_counter_codegen);
        		func_postamble();
				fprintf(file, "RET\n");

			}
            break;
        case STMT_BLOCK:
			stmt_codegen(s->body, function_name);
            break;

        default:
            break;
    }
	
	stmt_codegen(s->next, function_name);
	
}