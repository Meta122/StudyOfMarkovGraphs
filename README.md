## Study of Markov Graphs

This project is written in C language and designed to analyze the structure and behavior of directed graphs.
It implements classic algorithms like Tarjan's for decomposition into a partition, matrix analysis methods to study convergence,
and the possibility to create Mermaid graphs for better readability.

---

## Core Features

The program offers an interactive menu to perform the following tasks:

### I. Graph Analysis (Parts 1 & 2)
* **Graph Loading**: Reads the graph structure from a specific text file.
* **Adjacency List Display**: Shows the internal representation of the graph.
* **Mermaid Generation**: Creates a text file in Mermaid format to visualize the graph and its Hasse diagram.
* **Tarjan's Algorithm**: Determines the partition of the graph into Strongly Connected Components.
* **Characteristics**: Calculates and displays structural properties (transitory, absorbing, etc.).

### II. Matrix Analysis (Part 3)
* **Adjacency Matrix**: Conversion of the graph into a transition matrix.
* **Matrix Power**: Calculates $M^k$ for a given exponent $k$.
* **Convergence Study**: Determines if the transition matrix $M$ converges to a limit matrix ($M^\infty$) after a given number of iterations ($M^n \approx M^{n-1}$).
* **Sub-Matrix Study**: Creates and studies the convergence of a sub-matrix generated from a class of the graph.

---

## Compilation and Execution

This project is developed in C and requires a standard C compiler (such as GCC) and a build system (like CMake).

---

## Contributors

This project was made by Rafael Véclin, Maël Prouteau and Frédéric Pacreau from group P2-INT2.

---

## Tools

This project was made using mainly CLion (for C and CMake), GitHub for version control, and Discord for communication between members.
AI was used to generate specific test-cases, help with documentation, explain some functions and concepts that were hard to understand, and help a bit with debugging.