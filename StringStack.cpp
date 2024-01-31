#include "StringStack.h"
#include "stack_impl/DynamicLinkedStringStack.h"
#include "stack_impl/StaticArrayStringStack.h"

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
    }
    return nullptr;
}
