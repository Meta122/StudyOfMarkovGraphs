//
// Created by astri on 21/10/2025.
//

#include "list.h"

t_cell* create_cell(int vertex, float probability){
  t_cell* cell = (t_cell*)malloc(sizeof(t_cell));
  cell->vertex = vertex;
  cell->probability = probability;
  return cell;
}

t_list create_empty_list(){
  t_list list;
  list.head = NULL;
  return list;
}

t_adjacency_list create_empty_adjacency_list(int size){
    t_adjacency_list adjacency_list;
    adjacency_list.size = size;
    adjacency_list.vertices = (t_list*)malloc(sizeof(t_list*) * size);
    for(int i = 0; i < size; i++){
      adjacency_list.vertices[i] = create_empty_list();
    }
    return adjacency_list;
}