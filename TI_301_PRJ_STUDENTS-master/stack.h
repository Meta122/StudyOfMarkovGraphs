#ifndef STACK_H
#define STACK_H
#include "tarjan.h"

typedef struct s_stackcell {
  t_tarjan_vertex vertex ;
  t_tarjan_vertex * next ;
} t_stackcell ;

typedef struct s_stacklist {
  t_stackcell * head ;
} t_stacklist ;

t_tarjan_vertex pop(t_stacklist *) ;
t_tarjan_vertex top(t_stacklist) ;

#endif //STACK_H
