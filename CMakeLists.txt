cmake_minimum_required(VERSION 3.26)
project(stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack main.cpp
        StringStack.h
        stack_impl/DynamicLinkedStringStack.cpp
        stack_impl/DynamicLinkedStringStack.h
)
