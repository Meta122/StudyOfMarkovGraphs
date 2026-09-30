cmake_minimum_required(VERSION 3.20)
project(StudyOfMarkovGraphs C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE_DIR_CODE "src")
add_executable(StudyOfMarkovGraphs
    "${PROJECT_SOURCE_DIR_CODE}/Mermaid Graph/graph.c"
    "${PROJECT_SOURCE_DIR_CODE}/Mermaid Graph/mermaid.c"
    "${PROJECT_SOURCE_DIR_CODE}/Tarjan Algorithm/stack.c"
    "${PROJECT_SOURCE_DIR_CODE}/Tarjan Algorithm/tarjan.c"
    "${PROJECT_SOURCE_DIR_CODE}/Tarjan Algorithm/tarjan_algo.c"
    "${PROJECT_SOURCE_DIR_CODE}/characteristics.c"
    "${PROJECT_SOURCE_DIR_CODE}/hasse.c"
    "${PROJECT_SOURCE_DIR_CODE}/list.c"
    "${PROJECT_SOURCE_DIR_CODE}/main.c"
    "${PROJECT_SOURCE_DIR_CODE}/matrix.c"
    "${PROJECT_SOURCE_DIR_CODE}/utils.c"
)
target_include_directories(StudyOfMarkovGraphs PRIVATE "${PROJECT_SOURCE_DIR_CODE}")

include(CTest)
if(BUILD_TESTING)
    add_executable(test_algorithms
        tests/test_algorithms.c
        "${PROJECT_SOURCE_DIR_CODE}/list.c"
        "${PROJECT_SOURCE_DIR_CODE}/matrix.c"
        "${PROJECT_SOURCE_DIR_CODE}/Tarjan Algorithm/stack.c"
        "${PROJECT_SOURCE_DIR_CODE}/Tarjan Algorithm/tarjan.c"
        "${PROJECT_SOURCE_DIR_CODE}/Tarjan Algorithm/tarjan_algo.c"
    )
    target_include_directories(test_algorithms PRIVATE "${PROJECT_SOURCE_DIR_CODE}")
    if(UNIX)
        target_link_libraries(test_algorithms PRIVATE m)
    endif()
    add_test(NAME algorithms COMMAND test_algorithms)
endif()
