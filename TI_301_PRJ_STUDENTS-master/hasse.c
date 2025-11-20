#include <malloc.h>
#include "hasse.h"

#include "Tarjan Algorithm/tarjan_algo.h"


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
                    // look for a link from link2.to link1.to
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


void addLinks(t_link_array* p_link_array, t_adjacency_list graph) {
    t_partition partition = tarjan(graph);
    int size = graph.size;

    int* class_map = (int*)malloc(sizeof(int) * size);

    if (class_map == NULL) {
        printf("Failed to allocate memory for class map");
        return;
    }

    for(int i=0; i<size; i++) class_map[i] = -1;

    int current_class_id = 0;
    t_class_cell* class_node = partition.head;

    while (class_node != NULL) {
        t_tarjan_cell* vertex_node = class_node->class->head;

        while (vertex_node != NULL) {
            int vertex_id = vertex_node->vertex->identifier;

            if (vertex_id - 1 >= 0 && vertex_id - 1 < size) {
                class_map[vertex_id - 1] = current_class_id;
            }

            vertex_node = vertex_node->next;
        }

        current_class_id++;
        class_node = class_node->next;
    }

    for (int i = 0; i < size; i++) {
        int Ci = class_map[i];
        if (Ci == -1) continue;

        t_cell* cur = graph.vertices[i].head->next;

        while (cur) {
            int j_index = cur->vertex - 1;

            if (j_index >= 0 && j_index < size) {
                int Cj = class_map[j_index];

                if (Cj != -1 && Ci != Cj) {
                    int link_exists = 0;
                    for (int k = 0; k < p_link_array->log_size; k++) {
                        if (p_link_array->links[k].from == Ci && p_link_array->links[k].to == Cj) {
                            link_exists = 1;
                            break;
                        }
                    }
                    if (!link_exists) {
                        p_link_array->links[p_link_array->log_size].from = Ci;
                        p_link_array->links[p_link_array->log_size].to = Cj;
                        p_link_array->log_size++;
                    }
                }
            }
            cur = cur->next;
        }
    }
    free(class_map);
}

/*void addLinks(int size, t_link_array* p_link_array, int* class_of_vertex, t_adjacency_list graph){
    for (int i = 0; i < size; i++){
      int Ci = class_of_vertex[i];
      t_cell* cur = graph.vertices[i].head->next;
      while (cur){
          int j = cur->vertex - 1;
          int Cj = class_of_vertex[j];
        if (Ci != Cj){
            // Verify if the link already exists or not
            int link_exists = 0;
            for (int k = 0; k < p_link_array->log_size; k++) {
                if (p_link_array->links[k].from == Ci && p_link_array->links[k].to == Cj) {
                    link_exists = 1;
                    break;
                }
            }
            if (!link_exists) {
                p_link_array->links[p_link_array->log_size].from = Ci;
                p_link_array->links[p_link_array->log_size].to = Cj;
                p_link_array->log_size++;
            }
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
        cur = cur->next;
      }
    }

}*/

t_link_array* createLinkArray(){
  t_link_array* array = (t_link_array*)malloc(sizeof(t_link_array));
    if (array == NULL) return NULL;
    array->links = (t_link*)malloc(sizeof(t_link) * 50);
    if (array->links == NULL) {
        free(array);
        return NULL;
    }
  array->log_size = 0;
  return array;
}

void create_mermaid_hasse(t_link_array* p_link_array) {
    FILE *file = fopen("hasse_diagram.txt", "w");
    if (file == NULL) {
        perror("Error opening the file hasse_diagram.txt");
        return;
    }

    char output[10000] =
        "---\n"
        "config:\n"
        "layout: elk\n"
        "theme: neo\n"
        "look: neo\n"
        "--- \n"
        "\nflowchart LR \n";

    for (int i = 0; i < p_link_array->log_size; i++) {
        char line[256] = "";
        t_link current_link = p_link_array->links[i];

        sprintf(line, "C%d[%d] --> C%d[%d]\n", current_link.from, current_link.from, current_link.to, current_link.to);
        strcat(output, line);
    }

    fprintf(file, "%s", output);
    fclose(file);
    printf("Hasse diagram generated in hasse_diagram.txt\n");
}