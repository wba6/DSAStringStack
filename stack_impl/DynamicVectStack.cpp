//
// Created by brade on 2/3/2024.
//

#include "DynamicVectStack.h"
#include "iostream"
#include "../Bigram.h"

int DynamicVectStack::push(const char *s) {
    data.push_back(Bigram(s));
    return 1;
}

Bigram DynamicVectStack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack underflow!" << std::endl;
        return " ";
    }
    Bigram topValue = data.back();
    data.pop_back();
    return topValue;
}

int DynamicVectStack::reset() {
    data.clear();
    return 1;
}

bool DynamicVectStack::isFull() const {
    return false;
}

bool DynamicVectStack::isEmpty() const {
    return data.empty();
}

const Bigram &DynamicVectStack::peek() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty (underflow)" << std::endl;
        return " ";
    }
    return data.back();
}

stackType DynamicVectStack::getStackType() {
    return dynamicVectStack;
}
