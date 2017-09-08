cmake_minimum_required(VERSION 3.8)
project(data_structures_in_c)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(Main ${SOURCE_FILES})

add_executable(SequentialList "Linear List/SequentialList.c")
add_executable(SinglyLinkedList "Linear List/SinglyLinkedList.c")
add_executable(StaticLinkedList "Linear List/StaticLinkedList.c")
add_executable(CircularLinkedList "Linear List/CircularLinkedList.c")