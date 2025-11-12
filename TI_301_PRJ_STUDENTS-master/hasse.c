#include <malloc.h>
#include "hasse.h"


void removeTransitiveLinks(t_link_array *p_link_array)
{
    int i = 0;
    while (i < p_link_array->log_size)
    {
        t_link link1 = p_link_array->links[i];
        int j = 0;
        int to_remove = 0;
        while (j < p_link_array->log_size && !to_remove)
        {
            if (j != i)
            {
                t_link link2 = p_link_array->links[j];
                if (link1.from == link2.from)
                {
                    // look for a link from link2.to to link1.to
                    int k = 0;
                    while (k < p_link_array->log_size && !to_remove)
                    {
                        if (k != j && k != i)
                        {
                            t_link link3 = p_link_array->links[k];
                            if ((link3.from == link2.to) && (link3.to == link1.to))
                            {
                                to_remove = 1;
                            }
                        }
                        k++;
                    }
                }
            }
            j++;
        }
        if (to_remove)
        {
            // remove link1 by replacing it with the last link
            p_link_array->links[i] = p_link_array->links[p_link_array->log_size - 1];
            p_link_array->log_size--;
        }
        else
        {
            i++;
        }
    }
}


void addLinks(int size, t_tarjan_vertex** ids, t_link_array* p_link_array, int* class_of_vertex, t_adjacency_list graph){
    for (int i = 0; i < size; i++){
      int Ci = class_of_vertex[i];
      t_cell* cur = graph.vertices[i].head->next;
      int j = 0;
      while (cur){
        int Cj = class_of_vertex[cur->vertex];
        if (Ci != Cj){
            t_link* temp_link = createLink(Ci, Cj);
            int k = 0;
            while (k < p_link_array->log_size){
                if (p_link_array->links[k].from != (*temp_link).from && p_link_array->links[k].to != (*temp_link).to || p_link_array->links[k].from != (*temp_link).to && p_link_array->links[k].to != (*temp_link).from){
                  k++;
                }
                else{
                    p_link_array->log_size++;
                    p_link_array->links[k] = *temp_link;
                    k = p_link_array->log_size;
                }
            }
        }
        j++;
        cur = cur->next;
      }
    }

}

t_link* createLink(int a, int b){
      t_link* link = (t_link*)malloc(sizeof(t_link));
      link->from = a;
      link->to = b;
      return link;
  }

t_link_array* createLinkArray(){
  t_link_array* link = (t_link_array*)malloc(sizeof(t_link_array));
  link->log_size = 0;
  return link;
}