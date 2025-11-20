#include "Mermaid Graph/graph.h"
#include "Mermaid Graph/mermaid.h"
#include "hasse.h"
#include "Tarjan Algorithm/tarjan_algo.h"

int main() {
    t_adjacency_list graph;
    t_partition partition;

    printf("Example from part 2 :\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/part2_graph.txt");
    if (checkGraph(graph)) {
        print_adjacency_list(graph);
        partition = tarjan(graph);
        display_partition(partition);
        t_link_array * p_link_array = createLinkArray(partition);
        addLinks(p_link_array, graph);
        create_mermaid_hasse(p_link_array, partition);

    }

    printf("Exemple 1:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple1.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n\n");

    printf("Exemple 1 Chat GPT fixed:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple1_chatGPT_fixed.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n\n");

    printf("Exemple 1 from Chat GPT:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple1_from_chatGPT.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n\n");

    printf("Exemple 2:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple2.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n\n");

    printf("Exemple 3:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple3.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n\n");

    printf("Exemple 4_2check:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple4_2check.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n\n");

    printf("Exemple hasse 1:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple_hasse1.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n\n");

    printf("Exemple scc 1:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple_scc1.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);
    printf("\n\n");

    printf("Exemple valid step3:\n");
    graph = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple_valid_step3.txt");
    if (checkGraph(graph)) print_adjacency_list(graph);

    printf("I created a tree on mermaid here ");
    create_mermaid_tree(graph);

    return 0;
}