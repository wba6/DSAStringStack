//
// Created by brade on 2/3/2024.
//

#ifndef STACK_DYNAMICVECTSTACK_H
#define STACK_DYNAMICVECTSTACK_H

#include <vector>
#include "../StringStack.h"

class DynamicVectStack : public StringStack {
public:
    DynamicVectStack(){};
    int push(const std::string &s) override;

    std::string pop() override;

    int reset() override;

    bool isFull() const override;

    bool isEmpty() const override;

    const std::string &peek() const override;
private:
    std::vector<std::string> data;
};


#endif //STACK_DYNAMICVECTSTACK_H
