#include "tarjan_algo.h"

/**
 * @brief Utility function to find the minimum of two integers.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return int The smaller value between a and b.
 */
int min(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * @brief The recursive core of Tarjan's algorithm (Depth First Search).
 *
 * This function visits vertices, assigns them a discovery number and a low-link value
 * (accessible_number), pushes them onto a stack, and identifies the roots of
 * [cite_start]strongly connected components [cite: 297-299].
 *
 * @param G The graph being analyzed.
 * @param v The current vertex being visited.
 * @param stack The stack used to track vertices in the current traversal path.
 * @param num Pointer to the global counter used for numbering vertices.
 * @param partition The partition structure where identified components (classes) are stored.
 * @param vertex_list An array of all Tarjan vertices for direct access by index.
 */
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

/**
 * @brief Main function to execute Tarjan's algorithm on a graph.
 *
 * It initializes the necessary data structures (vertex list, stack, partition)
 * and iterates through all vertices to ensure even disconnected components are processed.
 * It produces a partition of the graph into Strongly Connected Components (SCCs).
 *
 * @param G The adjacency list representation of the graph.
 * @return t_partition The resulting partition containing the list of SCCs found.
 */
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
    t_class_cell * current = partition.head;
    int i = 1;
    while (current != NULL) {
        current->class->name = malloc(16 * sizeof(char)); // Alloue suffisamment d'espace
        sprintf(current->class->name, "C%d", i);
        current = current->next;
        i++;
    }
    free(vertex_list) ;
    return partition ;
}