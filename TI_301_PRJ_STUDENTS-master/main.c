#include "Mermaid Graph/graph.h"
#include "Mermaid Graph/mermaid.h"
#include "hasse.h"
#include "characteristics.h"
#include "matrix.h"

/**
 * @brief Clears the standard input buffer (stdin).
 *
 * This utility function reads and discards characters from the input stream
 * until a newline or EOF is reached. It is essential after using scanf()
 * to prevent leftover characters (like the 'Enter' key) from skipping
 * subsequent input prompts.
 * It was made by Gemini to avoid error with unexpected inputs
 */
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Displays a menu to select a graph data file.
 *
 * Presents a numbered list of predefined graph files to the user.
 * It constructs the full relative path based on the user's choice
 * and stores it in the provided buffer. It also handles custom filename input.
 *
 * @param filepath Buffer where the selected file's full path will be written.
 */
void select_file(char* filepath) {
    int choice = 0;
    printf("\n--- SELECT A FILE ---\n");
    printf("1. part2_graph.txt\n");
    printf("2. exemple1.txt\n");
    printf("3. exemple_meteo.txt\n");
    printf("4. exemple_valid_step3.txt\n");
    printf("5. Type custom path\n");
    printf("Choice: ");
    scanf("%d", &choice);
    clear_buffer();
    const char* base_path = "../TI_301_PRJ_STUDENTS-master/data/";
    switch (choice) {
        case 1:
            sprintf(filepath, "%spart2_graph.txt", base_path);
            break;
        case 2:
            sprintf(filepath, "%sexemple1.txt", base_path);
            break;
        case 3:
            sprintf(filepath, "%sexemple_meteo.txt", base_path);
            break;
        case 4:
            sprintf(filepath, "%sexemple_valid_step3.txt", base_path);
            break;
        case 5 : // This part is AI generated
            char user_input[100];
            printf("Enter filename (e.g., graph.txt): ");
            if (scanf("%100s", user_input) != 1) {
                printf("Invalid choice, defaulting to exemple_meteo.txt.\n");
                sprintf(filepath, "%sexemple_meteo.txt", base_path);
                break;
            }
            clear_buffer();
            snprintf(filepath, 256, "%s%s", base_path, user_input);
            break;
        default:
            printf("Invalid choice, defaulting to exemple_meteo.txt\n");
            sprintf(filepath, "%sexemple_meteo.txt", base_path);
            break;
    }
}


int main() {
    int choice = -1;
    int graph_loaded = 0;
    char filepath[256] = "";
    t_adjacency_list graph;
    t_partition partition;
    t_link_array* link_array = NULL;
    float ** matrix = NULL;

    printf("==========================================\n");
    printf("         STUDY OF MARKOV GRAPHS  \n");
    printf("==========================================\n");

    while (choice != 0) {
        printf("\n---------------- MAIN MENU ----------------\n");
        printf("1. Load new graph file\n");

        if (graph_loaded) {
            printf("2. [Part 1] Display Adjacency List\n");
            printf("3. [Part 1] Generate Mermaid Graph\n");
            printf("4. [Part 2] Run Tarjan Algorithm\n");
            printf("5. [Part 2] Generate Hasse Diagram\n");
            printf("6. [Part 3] Display Adjacency Matrix\n");
            printf("7. [Part 3] Power Matrix\n");
            printf("8. [Part 3] Study Matrix Convergence \n");
            printf("9. [Part 3] Study Sub-Matrix \n");
        }
        printf("0. Exit\n");
        printf("-------------------------------------------\n");
        printf("What do you want to do ? : ");

        if (scanf("%d", &choice) != 1) {
            clear_buffer();
            continue;
        }
        clear_buffer(); // Made by Gemini to avoid error with unexpected inputs

        switch (choice) {
            case 0:
                printf("Exiting program\n");
                break;

            // Load graph
            case 1:
                select_file(filepath);
                printf("Loading %s ...\n", filepath);
                graph = readGraph(filepath);
                graph_loaded = 1;
                printf("Graph loaded successfully.\n");
                link_array = NULL;
                break;

            // Display adjacency list
            case 2:
                if (!graph_loaded) {
                    printf("Load a graph first!\n");
                    break;
                }
                printf("\n--- Adjacency List ---\n");
                print_adjacency_list(graph);
                checkGraph(graph);
                break;

            // Mermaid graph
            case 3:
                if (!graph_loaded) {
                    printf("Load a graph first!\n");
                    break;
                }
                create_mermaid_tree(graph);
                printf("Mermaid text file generated in cmake-build-debug.\n");
                break;

            // Tarjan algorithm
            case 4:
                if (!graph_loaded) {
                    printf("Load a graph first!\n");
                    break;
                }
                partition = tarjan(graph);
                printf("\n--- Tarjan Partition ---\n");
                display_partition(partition);
                break;

            // Hasse
            case 5:
                if (!graph_loaded) {
                    printf("Load a graph first!\n");
                    break;
                }
                partition = tarjan(graph);
                link_array = createLinkArray();
                addLinks(link_array, graph);
                printf("Links found: %d\n", link_array->log_size);
                create_mermaid_hasse(link_array, partition);
                print_graph_characteristics(partition, *link_array);
                break;

            // Display matrix
            case 6:
                if (!graph_loaded) {
                    printf("Load a graph first!\n");
                    break;
                }
                float ** matrix = convert_matrix(graph);
                printf("\n--- Adjacency Matrix ---\n");
                display_matrix(matrix, graph.size);
                free_matrix(matrix, graph.size);
                break;

            // Power matrix
            case 7:
                if (!graph_loaded) {
                    printf("Load a graph first!\n");
                    break;
                }
                int k;
                printf("Enter exponent (positive integer) : ");
                if (scanf("%d", &k) != 1 || k < 0) {
                    printf("Invalid input.\n");
                    clear_buffer();
                    break;
                }
                clear_buffer();
                matrix = convert_matrix(graph);
                printf("\n--- Original matrix ---\n");
                display_matrix(matrix, graph.size);
                printf("\n");

                float ** power = power_matrix(matrix, graph.size, k);
                printf("\n--- Matrix to the power %d ---\n", k);
                display_matrix(power, graph.size);
                free_matrix(power, graph.size);
                free_matrix(matrix, graph.size);
                break;

            // Matrix Convergence
            case 8:
                if (!graph_loaded) {
                    printf("Load a graph first!\n");
                    break;
                }
                matrix = convert_matrix(graph);
                int n = graph.size;
                test_convergence(matrix, n);
                break;

            // Study of sub-matrix
            case 9:
                if (!graph_loaded) {
                    printf("Load a graph first!\n");
                    break;
                }
                partition = tarjan(graph);
                display_partition(partition);
                matrix = convert_matrix(graph);
                int classes_cpt = 0;
                t_class_cell * current = partition.head;
                while (current != NULL) {
                    classes_cpt++;
                    current = current->next;
                }
                int compo_index;
                printf("\n--- Select Component Number ---\n");
                if (scanf("%d", &compo_index) != 1 || compo_index < 1 || compo_index > classes_cpt) {
                    printf("Invalid input or number.\n");
                    clear_buffer();
                    break;
                }
                clear_buffer();
                compo_index--;
                int n_sub = 0 ;
                float ** sub_matrix = subMatrix(matrix, partition, compo_index, &n_sub);
                test_convergence(sub_matrix, n_sub);
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
