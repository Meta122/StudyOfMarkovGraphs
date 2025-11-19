#include "tarjan_algo.h"

int min(int a, int b) {
    return (a < b) ? a : b;
}

void strongConnect(t_adjacency_list G, t_tarjan_vertex * v, t_stacklist * stack, int * num, t_partition * partition, t_tarjan_vertex ** vertex_list) {
    v->number = *num ;
    v->accessible_number = v->number;
    (*num)++ ;
    push(stack, v) ;
    v->is_in_stack = 1 ;
    int vertex_index = v->identifier - 1 ;
    if (vertex_index < 0 || vertex_index >= G.size) {
        return;
    }
    t_list list = G.vertices[vertex_index] ;
    t_cell * curr = list.head ;

    while (curr != NULL) {
        int id = curr->vertex - 1 ;
        if (id >= 0 && id < G.size) {
            t_tarjan_vertex * w = vertex_list[id] ;
            if (w->number == -1) {
                strongConnect(G, w, stack, num, partition, vertex_list) ;
                v->accessible_number = min(v->accessible_number, w->accessible_number) ;
            } else if (w->is_in_stack) {
                v->accessible_number = min(v->accessible_number, w->number) ;
            }
        }
        curr = curr->next ;
    }

    if (v->accessible_number == v->number) {
        t_class *C = (t_class*)malloc(sizeof(t_class));
        if (C == NULL) return;
        *C = create_empty_class() ;
        t_tarjan_vertex * w_pop = NULL;
        do {
            w_pop = pop(stack) ;
            if (w_pop == NULL) {
                free(C);
                return;
            }
            w_pop->is_in_stack = 0 ;
            add_vertex(w_pop, C) ;
        } while (w_pop != v) ;
        add_class(C, partition) ;
    }
}

t_partition tarjan(t_adjacency_list G) {
    t_partition partition = create_empty_partition() ;
    t_tarjan_vertex ** vertex_list = createVertexList(G) ;
    t_stacklist stack = createEmptyStack() ;
    int num = 0 ;
    for (int i = 0 ; i < G.size ; i++) {
        t_tarjan_vertex * v = vertex_list[i] ;
        v->identifier = i + 1;

        if (v->number == -1) {
            strongConnect(G, v, &stack, &num, &partition, vertex_list) ;
        }
    }
    free(vertex_list) ;
    return partition ;
}