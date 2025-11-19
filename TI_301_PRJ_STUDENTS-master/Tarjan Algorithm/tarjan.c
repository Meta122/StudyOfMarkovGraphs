//
// Created by astri on 12/11/2025.
//

#include "tarjan.h"
#include <stdio.h>

t_tarjan_vertex* create_tarjan_vertex(int identifier){
    t_tarjan_vertex* cell = (t_tarjan_vertex*)malloc(sizeof(t_tarjan_vertex));
    cell->identifier = identifier;
    cell->number = -1;
    cell->accessible_number = -1;
    cell->is_in_stack = 0;
    return cell;
 }

t_class create_empty_class(){
    t_class class;
    class.head = NULL;
    return class;
  }

t_partition create_empty_partition(){
    t_partition partition;
    partition.head = NULL;
    partition.tail = NULL;
    return partition;
  }

t_tarjan_vertex** createVertexList (t_adjacency_list list){
    t_tarjan_vertex** array = malloc(sizeof(t_tarjan_vertex*) * list.size);
    for (int i=0; i<list.size; i++) {
        array[i] = create_tarjan_vertex(list.vertices[i].head->vertex); ;
    }
    return array ;
}

void add_vertex(t_tarjan_vertex * v, t_class * C) {
    t_tarjan_cell * cell = (t_tarjan_vertex*)malloc(sizeof(t_tarjan_vertex));
    cell->vertex = v ;
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
    cell->class = C ;
    if (partition->head == NULL) {
        partition->head = cell ;
        partition->tail = cell ;
    } else {
        partition->tail->next = cell ;
        partition->tail = cell ;
    }
}

void display_class(t_class C) {
    printf("Component CX : {") ;
    t_class_cell * current = C.head ;
    // à finir
}