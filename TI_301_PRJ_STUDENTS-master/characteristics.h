//
// Created by astri on 19/11/2025.
//

#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H

#include "Tarjan Algorithm/tarjan.h"
#include "hasse.h"

int is_transitory(t_class* c, t_link_array links);

int is_absorbing(t_class* c, t_link_array links);

int is_irreducible(t_partition partition);

void print_graph_characteristics(t_partition partition, t_link_array links);

#endif //CHARACTERISTICS_H
