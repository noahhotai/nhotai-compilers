#ifndef SCOPE_H
#define SCOPE_H
#include "symbol.h"
#include "decl.h"
#include "hash_table.h"




struct scope_stack * the_stack;

struct scope_stack{
	int length;
	struct scope_stack_node* top;
};

struct scope_stack_node{
	struct scope_stack_node* prev;
	struct hash_table* ht;
	int count;
};


struct scope_stack_node * scope_stack_node_creator();

struct scope_stack * scope_stack_creator();

void scope_enter();

void scope_exit();

int scope_level();


void scope_bind( const char *name, struct symbol *sym );
struct symbol *scope_lookup_current(const char *name );

struct symbol *scope_lookup( const char *name );

#endif