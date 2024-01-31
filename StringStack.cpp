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
    if(type == stackType::dynamicLinkedStack){
        return (new DynamicLinkedStringStack);
    }else if(type == stackType::staticArrayStringStack){
        return (new StaticArrayStringStack);
    }
    return nullptr;
}
