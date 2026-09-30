#include <malloc.h>
#include "hasse.h"
#include "Tarjan Algorithm/tarjan_algo.h"

/**
 * We didn't implement it
 * @brief Removes transitive (redundant) links from the link array.
 *
 * This function iterates through the list of links and removes any direct link
 * A -> C if there exists an intermediate path A -> B -> C. This is essential
 * for generating a clean Hasse diagram without redundancy.
 *
 * @param p_link_array Pointer to the array of links to be processed.
 */
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
            p_link_array->links[i] = p_link_array->links[p_link_array->log_size - 1];
            p_link_array->log_size--;
        }
        else
        {
            i++;
        }
    }
}

/**
 * @brief Identifies and adds links between strongly connected components (classes).
 *
 * This function maps every vertex of the graph to its corresponding class.
 * It then iterates through the graph's adjacency list to find edges that connect
 * two different classes and adds them to the link array if they don't already exist.
 *
 * @param p_link_array Pointer to the link array where found links will be stored.
 * @param graph The original adjacency list of the graph.
 */
void addLinks(t_link_array* p_link_array, t_adjacency_list graph) {
    t_partition partition = tarjan(graph);
    int size = graph.size;

    t_class** class_map = malloc(sizeof(t_class*) * size);


    t_class_cell* class_node = partition.head;

    while (class_node != NULL) {
        t_tarjan_cell* vertex_node = class_node->class->head;

        while (vertex_node != NULL) {
            int vertex_id = vertex_node->vertex->identifier;

            class_map[vertex_id - 1] = class_node->class;

            vertex_node = vertex_node->next;
        }
        class_node = class_node->next;
    }

    for (int i = 0; i < size; i++) {
        t_class* Ci = class_map[i];

        t_cell* cur = graph.vertices[i].head;

        while (cur) {
            int j_index = cur->vertex - 1;

            t_class* Cj = class_map[j_index];

            if (Ci != Cj) {
                int link_exists = 0;
                for (int k = 0; k < p_link_array->log_size; k++) {
                    if (p_link_array->links[k].from->name == Ci->name && p_link_array->links[k].to->name == Cj->name) {
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
            cur = cur->next;
        }
    }
    free(class_map);
}

/**
 * @brief Allocates and initializes a new empty link array.
 *
 * It reserves memory for the structure and a fixed capacity (50) of links.
 *
 * @return t_link_array* A pointer to the newly created link array structure.
 */
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

/**
 * @brief Generates a string label containing the vertices of a class.
 *
 * Formats the content of a class into a string like "{1,2,3}" to be used
 * as a label in the visualization.
 *
 * @param p_class Pointer to the class structure.
 * @param buffer Character buffer where the string will be written.
 */
void get_class_label(t_class* p_class, char* buffer) {
    strcpy(buffer, "{");
    t_tarjan_cell* curr = p_class->head;
    while (curr != NULL) {
        char num_str[20];
        sprintf(num_str, "%d", curr->vertex->identifier);
        strcat(buffer, num_str);
        if (curr->next != NULL) strcat(buffer, ",");
        curr = curr->next;
    }
    strcat(buffer, "}");
}

/**
 * @brief Generates a Mermaid file representing the Hasse diagram.
 *
 * This function creates a "hasse_diagram.txt" file. It first declares all nodes
 * (classes) with their vertex labels, and then defines the directed links
 * between them.
 *
 * @param p_link_array The array of links between classes.
 * @param partition The partition containing all the classes (nodes).
 */
void create_mermaid_hasse(t_link_array* p_link_array, t_partition partition) {
    FILE *file = fopen("hasse_diagram.txt", "w");
    if (file == NULL) {
        perror("Error opening the file hasse_diagram.txt");
        return;
    }

    fprintf(file, "---\nconfig:\nlayout: elk\ntheme: neo\nlook: neo\n---\n\nflowchart LR \n");
    t_class_cell* current_cell = partition.head;

    while (current_cell != NULL) {
        t_class* cls = current_cell->class;
        char label[1024] = "";

        get_class_label(cls, label);
        fprintf(file, "%s[\"%s\"]\n", cls->name, label);

        current_cell = current_cell->next;
    }

    for (int i = 0; i < p_link_array->log_size; i++) {
        t_link current_link = p_link_array->links[i];
        fprintf(file, "%s --> %s\n",
                current_link.from->name,
                current_link.to->name);
    }

    fclose(file);
    printf("Hasse diagram created in hasse_diagram.txt\n\n");
}