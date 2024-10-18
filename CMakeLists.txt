cmake_minimum_required(VERSION 3.10)

project(AutomatedMenuManagementSystem C)

set(SOURCES
    src/AutomatedMenuManagementSystem.c
    src/AutomatedMenuManagementSystem.h)


add_executable(AutomatedMenuManagementSystem ${SOURCES})

enable_testing()
add_test(NAME unit_tests COMMAND AutomatedMenuManagementSystem)
