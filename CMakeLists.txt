cmake_minimum_required(VERSION 3.8)
project(data_structures_in_c)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(Main ${SOURCE_FILES})

add_executable(SequentialList "LinearList/SequentialList.c")
add_executable(SinglyLinkedList "LinearList/SinglyLinkedList.c")
add_executable(StaticLinkedList "LinearList/StaticLinkedList.c")
add_executable(CircularLinkedList "LinearList/CircularLinkedList.c")
add_executable(DoubleLinkedList "LinearList/DoubleLinkedList.c")
add_executable(SequentialStack "Stack/SequentialStack.c")
add_executable(ShareStack "Stack/ShareStack.c")
add_executable(LinkedStack Stack/LinkedStack.c)
add_executable(SequentialQueue Queue/SequentialQueue.c)
add_executable(LinkedQueue Queue/LinkedQueue.c)
add_executable(BinaryTree Tree/BinaryTree.c)