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
    return partition;
  }

t_tarjan_vertex** createVertexList (t_adjacency_list list){
    t_tarjan_vertex** array = malloc(sizeof(t_tarjan_vertex*) * list.size);
    for (int i=0; i<list.size; i++) {
        array[i] = create_tarjan_vertex(list.vertices[i].head->vertex); ;
    }
    return array ;
}