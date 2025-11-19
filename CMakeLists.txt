cmake_minimum_required(VERSION 3.30)
project(StudyOfMarkovGraphs C)

set(CMAKE_C_STANDARD 11)

include_directories(TI_301_PRJ_STUDENTS-master)

add_executable(StudyOfMarkovGraphs
    "TI_301_PRJ_STUDENTS-master/Mermaid Graph/graph.c"
        "TI_301_PRJ_STUDENTS-master/Mermaid Graph/graph.h"
        TI_301_PRJ_STUDENTS-master/list.c
    TI_301_PRJ_STUDENTS-master/list.h
    TI_301_PRJ_STUDENTS-master/main.c
    TI_301_PRJ_STUDENTS-master/utils.c
    TI_301_PRJ_STUDENTS-master/utils.h
        TI_301_PRJ_STUDENTS-master/hasse.c
        TI_301_PRJ_STUDENTS-master/hasse.h
    "TI_301_PRJ_STUDENTS-master/Mermaid Graph/mermaid.c"
        "TI_301_PRJ_STUDENTS-master/Mermaid Graph/mermaid.h"
        "TI_301_PRJ_STUDENTS-master/Tarjan Algorithm/tarjan.c"
        "TI_301_PRJ_STUDENTS-master/Tarjan Algorithm/tarjan.h"
        "TI_301_PRJ_STUDENTS-master/Tarjan Algorithm/stack.c"
        "TI_301_PRJ_STUDENTS-master/Tarjan Algorithm/stack.h"
        "TI_301_PRJ_STUDENTS-master/Tarjan Algorithm/tarjan_algo.c"
        "TI_301_PRJ_STUDENTS-master/Tarjan Algorithm/tarjan_algo.h"
        "TI_301_PRJ_STUDENTS-master/characteristics.c"
        "TI_301_PRJ_STUDENTS-master/characteristics.h"

)
