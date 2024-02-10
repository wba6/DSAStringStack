
#ifndef STACK_DYNAMICLINKEDSTACK_H
#define STACK_DYNAMICLINKEDSTACK_H

#include "../BigramStack.h"
#include "../Bigram.h"

class DynamicLinkedStack : public BigramStack {
private:
    //struct for StackNode
    struct StackNode {
        Bigram value; //value of node
        StackNode *next; //pointer to next node
    };
    StackNode *top; //pointer to the stack top
public:
    DynamicLinkedStack() : top(nullptr) {};

    //destructor
    ~DynamicLinkedStack();

    int push(const char *s) override;

    Bigram pop() override;

    int reset() override;

    bool isFull() const override;

    bool isEmpty() const override;

    const Bigram & peek() const override;

};


#endif //STACK_DYNAMICLINKEDSTACK_H
