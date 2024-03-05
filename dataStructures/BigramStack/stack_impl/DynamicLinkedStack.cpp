
#include <iostream>
#include "DynamicLinkedStack.h"


int DynamicLinkedStack::push(const char *s) {
    StackNode *newNode = nullptr; //pointer to new node

    //allocate a new node and store string
    newNode = new StackNode;
    newNode->value = s;

    //if list is empty set this node to the first
    if (isEmpty()) {
        top = newNode;
        newNode->next = nullptr;
    } else { // if not insert node before top
        newNode->next = top;
        top = newNode;
    }
    return 1;
}

Bigram DynamicLinkedStack::pop() {
    StackNode *temp = nullptr; //temporary pointer
    Bigram topVal; //top popped value

    if (isEmpty()) {
        std::cerr << "Stack underflow!" << std::endl;
        return " ";
    } else //pop value off top of stack
    {
        topVal = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
    return topVal;
}


int DynamicLinkedStack::reset() {
    while (top != nullptr) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
    return 1;
}

bool DynamicLinkedStack::isFull() const {
    return false;
}

const Bigram &DynamicLinkedStack::peek() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty!" << std::endl;
        return " ";
    }
    //peek at value
    return (top->value);
}

bool DynamicLinkedStack::isEmpty() const {
    if (!top) {
        return true;
    } else {
        return false;
    }
}

//Destructor that deletes are allocated values
DynamicLinkedStack::~DynamicLinkedStack() {
    this->reset();
}

stackType DynamicLinkedStack::getStackType() {
    return dynamicLinkedStack;
}
