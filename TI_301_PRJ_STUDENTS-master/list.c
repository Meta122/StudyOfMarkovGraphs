#include "list.h"

t_cell* create_cell(int vertex, float probability){
  t_cell* cell = (t_cell*)malloc(sizeof(t_cell));
  cell->vertex = vertex;
  cell->probability = probability;
  cell->next = NULL;
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

void print_adjacency_list(t_adjacency_list adjacency_list){
  for (int i = 0; i < adjacency_list.size; i++){
    printf("List for vertex [%d]: ", i);
    display_list(adjacency_list.vertices[i]);
  }
}

void add_cell(t_list *list, int vertex, float probability)
{
  t_cell *cell = create_cell(vertex, probability);
  if(list->head == NULL)
  {
    list->head = cell;
  }
  else
  {
    t_cell* temp = list->head;
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = cell;
  }
}

void display_list (t_list list)
{
  printf("[head @] -> ");
  t_cell* cell = list.head;
  while(cell != NULL)
  {
    printf("(%d, %f) @-> ", cell->vertex, cell->probability);
    cell = cell->next;
  }
  printf("NULL\n");

}
