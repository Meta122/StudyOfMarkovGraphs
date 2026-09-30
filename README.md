# Study of Markov Graphs

An academic C project for exploring directed graphs and transition matrices. The interactive program loads text examples, displays adjacency structures, finds strongly connected components with Tarjan's algorithm, generates Mermaid diagrams, and studies powers and convergence of matrices.

## What it covers

- Directed graph loading and adjacency list display
- Strongly connected components and graph characteristics
- Mermaid representations of graphs and Hasse diagrams
- Transition matrices, matrix powers, and numerical convergence experiments

## Build and run

Requires a C11 compiler and CMake 3.20 or newer.

```sh
cmake -S . -B build
cmake --build build
cd build
./StudyOfMarkovGraphs
```

On Windows, run the executable produced in the selected build configuration. The program expects to be started from the build directory: its bundled sample paths are relative to that directory. In the menu, choose **Load new graph file** first, then an example or a custom path.

## Repository layout

- `CMakeLists.txt` defines the executable.
- `src/` contains the C source and headers, grouped by graph and Tarjan components.
- `data/` contains sample graphs.

Run the focused algorithm tests with `ctest --test-dir build --output-on-failure` after building. They check strongly connected components on a graph with two cycles and one isolated vertex, plus known transition-matrix powers. CI runs these tests. The interactive menu and broader numerical behavior still need manual verification.

## Project context and contributions

Academic group project at Efrei by Rafael Véclin, Maël Prouteau and Frédéric Pacreau (P2-INT2, group 3). The current repository documents collective work; a precise per-person breakdown is not recorded here. CLion, GitHub and Discord supported development. AI assistance was used for selected test cases, documentation, explanations and debugging.

## License

MIT; see [LICENSE](LICENSE).
