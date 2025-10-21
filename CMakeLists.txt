cmake_minimum_required(VERSION 3.30)
project(StudyOfMarkovGraphs C)

set(CMAKE_C_STANDARD 11)

include_directories(TI_301_PRJ_STUDENTS-master)

add_executable(StudyOfMarkovGraphs
    TI_301_PRJ_STUDENTS-master/graph.c
    TI_301_PRJ_STUDENTS-master/graph.h
    TI_301_PRJ_STUDENTS-master/list.c
    TI_301_PRJ_STUDENTS-master/list.h
    TI_301_PRJ_STUDENTS-master/main.c
    TI_301_PRJ_STUDENTS-master/utils.c
    TI_301_PRJ_STUDENTS-master/utils.h)
