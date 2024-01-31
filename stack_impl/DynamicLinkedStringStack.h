
#ifndef STACK_DYNAMICLINKEDSTRINGSTACK_H
#define STACK_DYNAMICLINKEDSTRINGSTACK_H

#include "../StringStack.h"
class DynamicLinkedStringStack : public StringStack {
private:
    //struct for StackNode
    struct StackNode
    {
        std::string value; //value of node
        StackNode *next; //pointer to next node
    };
    StackNode *top; //pointer to the stack top
public:
    DynamicLinkedStringStack(): top(nullptr) {};

    //destructor
    ~DynamicLinkedStringStack();

    int push(const std::string &s) override;

    std::string pop() override;

    int reset() override;

    bool isFull() const override;

    bool isEmpty() const override;

    const std::string& peek() const override;

};


#endif //STACK_DYNAMICLINKEDSTRINGSTACK_H
