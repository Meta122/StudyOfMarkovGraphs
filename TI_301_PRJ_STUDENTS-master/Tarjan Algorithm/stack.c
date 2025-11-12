#include "stack.h"

int pop(t_stacklist * stack) {
    t_stackcell * head = stack->head ;
    stack->head = stack->head->next ;
    return head->number ;
}

int top(t_stacklist stack) {
    return (stack.head->number) ;
}

int isInStack(int n, t_stacklist stack) {
    t_stackcell * current = stack.head ;
    while (current != stack.head) {
      if (current->number == n) {
        return 1 ;
      }
      current = current->next ;
    }
    return 0 ;
}