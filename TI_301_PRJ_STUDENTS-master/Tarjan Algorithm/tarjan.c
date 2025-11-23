#include "tarjan.h"

/**
 * @brief Allocates and initializes a new Tarjan vertex structure.
 *
 * Initializes the vertex with specific values required for the algorithm:
 * - number and accessible_number are set to -1 (undefined).
 * - is_in_stack is set to 0 (false).
 *
 * @param identifier The unique ID of the vertex (from the graph).
 * @return t_tarjan_vertex* A pointer to the newly created vertex structure.
 */
t_tarjan_vertex* create_tarjan_vertex(int identifier){
    t_tarjan_vertex* cell = (t_tarjan_vertex*)malloc(sizeof(t_tarjan_vertex));
    cell->identifier = identifier;
    cell->number = -1;
    cell->accessible_number = -1;
    cell->is_in_stack = 0;
    return cell;
}

/**
 * @brief Initializes an empty class (Strongly Connected Component).
 *
 * @return t_class An empty class structure with pointers initialized to NULL.
 */
t_class create_empty_class() {
    t_class class;
    class.head = NULL;
    class.tail = NULL;
    class.name = NULL;
    return class;
}

/**
 * @brief Initializes an empty partition.
 *
 * A partition is a collection of classes (SCCs).
 *
 * @return t_partition An empty partition structure.
 */
t_partition create_empty_partition() {
    t_partition partition;
    partition.head = NULL;
    partition.tail = NULL;
    return partition;
}

/**
 * @brief Creates an array of Tarjan vertices from the graph's adjacency list.
 *
 * This function initializes the necessary data structure to track the state
 * [cite_start]of every vertex during the execution of Tarjan's algorithm [cite: 309-310].
 *
 * @param list The adjacency list of the graph.
 * @return t_tarjan_vertex** An array of pointers to initialized Tarjan vertices.
 */
t_tarjan_vertex** createVertexList (t_adjacency_list list){
    t_tarjan_vertex** array = malloc(sizeof(t_tarjan_vertex*) * list.size);
    for (int i=0; i<list.size; i++) {
        array[i] = create_tarjan_vertex(i + 1);
    }
    return array ;
}

/**
 * @brief Adds a vertex to a specific class (SCC).
 *
 * Appends the vertex to the end of the class's linked list.
 *
 * @param v The vertex to add.
 * @param C The target class.
 */
void add_vertex(t_tarjan_vertex * v, t_class * C) {
    t_tarjan_cell * cell = (t_tarjan_cell*)malloc(sizeof(t_tarjan_cell));
    if (cell == NULL) return;

    cell->vertex = v ;
    cell->next = NULL;

    if (C->head == NULL) {
        C->head = cell ;
        C->tail = cell ;
    } else {
        C->tail->next = cell ;
        C->tail = cell ;
    }
}

/**
 * @brief Adds a class (SCC) to the partition.
 *
 * Appends the class to the end of the partition's linked list.
 *
 * @param C The class to add.
 * @param partition The partition structure.
 */
void add_class(t_class * C, t_partition * partition) {
    t_class_cell * cell = (t_class_cell *)malloc(sizeof(t_class_cell));
    if (cell == NULL) return;

    cell->class = C ;
    cell->next = NULL;

    if (partition->head == NULL) {
        partition->head = cell ;
        partition->tail = cell ;
    } else {
        partition->tail->next = cell ;
        partition->tail = cell ;
    }
}

/**
 * @brief Displays the contents of a single class.
 *
 * Prints vertices in the format: { v1, v2, v3 }.
 *
 * @param C The class to display.
 */
void display_class(t_class C) {
    printf("{ ");
    t_tarjan_cell *current = C.head;
    while (current != NULL) {
        printf("%d", current->vertex->identifier);
        if (current->next != NULL)
            printf(", ");
        current = current->next;
    }
    printf(" }\n");
}

/**
 * @brief Displays the entire partition (all Strongly Connected Components).
 *
 * Iterates through all classes in the partition and prints them.
 *
 * @param partition The partition to display.
 */
void display_partition(t_partition partition) {
    t_class_cell *current_class_cell = partition.head;
    int i = 1;
    while (current_class_cell != NULL) {
        printf("Component %s: ", current_class_cell->class->name);
        display_class(*current_class_cell->class);
        current_class_cell = current_class_cell->next;
        i++;
    }
}