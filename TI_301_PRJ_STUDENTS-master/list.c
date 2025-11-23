#include "list.h"

/**
 * @brief Allocates and initializes a new cell (edge) for the adjacency list.
 *
 * @param vertex The destination vertex identifier.
 * @param probability The probability weight of the edge.
 * @return t_cell* A pointer to the newly created cell.
 */
t_cell* create_cell(int vertex, float probability){
  t_cell* cell = (t_cell*)malloc(sizeof(t_cell));
  cell->vertex = vertex;
  cell->probability = probability;
  cell->next = NULL;
  return cell;
}

/**
 * @brief Initializes an empty linked list.
 *
 * Sets the head pointer to NULL.
 *
 * @return t_list An empty list structure.
 */
t_list create_empty_list(){
  t_list list;
  list.head = NULL;
  return list;
}

/**
 * @brief Creates the main adjacency list structure for the graph.
 *
 * Allocates an array of lists corresponding to the number of vertices
 * [cite_start]and initializes each list to be empty [cite: 627-628].
 *
 * @param size The number of vertices in the graph.
 * @return t_adjacency_list The initialized adjacency list structure.
 */
t_adjacency_list create_empty_adjacency_list(int size){
    t_adjacency_list adjacency_list;
    adjacency_list.size = size;
    adjacency_list.vertices = (t_list*)malloc(sizeof(t_list) * size);
    for(int i = 0; i < size; i++){
      adjacency_list.vertices[i] = create_empty_list();
    }
    return adjacency_list;
}

/**
 * @brief Displays the entire adjacency list (the whole graph).
 *
 * [cite_start]Iterates through every vertex and prints its associated list of outgoing edges[cite: 629].
 *
 * @param adjacency_list The graph data structure to display.
 */
void print_adjacency_list(t_adjacency_list adjacency_list){
  for (int i = 0; i < adjacency_list.size; i++){
    printf("List for vertex [%d]: ", i);
    display_list(adjacency_list.vertices[i]);
  }
}

/**
 * @brief Adds a new edge to the end of a specific list.
 *
 * This function appends a new cell containing the destination vertex
 * [cite_start]and probability to the linked list[cite: 625].
 *
 * @param list Pointer to the linked list of the source vertex.
 * @param vertex The destination vertex ID.
 * @param probability The probability of the transition.
 */
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

/**
 * @brief Visualizes the content of a single linked list.
 *
 * [cite_start]Prints the vertices and probabilities in the format specified in Part 1 examples [cite: 593-617].
 *
 * @param list The list to be displayed.
 */
void display_list (t_list list)
{
  printf("[head @] -> ");
  t_cell* cell = list.head;
  while(cell != NULL)
  {
    printf("(%d, %1.2f) @-> ", cell->vertex, cell->probability);
    cell = cell->next;
  }
  printf("NULL\n");
}
