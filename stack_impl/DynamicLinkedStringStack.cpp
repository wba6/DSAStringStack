
#include <iostream>
#include "DynamicLinkedStringStack.h"

StringStack *StringStack::Create(stackType type) {
    if(type == stackType::dynamicLinkedStack){
        return (new DynamicLinkedStringStack);
    }
    return nullptr;
}

int DynamicLinkedStringStack::push(std::string s) {
    StackNode *newNode = nullptr; //pointer to new node

    //allocate a new node and store string
    newNode = new StackNode;
    newNode->value = s;

    //if list is empty set this node to the first
    if(isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else
    { // if not insert node before top
        newNode->next = top;
        top = newNode;
    }
    return 1;
}

std::string DynamicLinkedStringStack::pop() {
    StackNode *temp = nullptr; //temporary pointer
    std::string topVal; //top popped value

    if(isEmpty())
    {
        std::cout << "The Stack is empty" << std::endl;
    }
    else //pop value off top of stack
    {
        topVal = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
    return topVal;
}



int DynamicLinkedStringStack::reset() {
    StackNode *nodePtr; //used to traverse
    StackNode *nextNode; //keep track of following node

    //set nodePtr to the top of the stack
    nodePtr = top;

    //traverse the list deleting each node
    while(nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    return 1;
}

bool DynamicLinkedStringStack::isFull() {
    return false;
}

const std::string& DynamicLinkedStringStack::peak() {
    if(isEmpty())
    {
        std::cout << "The StringStack is empty" << std::endl;
    }
    else //pop value off top of stack
    {
        return top->value;
    }
    return "";
}

bool DynamicLinkedStringStack::isEmpty() {
    if(!top)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Destructor that deletes are allocated values
DynamicLinkedStringStack::~DynamicLinkedStringStack() {
   this->reset();
}
