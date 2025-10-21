//
// Created by rafyv on 21/10/2025.
//

#include "graph.h"
#include <stdio.h>

t_adjacency_list readGraph(const char *filename) {
    FILE *file = fopen(filename, "rt"); // read-only, text
    int nbvert, start, end;
    float proba;
    t_adjacency_list graph ;
    if (file == NULL) {
        perror("Could not open file for reading");
        exit(EXIT_FAILURE);
    }
    // first line contains number of vertices
    if (fscanf(file, "%d", &nbvert) != 1) {
        perror("Could not read number of vertices");
        exit(EXIT_FAILURE);
    }
    graph = create_empty_adjacency_list(nbvert);
    while (fscanf(file, "%d %d %f", &start, &end, &proba) == 3) {
        // we obtain, for each line of the file, the values
        // start, end and proba
        add_cell(&graph.vertices[start-1], end, proba) ;
    }
    fclose(file);
    return graph ;
}

int checkGraph(t_adjacency_list graph) {
    for (int i = 0; i < graph.size; i++) {
        float sum = 0 ;
        t_cell * curr = graph.vertices[i].head ;
        while (curr != NULL) {
            sum += curr->probability ;
            curr = curr->next ;
        }
        if (sum < 0.99 || sum > 1) {
            printf("The graph is not a Markov graph : ") ;
            printf("the sum of probabilities of vertex %d : %f.\n", i+1, sum) ;
        }
    }
    printf("The graph is a Markov graph.\n") ;
    return 1 ;
}