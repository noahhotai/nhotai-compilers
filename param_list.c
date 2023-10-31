#include "param_list.h"

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){
    struct param_list * d = malloc(sizeof(struct param_list));
    d->name = name;
    d->type = type;
    d->next = next;
    return d;
}
void param_list_print( struct param_list *a ){

}