#include "StringStack.h"
#include "stack_impl/DynamicLinkedStringStack.h"
#include "stack_impl/StaticArrayStringStack.h"
#include "stack_impl/DynamicVectStack.h"
#include "iostream"
/*
* creates a new type of stack
*
* @param stackType type : the type of stack to be returned
* @return void
* */
StringStack *StringStack::Create(stackType type) {
    switch (type) {
        case stackType::dynamicLinkedStack:
            return new DynamicLinkedStringStack;
        case stackType::staticArrayStringStack:
            return new StaticArrayStringStack;
        case stackType::dynamicVectStack:
            return new DynamicVectStack;
    }
    std::cerr << "Type not implemented" << std::endl;
    return nullptr;
}
