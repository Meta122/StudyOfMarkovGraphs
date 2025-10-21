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
        add_cell(&graph.vertices[start], end, proba) ;
    }
    fclose(file);
    return graph ;
}
