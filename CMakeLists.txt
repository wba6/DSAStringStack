cmake_minimum_required(VERSION 3.26)
project(stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack main.cpp
        BigramStack.h
        stack_impl/DynamicLinkedStack.cpp
        stack_impl/DynamicLinkedStack.h
        BigramStack.cpp
        stack_impl/StaticArrayStack.cpp
        stack_impl/StaticArrayStack.h
        stack_impl/DynamicVectStack.cpp
        stack_impl/DynamicVectStack.h
        Bigram.cpp
        Bigram.h
        stack_impl/StaticArrayStack.cpp
)
