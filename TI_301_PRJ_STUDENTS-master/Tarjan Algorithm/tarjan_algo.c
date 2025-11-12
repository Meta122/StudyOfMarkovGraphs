#include "tarjan_algo.h"

int min(int a, int b) {
    return (a < b) ? a : b;
}

void strongConnect(t_adjacency_list G, t_tarjan_vertex * v, t_stacklist * stack, int * num, t_partition partition, t_tarjan_vertex ** vertex_list) {
    v->number = *num ;
    v->accessible_number = v->number;
    *num ++;
    push(stack, *v) ;
    v->is_in_stack = 1 ;
    t_list list = G.vertices[*num-1] ;
    t_cell * curr = list.head->next ;
    while (curr != NULL) {
        int id = curr->vertex ;
        t_tarjan_vertex * w = vertex_list[id] ;
        if (w->number == -1) {
            strongConnect(G, w, stack, num, partition, vertex_list) ;
            v->accessible_number = min(v->accessible_number, w->accessible_number) ;
        } else if (isInStack(w, stack)) {
            v->accessible_number = min(v->accessible_number, w->number) ;
        }
        curr = curr->next ;
    }
    if (v->accessible_number == v->number) {
        t_class C = create_empty_class() ;
        t_tarjan_vertex * w ;
        do {
            *w = pop(stack) ;
            w->is_in_stack = 0 ;
            // Ajouter w à C
        } while (w != v) ;
        // Ajouter C à partition
    }
}

t_partition tarjan(t_adjacency_list G) {
    t_partition partition = create_empty_partition() ;
    t_tarjan_vertex ** vertex_list = createVertexList(G) ;
    t_stacklist stack = createEmptyStack() ;
    int num = 0 ;

    for (int i = 0 ; i < G.size ; i++) {
        t_tarjan_vertex * v = vertex_list[i] ;
        if (v->number == -1) {
            strongConnect(G, v, &stack, &num, partition, vertex_list) ;
        }
    }

    return partition ;
}