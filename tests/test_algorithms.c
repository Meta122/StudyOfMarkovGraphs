#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "matrix.h"
#include "Tarjan Algorithm/tarjan_algo.h"

static void free_graph(t_adjacency_list graph) {
    for (int i = 0; i < graph.size; ++i) {
        t_cell *edge = graph.vertices[i].head;
        while (edge != NULL) {
            t_cell *next = edge->next;
            free(edge);
            edge = next;
        }
    }
    free(graph.vertices);
}

static void free_partition(t_partition partition) {
    t_class_cell *component = partition.head;
    while (component != NULL) {
        t_class_cell *next_component = component->next;
        t_tarjan_cell *member = component->class->head;
        while (member != NULL) {
            t_tarjan_cell *next_member = member->next;
            free(member->vertex);
            free(member);
            member = next_member;
        }
        free(component->class->name);
        free(component->class);
        free(component);
        component = next_component;
    }
}

static void test_strongly_connected_components(void) {
    t_adjacency_list graph = create_empty_adjacency_list(5);
    add_cell(&graph.vertices[0], 2, 1.0f);
    add_cell(&graph.vertices[1], 1, 0.5f);
    add_cell(&graph.vertices[1], 3, 0.5f);
    add_cell(&graph.vertices[2], 4, 1.0f);
    add_cell(&graph.vertices[3], 3, 1.0f);

    t_partition partition = tarjan(graph);
    unsigned found = 0;
    int count = 0;
    for (t_class_cell *component = partition.head; component != NULL; component = component->next) {
        unsigned members = 0;
        for (t_tarjan_cell *member = component->class->head; member != NULL; member = member->next) {
            members |= 1u << (member->vertex->identifier - 1);
        }
        if (members == 0x03u) found |= 1u;
        else if (members == 0x0cu) found |= 2u;
        else if (members == 0x10u) found |= 4u;
        else assert(!"Unexpected strongly connected component");
        ++count;
    }
    assert(count == 3 && found == 7u);

    free_partition(partition);
    free_graph(graph);
}

static void test_transition_matrix_powers(void) {
    t_adjacency_list graph = create_empty_adjacency_list(2);
    add_cell(&graph.vertices[0], 1, 0.5f);
    add_cell(&graph.vertices[0], 2, 0.5f);
    add_cell(&graph.vertices[1], 1, 0.25f);
    add_cell(&graph.vertices[1], 2, 0.75f);

    float **matrix = convert_matrix(graph);
    float **zero = power_matrix(matrix, 2, 0);
    float **two = power_matrix(matrix, 2, 2);
    assert(fabsf(zero[0][0] - 1.0f) < 1e-6f);
    assert(fabsf(zero[0][1]) < 1e-6f);
    assert(fabsf(zero[1][0]) < 1e-6f);
    assert(fabsf(zero[1][1] - 1.0f) < 1e-6f);
    assert(fabsf(two[0][0] - 0.375f) < 1e-6f);
    assert(fabsf(two[0][1] - 0.625f) < 1e-6f);
    assert(fabsf(two[1][0] - 0.3125f) < 1e-6f);
    assert(fabsf(two[1][1] - 0.6875f) < 1e-6f);

    free_matrix(two, 2);
    free_matrix(zero, 2);
    free_matrix(matrix, 2);
    free_graph(graph);
}

int main(void) {
    test_strongly_connected_components();
    test_transition_matrix_powers();
    puts("Algorithm checks passed.");
    return 0;
}
