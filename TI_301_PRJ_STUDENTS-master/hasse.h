#ifndef __HASSE_H__
#define __HASSE_H__

#include "Tarjan Algorithm/tarjan.h"
#include "string.h"

struct s_link {
    t_class* from;
    t_class* to;
} typedef t_link;

struct s_link_array {
  int log_size;
  t_link* links;
} typedef t_link_array;

void removeTransitiveLinks(t_link_array *p_link_array);

t_link* createLink(int, int);

t_link_array* createLinkArray();

void addLinks(t_link_array* p_link_array, t_adjacency_list graph);

void create_mermaid_hasse(t_link_array* p_link_array, t_partition partition);

/**
 * @brief Creates a link array from the given partition and graph.
 *
 * @param part The partition of the graph.
 * @param graph The adjacency list representation of the graph.
 * @return The created link array.
 */

#endif