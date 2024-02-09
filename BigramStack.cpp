#include "BigramStack.h"
#include "stack_impl/DynamicLinkedStack.h"
#include "stack_impl/StaticArrayStack.h"
#include "stack_impl/DynamicVectStack.h"
#include "iostream"
/*
* creates a new type of stack
*
* @param stackType type : the type of stack to be returned
* @return void
* */
BigramStack *BigramStack::Create(stackType type) {
    switch (type) {
        case stackType::dynamicLinkedStack:
            return new DynamicLinkedStack;
        case stackType::staticArrayStack:
            return new StaticArrayStack;
        case stackType::dynamicVectStack:
            return new DynamicVectStack;
    }
    std::cerr << "Type not implemented" << std::endl;
    return nullptr;
}
