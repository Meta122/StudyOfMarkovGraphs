//
// Created by astri on 21/10/2025.
//

#ifndef CELL_H
#define CELL_H

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
};

#endif //CELL_H
