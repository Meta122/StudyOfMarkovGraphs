#include "tarjan.h"

t_tarjan_vertex* create_tarjan_vertex(int identifier){
    t_tarjan_vertex* cell = (t_tarjan_vertex*)malloc(sizeof(t_tarjan_vertex));
    cell->identifier = identifier;
    cell->number = -1;
    cell->accessible_number = -1;
    cell->is_in_stack = 0;
    return cell;
}

t_class create_empty_class() {
    t_class class;
    class.head = NULL;
    class.tail = NULL;
    class.name = NULL;
    return class;
}

t_partition create_empty_partition() {
    t_partition partition;
    partition.head = NULL;
    partition.tail = NULL;
    return partition;
}

t_tarjan_vertex** createVertexList (t_adjacency_list list){
    t_tarjan_vertex** array = malloc(sizeof(t_tarjan_vertex*) * list.size);
    for (int i=0; i<list.size; i++) {
        array[i] = create_tarjan_vertex(i + 1);
    }
    return array ;
}

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

void display_partition(t_partition partition) {
    t_class_cell *current_class_cell = partition.head;
    int i = 1;
    printf("\n|----------------------------------|\n");
    while (current_class_cell != NULL) {
        printf("     Component %s: ", current_class_cell->class->name);
        display_class(*current_class_cell->class);
        current_class_cell = current_class_cell->next;
        i++;
    }
    printf("|----------------------------------|\n\n");
}