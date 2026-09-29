cmake_minimum_required(VERSION 3.20)
project(StudyOfMarkovGraphs C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE_DIR_ORIGINAL "TI_301_PRJ_STUDENTS-master")
add_executable(StudyOfMarkovGraphs
    "${PROJECT_SOURCE_DIR_ORIGINAL}/Mermaid Graph/graph.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/Mermaid Graph/mermaid.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/Tarjan Algorithm/stack.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/Tarjan Algorithm/tarjan.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/Tarjan Algorithm/tarjan_algo.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/characteristics.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/hasse.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/list.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/main.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/matrix.c"
    "${PROJECT_SOURCE_DIR_ORIGINAL}/utils.c"
)
target_include_directories(StudyOfMarkovGraphs PRIVATE "${PROJECT_SOURCE_DIR_ORIGINAL}")
