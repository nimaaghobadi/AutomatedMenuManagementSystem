cmake_minimum_required(VERSION 3.10)

project(AutomatedMenuManagementSystem C)

include_directories(src)

set(SOURCES
    src/AutomatedMenuManagementSystem.c)

add_executable(AutomatedMenuManagementSystem ${SOURCES})

enable_testing()

add_test(NAME unit_tests COMMAND AutomatedMenuManagementSystem)

add_executable(test_automated_menu tests/test_automated_menu_management.c)
add_test(NAME unit_test COMMAND test_automated_menu)

