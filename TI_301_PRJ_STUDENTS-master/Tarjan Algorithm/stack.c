#include "stack.h"

/**
 * @brief Removes and returns the element at the top of the stack.
 *
 * This function pops the head of the stack, updates the stack pointer,
 * and frees the memory of the popped cell.
 *
 * @param stack A pointer to the stack structure.
 * @return t_tarjan_vertex* The vertex that was at the top of the stack, or NULL if the stack is empty.
 */
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

/**
 * @brief Retrieves the element at the top of the stack without removing it.
 *
 * @param stack The stack structure (passed by value).
 * @return t_tarjan_vertex* The vertex at the top of the stack, or NULL if the stack is empty.
 */
t_tarjan_vertex * top(t_stacklist stack) {
    if (stack.head == NULL) {
        return NULL ;
    }
    return stack.head->vertex ;
}

/**
 * @brief Pushes a new vertex onto the top of the stack.
 *
 * @param stack A pointer to the stack structure.
 * @param vertex The vertex to be added to the stack.
 */
void push(t_stacklist * stack, t_tarjan_vertex * vertex) {
    t_stackcell * new_cell = (t_stackcell *)malloc(sizeof(t_stackcell));
    new_cell->vertex = vertex ;
    new_cell->next = stack->head ;
    stack->head = new_cell ;
}

/**
 * @brief Initializes a new empty stack.
 *
 * @return t_stacklist An empty stack structure with the head set to NULL.
 */
t_stacklist createEmptyStack() {
    t_stacklist stack ;
    stack.head = NULL ;
    return stack ;
}