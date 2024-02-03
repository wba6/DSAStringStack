//
// Created by brade on 2/3/2024.
//

#include "DynamicVectStack.h"
#include "iostream"

int DynamicVectStack::push(const std::string &s) {
    data.push_back(s);
    return 1;
}

std::string DynamicVectStack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack underflow!" << std::endl;
        return "";
    }
    std::string topValue = data.back();
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

const std::string &DynamicVectStack::peek() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty (underflow)" << std::endl;
    }
    return data.back();
}
