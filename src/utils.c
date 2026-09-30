#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


/**
 * @brief Generates a string identifier from an integer vertex number.
 *
 * Translates a number into an Excel-column style alphabetical ID
 * (e.g., 1->"A", 2->"B", ..., 26->"Z", 27->"AA").
 * This is useful for creating readable node labels in visualization tools like Mermaid.
 *
 * @param i The vertex number (1-based index).
 * @return char* A pointer to a static buffer containing the generated string ID.
 */
char *getID(int i)
{
    // translate from 1,2,3, .. ,500+ to A,B,C,..,Z,AA,AB,...
    static char buffer[10];
    char temp[10];
    int index = 0;

    i--; // Adjust to 0-based index
    while (i >= 0)
    {
        temp[index++] = 'A' + (i % 26);
        i = (i / 26) - 1;
    }

    // Reverse the string to get the correct order
    for (int j = 0; j < index; j++)
    {
        buffer[j] = temp[index - j - 1];
    }
    buffer[index] = '\0';

    return buffer;
}
