#ifndef STACK_H
#define STACK_H
#include "tarjan.h"

typedef struct s_stackcell {
  int number ;
  struct s_stackcell * next ;
} t_stackcell ;

typedef struct s_stacklist {
  t_stackcell * head ;
} t_stacklist ;

int pop(t_stacklist *) ;
int top(t_stacklist) ;
int isInStack(int, t_stacklist) ;

#endif //STACK_H
