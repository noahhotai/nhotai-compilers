
#include "scope.h"


struct scope_stack_node * scope_stack_node_creator(){

	struct scope_stack_node * ssn = calloc(1, sizeof(struct scope_stack_node));
    ssn->ht = hash_table_create(0, 0);
    ssn->count = -1;
	
	return ssn;
};


struct scope_stack * scope_stack_creator(){

	struct scope_stack * ss = calloc(1, sizeof(struct scope_stack));
    ss->top = scope_stack_node_creator();
    ss->length = 1;

	return ss;
};





void scope_enter(){
    // printf("scope_enter\n");
    the_stack->length++;
    struct scope_stack_node* new_top = scope_stack_node_creator();
    
    new_top->prev = the_stack->top;
    
    the_stack->top = new_top;
    

}
void scope_exit(){
    // scope exit() causes the topmost hash table to be removed
    // printf("scope_exit\n");
    struct scope_stack_node* old_top = the_stack->top;
    the_stack->top = old_top->prev;

    hash_table_delete(old_top->ht);
    free(old_top);

}

int scope_level(){

    return the_stack->length;

}

void scope_bind( char *name, struct symbol *sym ){
    extern int resolve_error;
    // printf("scope_bind: %s\n", name);
    // print("scope_bind: %s");
    if (sym->type->kind != TYPE_FUNCTION){
        // printf("scope_bind\n");
        if (hash_table_lookup(the_stack->top->ht, name)){
            printf("error: redeclaration");
            resolve_error = 1;
        }
        else {
            hash_table_insert(the_stack->top->ht, name, sym);
        }
    }
    else {
        hash_table_insert(the_stack->top->ht, name, sym);
    }
}



// struct stack_node* scope_lookup_current( const char *name ){


// }
struct symbol *scope_lookup_current( char *name ){
    
    return hash_table_lookup(the_stack->top->ht, name);

}


struct symbol *scope_lookup( char *name ){

    struct scope_stack_node* curr = the_stack->top;
    struct symbol* return_symbol = 0;

    while(curr){

        return_symbol = hash_table_lookup(curr->ht, name);
        if (return_symbol){
            break;
        }
        else{
            curr = curr->prev;
        }
    }

    return return_symbol;

}