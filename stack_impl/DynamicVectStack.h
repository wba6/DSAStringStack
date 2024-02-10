//
// Created by brade on 2/3/2024.
//

#ifndef STACK_DYNAMICVECTSTACK_H
#define STACK_DYNAMICVECTSTACK_H

#include <vector>
#include "../BigramStack.h"
#include "../Bigram.h"

class DynamicVectStack : public BigramStack {
public:
    DynamicVectStack() {};

    int push(const char *s) override;

    Bigram pop() override;

    int reset() override;

    bool isFull() const override;

    bool isEmpty() const override;

    const Bigram &peek() const override;

private:
    std::vector<Bigram> data;
};


#endif //STACK_DYNAMICVECTSTACK_H
