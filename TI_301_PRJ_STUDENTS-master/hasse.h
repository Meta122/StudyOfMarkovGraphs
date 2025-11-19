#ifndef __HASSE_H__
#define __HASSE_H__

#include "Tarjan Algorithm/tarjan.h"

struct s_link {
    int from;
    int to;
} typedef t_link;

struct s_link_array {
  int log_size;
  t_link* links;
} typedef t_link_array;

void removeTransitiveLinks(t_link_array *p_link_array);

t_link* createLink(int, int);

t_link_array* createLinkArray();

void addLinks(int size,t_link_array *p_link_array, int* class_of_vertex, t_adjacency_list);

/**
 * @brief Creates a link array from the given partition and graph.
 *
 * @param part The partition of the graph.
 * @param graph The adjacency list representation of the graph.
 * @return The created link array.
 */

#endif