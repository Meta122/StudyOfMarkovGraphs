#ifndef STACK_H
#define STACK_H
#include "tarjan.h"

typedef struct s_stackcell {
  t_tarjan_vertex vertex ;
  struct s_stackcell * next ;
} t_stackcell ;

typedef struct s_stacklist {
  t_stackcell * head ;
} t_stacklist ;

t_tarjan_vertex pop(t_stacklist *) ;
t_tarjan_vertex top(t_stacklist) ;

#endif //STACK_H
