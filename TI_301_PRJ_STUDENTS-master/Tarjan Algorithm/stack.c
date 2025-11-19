#include "stack.h"

t_tarjan_vertex * pop(t_stacklist * stack) {
    if (stack->head == NULL) {
        return NULL ;
    }
    t_stackcell * old = stack->head ;
    t_tarjan_vertex * v = old->vertex ;
    stack->head = old->next ;
    free(old) ;
    return v ;
}

t_tarjan_vertex * top(t_stacklist stack) {
    if (stack.head == NULL) {
        return NULL ;
    }
    return stack.head->vertex ;
}

void push(t_stacklist * stack, t_tarjan_vertex * vertex) {
    t_stackcell * new_cell = (t_stackcell *)malloc(sizeof(t_stackcell));
    new_cell->vertex = vertex ;
    new_cell->next = stack->head ;
    stack->head = new_cell ;
}

t_stacklist createEmptyStack() {
    t_stacklist stack ;
    stack.head = NULL ;
    return stack ;
}