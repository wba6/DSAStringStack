cmake_minimum_required(VERSION 3.26)
project(stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack main.cpp
        BigramStack/BigramStack.h
        BigramStack/stack_impl/DynamicLinkedStack.cpp
        BigramStack/stack_impl/DynamicLinkedStack.h
        BigramStack/BigramStack.cpp
        BigramStack/stack_impl/StaticArrayStack.cpp
        BigramStack/stack_impl/StaticArrayStack.h
        BigramStack/stack_impl/DynamicVectStack.cpp
        BigramStack/stack_impl/DynamicVectStack.h
        Bigram.cpp
        Bigram.h
        BigramStack/stack_impl/StaticArrayStack.cpp
        queue/Queue.h
        queue/queue_impl/DynamicLinkedQueue.h
        queue/queue_impl/DynamicLinkedQueue.cpp
        queue/Queue.cpp
)
