#include "graph.h"

/**
 * @brief Reads a graph definition from a text file and builds the adjacency list.
 *
 * The file format must be:
 * - Line 1: Number of vertices (N).
 * - [cite_start]Subsequent lines: "start_vertex end_vertex probability" [cite: 346-348].
 *
 * @param filename The path to the text file containing the graph data.
 * @return t_adjacency_list The constructed graph structure.
 */
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

/**
 * @brief Verifies if the loaded graph respects Markov graph constraints.
 *
 * A valid Markov graph requires that the sum of 'outgoing' probabilities
 * for every vertex equals 1. Due to floating-point arithmetic, this function
 * [cite_start]checks if the sum is between 0.99 and 1.01 [cite: 433-434].
 *
 * @param graph The adjacency list of the graph to validate.
 * @return int 1 if the graph is a valid Markov graph, 0 otherwise.
 */
int checkGraph(t_adjacency_list graph) {
    for (int i = 0; i < graph.size; i++) {
        float sum = 0 ;
        t_cell * curr = graph.vertices[i].head ;
        while (curr != NULL) {
            sum += curr->probability ;
            curr = curr->next ;
        }
        if (sum < 0.99 || sum > 1.01) {
            printf("The graph is not a Markov graph : ") ;
            printf("the sum of probabilities of vertex %d is %f.\n", i+1, sum) ;
            return 0 ;
        }
    }
    printf("The graph is a Markov graph.\n") ;
    return 1 ;
}