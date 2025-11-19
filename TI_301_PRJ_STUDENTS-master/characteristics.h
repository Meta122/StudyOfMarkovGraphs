//
// Created by astri on 19/11/2025.
//

#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H

#include "Tarjan Algorithm/tarjan.h"
#include "hasse.h"

int is_transistory(t_link_array links);

int is_absorbing(t_link_array links, t_partition partition);

int is_irreducible(t_partition partition);

#endif //CHARACTERISTICS_H
