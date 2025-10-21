#include "graph.h"
#include "mermaid.h"


int main() {
    print_adjacency_list(readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple1.txt"));
    create_mermaid_tree(readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple2.txt"));
    return 0;
}
