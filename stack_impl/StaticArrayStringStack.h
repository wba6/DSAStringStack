//
// Created by William on 1/30/2024.
//

#ifndef STACK_STATICARRAYSTRINGSTACK_H
#define STACK_STATICARRAYSTRINGSTACK_H
#include "../StringStack.h"

#define StaticArrayStringStackSize 4
class StaticArrayStringStack : public StringStack{
public:
    StaticArrayStringStack() : top(-1) {};

    int push(const std::string& value) override;

    std::string pop() override;

    const std::string& peek() const override;

    bool isEmpty() const override;

    bool isFull() const override;

    int reset() override;

private:
    unsigned int top;
    std::string data[StaticArrayStringStackSize];
};


#endif //STACK_STATICARRAYSTRINGSTACK_H
