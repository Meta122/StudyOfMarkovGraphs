#include "stack.h"

t_tarjan_vertex pop(t_stacklist * stack) {
    t_stackcell * head = stack->head ;
    stack->head = stack->head->next ;
    return head->vertex ;
}

t_tarjan_vertex top(t_stacklist stack) {
    return (stack.head->vertex) ;
}

int isInStack(t_tarjan_vertex v, t_stacklist stack) {
    t_stackcell * current = stack.head ;
    while (current != stack.head) {
      if (&current->vertex == &v) {
        return 1 ;
      }
      current = current->next ;
    }
    return 0 ;
}