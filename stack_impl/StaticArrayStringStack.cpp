//
// Created by William on 1/30/2024.
//

#include <iostream>
#include "StaticArrayStringStack.h"

int StaticArrayStringStack::push(const std::string& value) {
    if (top == StaticArrayStringStackSize) {
        std::cerr << "Stack overflow!" << std::endl;
        return -1;
    }
    data[++top] = value;
    return 1;
}

std::string StaticArrayStringStack::pop() {
    if (top == -1) {
        std::cerr << "Stack underflow!" << std::endl;
        return "";
    }
    return data[top--];
}

const std::string& StaticArrayStringStack::peek() const {
    if (top == -1) {
        std::cerr << "Stack is empty!" << std::endl;
        return "";
    }
    return data[top];
}

bool StaticArrayStringStack::isEmpty() const {
    return top == -1;
}

bool StaticArrayStringStack::isFull() const {
    return top == StaticArrayStringStackSize-1;
}

int StaticArrayStringStack::reset() {
    top = -1;
}
