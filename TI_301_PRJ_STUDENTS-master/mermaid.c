//
// Created by astri on 21/10/2025.
//

#include "mermaid.h"
#include "stdio.h"
#include "string.h"

void create_mermaid_tree(t_adjacency_list graph){
    FILE *file = fopen("tree.txt", "w"); // read-only, text
    if (file == NULL)
    {
        printf("Error opening the file %s", "tree.txt");
    }

    char output[10000] =
        "---\n"
        "config:\n"
        "layout: elk\n"
        "theme: neo\n"
        "look: neo\n"
        "--- \n"
        "\nflowchart LR \n";

    char lettersID[100][100];
    for (int i = 0; i < graph.size; i++){
      strcpy(lettersID[i], getID(i+1));
      char line[100] = "";
      sprintf(line, "%s((%d))\n", lettersID[i],i+1);
      strcat(output, line);
    }
    strcat(output, "\n");
    for (int i = 0; i < graph.size; i++){
        t_cell* cell = graph.vertices[i].head;

        while(cell != NULL)
        {
            char line[100] = "";
            sprintf(line, "%s -->|%f|%s\n", lettersID[i],cell->probability,lettersID[(cell->vertex)-1]);
            strcat(output, line);
            cell = cell->next;
        }
    }

    fprintf(file, "%s", output);
    fclose(file);

}