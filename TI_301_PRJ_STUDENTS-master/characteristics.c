#include "characteristics.h"

/**
 * @brief Checks if a class is transitory.
 *
 * According to the definition, a class is 'transitory' if it is possible
 * to 'exit' that class, meaning there is at least one 'outgoing arrow'
 * from this class to another in the Hasse diagram[cite: 483].
 *
 * @param c The class to check.
 * @param links The array of links between classes (Hasse diagram edges).
 * @return int 1 if the class is transitory, 0 if it is persistent.
 */
int is_transitory(t_class* c, t_link_array links) {
    for (int i = 0; i < links.log_size; i++) {
        if (links.links[i].from == c) {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Checks if the Markov graph is irreducible.
 *
 * A Markov graph is said to be 'irreducible' if it is composed of only
 * one class (Strongly Connected Component)[cite: 488].
 *
 * @param partition The partition of the graph into classes.
 * @return int 1 if the graph is irreducible, 0 otherwise.
 */
int is_irreducible(t_partition partition) {
    int class_count = 0;
    t_class_cell* curr = partition.head;

    while (curr != NULL) {
        class_count++;
        curr = curr->next;
    }
    return (class_count == 1);
}

/**
 * @brief Checks if a class represents an absorbing state.
 *
 * A state is 'absorbing' if it meets two conditions:
 * 1. It is in a persistent class (cannot exit the class).
 * 2. It is the only state in that class[cite: 487].
 *
 * @param c The class to check.
 * @param links The array of links (to check for persistence).
 * @return int 1 if the class represents an absorbing state, 0 otherwise.
 */
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

/**
 * @brief Displays all the characteristics of the graph.
 *
 * This function prints:
 * - Whether the graph is irreducible or reducible[cite: 499].
 * - For each class: whether it is Transitory or Persistent[cite: 497].
 * - If a class is persistent and single-element, identifies it as Absorbing[cite: 498].
 *
 * @param partition The partition of the graph.
 * @param links The links between the classes of the partition.
 */
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