//
// Created by William on 1/30/2024.
//

#ifndef STACK_STATICARRAYSTACK_H
#define STACK_STATICARRAYSTACK_H
#include "../BigramStack.h"
#include "../Bigram.h"

#define StaticArrayStringStackSize 4
class StaticArrayStack : public BigramStack{
public:
    StaticArrayStack() : top(-1) {};

    int push(const char *value) override;

    Bigram pop() override;

    const Bigram & peek() const override;

    bool isEmpty() const override;

    bool isFull() const override;

    int reset() override;

private:
    unsigned int top;
    Bigram data[StaticArrayStringStackSize];
};


#endif //STACK_STATICARRAYSTACK_H
