//
// Created by astri on 12/11/2025.
//

#include "tarjan.h"
#include <stdio.h>

t_tarjan_vertex* create_tarjan_cell(int id){
    t_tarjan_vertex* cell = (t_tarjan_vertex*)malloc(sizeof(t_tarjan_vertex));
    cell->identifier = id;
    cell->number = 0;
    cell->accessible_number = 0;
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