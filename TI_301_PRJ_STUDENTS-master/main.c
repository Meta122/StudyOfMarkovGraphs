#include "Mermaid Graph/graph.h"
#include "Mermaid Graph/mermaid.h"
#include "hasse.h"
#include "characteristics.h"
#include "Tarjan Algorithm/tarjan_algo.h"
#include "matrix.h"

int main() {
    t_adjacency_list graph;
    float **T, **T_copy, **T_mult ;
    float diff;
    int n;
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/part2_graph.txt");

    if (checkGraph(graph)) {
        printf("\n--- Adjacency List ---\n");
        print_adjacency_list(graph);
        n = graph.size;
        T = convert_matrix(graph);
        printf("\n--- Transition Matrix T ---\n");
        display_matrix(T, n);
        T_copy = copy_matrix(T, n);
        printf("\n--- Copied Matrix T_copy ---\n");
        display_matrix(T_copy, n);
        diff = difference_matrix(T, T_copy, n);
        printf("\nDifference |T - T_copy| = %1.2f\n", diff);
        T_mult = multiply_matrix(T, T, n);
        printf("\n--- Multiplied Matrix T * T ---\n");
        display_matrix(T_mult, n);
        free_matrix(T_mult, n) ;
        free_matrix(T_copy, n);
        free_matrix(T, n) ;
    }

    printf("\n-------------------------------------------------\n\n");
    printf("Exemple 1:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple1.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n");

    printf("Exemple 1 Chat GPT fixed:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple1_chatGPT_fixed.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n");

    printf("Exemple 1 from Chat GPT:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple1_from_chatGPT.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n");

    printf("Exemple 2:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple2.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n");

    printf("Exemple 3:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple3.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n");

    printf("Exemple 4_2check:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple4_2check.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n");

    printf("Exemple hasse 1:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple_hasse1.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n");

    printf("Exemple scc 1:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple_scc1.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n");

    printf("Exemple valid step3:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple_valid_step3.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);

    printf("J'ai cree un arbre sur mermaid ici ");
    create_mermaid_tree(graph);

    return 0;
}