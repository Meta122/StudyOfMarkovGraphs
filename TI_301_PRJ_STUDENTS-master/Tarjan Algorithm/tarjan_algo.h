#ifndef TARJAN_ALGO_H
#define TARJAN_ALGO_H

#include "list.h"
#include "stack.h"

int min(int, int) ;
void strongConnect(t_adjacency_list, t_tarjan_vertex *, t_stacklist *, int *, t_partition, t_tarjan_vertex **); ;
t_partition tarjan(t_adjacency_list) ;

#endif //TARJAN_ALGO_H
