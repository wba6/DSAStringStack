//
// Created by William on 1/30/2024.
//

#include <iostream>
#include "StaticArrayStack.h"
#include "../Bigram.h"

int StaticArrayStack::push(const char *value) {
    if (top == StaticArrayStringStackSize) {
        std::cerr << "Stack overflow!" << std::endl;
        return -1;
    }
    data[++top] = value;
    return 1;
}

Bigram StaticArrayStack::pop() {
    if (top == -1) {
        std::cerr << "Stack underflow!" << std::endl;
        return "";
    }
    return data[top--];
}

const Bigram &StaticArrayStack::peek() const {
    if (top == -1) {
        std::cerr << "Stack is empty!" << std::endl;
        return nullptr;
    }
    return data[top];
}

bool StaticArrayStack::isEmpty() const {
    return top == -1;
}

bool StaticArrayStack::isFull() const {
    return top == StaticArrayStringStackSize - 1;
}

int StaticArrayStack::reset() {
    top = -1;
    return 1;
}
