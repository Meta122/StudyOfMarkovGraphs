//
// Created by astri on 21/10/2025.
//

#include "cell.h"

t_cell* create_cell(int vertex, float probability){
  t_cell* cell = (t_cell*)malloc(sizeof(t_cell));
  cell->vertex = vertex;
  cell->probability = probability;
  return cell;
}
t_list* create_empty_list(){
  t_list* list = (t_list*)malloc(sizeof(t_list));
  list->head = NULL;
  return list;
}