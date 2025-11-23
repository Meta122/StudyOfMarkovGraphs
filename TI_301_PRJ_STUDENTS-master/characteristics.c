#include "characteristics.h"

// It will return 1 meaning it is transitory or 0 meaning it is persistent
int is_transitory(t_class* c, t_link_array links) {
    for (int i = 0; i < links.log_size; i++) {
        if (links.links[i].from == c) {
            return 1;
        }
    }
    return 0;
}

int is_irreducible(t_partition partition) {
    int class_count = 0;
    t_class_cell* curr = partition.head;

    while (curr != NULL) {
        class_count++;
        curr = curr->next;
    }
    return (class_count == 1);
}

int is_absorbing(t_class* c, t_link_array links){
    if (is_transitory(c, links)) {
        return 0;
    }
    int count = 0;
    t_tarjan_cell* curr = c->head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    if (count == 1) {
        return 1;
    }
    return 0;
}

void print_graph_characteristics(t_partition partition, t_link_array links) {
    printf("---Graph Characteristics---\n");

    // We Check the irreducibility of the graph
    if (is_irreducible(partition)) {
        printf("The graph is irreducible.\n");
    } else {
        printf("The graph is reducible.\n");
    }
    printf("\n");

    t_class_cell* curr = partition.head;
    while (curr != NULL) {
        t_class* c = curr->class;

        printf("Class %s: ", c->name);

        if (is_transitory(c, links)) {
            printf("Transitory");
        } else {
            printf("Persistent");

            if (is_absorbing(c, links)) {
                printf(" (State %d is Absorbing)", c->head->vertex->identifier);
            }
        }
        printf("\n");
        curr = curr->next;
    }
}