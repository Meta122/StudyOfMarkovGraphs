//
// Created by astri on 21/10/2025.
//
#include "stdlib.h"

#ifndef LIST_H
#define LIST_H

struct s_cell {
    int vertex;
    float probability;
    struct s_cell *next;
} typedef t_cell;

struct s_list{
  t_cell *head;
} typedef t_list;

struct adjacency_list{
  int size;
  t_list* vertices;
} typedef t_adjacency_list;

t_cell* create_cell(int vertex, float probability);
t_list create_empty_list();

t_adjacency_list create_empty_adjacency_list(int size);
void add_cell(t_list *list, int vertex, float probability);
void display_list (t_list list);

#endif //LIST_H
