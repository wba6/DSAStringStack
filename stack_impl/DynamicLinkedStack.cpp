
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
        return nullptr;
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
    StackNode *nodePtr; //used to traverse
    StackNode *nextNode; //keep track of following node

    //set nodePtr to the top of the stack
    nodePtr = top;

    //traverse the list deleting each node
    while (nodePtr != nullptr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    return 1;
}

bool DynamicLinkedStack::isFull() const {
    return false;
}

const Bigram &DynamicLinkedStack::peek() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty!" << std::endl;
    } else //pop value off top of stack
    {
        return top->value;
    }
    return nullptr;
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
