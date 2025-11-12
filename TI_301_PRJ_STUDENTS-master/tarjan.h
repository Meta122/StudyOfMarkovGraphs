//
// Created by astri on 12/11/2025.
//
#include <stdlib.h>

#ifndef TARJAN_H
#define TARJAN_H

struct s_tarjan_vertex {
    int identifier;
    int number;
    int accessible_number;
    int is_in_stack;
} typedef t_tarjan_vertex;


struct s_class{
    char* name;
    t_tarjan_vertex *head;
    t_tarjan_vertex *tail;
} typedef t_class;

struct s_partition{
    t_class *head;
    t_class *tail;
} typedef t_partition;


t_tarjan_vertex* create_tarjan_cell(int identifier);
t_class create_empty_class();
t_partition create_empty_partition();


#endif //TARJAN_H
