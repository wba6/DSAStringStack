
#ifndef STACK_STRINGSTACK_H
#define STACK_STRINGSTACK_H

#include <string>

enum stackType{
    dynamicLinkedStack,
    staticStack
};

class StringStack{
public:


    static StringStack *Create(stackType type);

    /*
     * TODO: comment
     *
     * */
    virtual int push(std::string s) = 0;

    /*
    * TODO: comment
    *
    * */
    virtual std::string  pop() = 0;

    /*
    * TODO: comment
    *
    * */
    virtual int  reset() = 0;

    /*
    * TODO: comment
    *
    * */
    virtual bool  isFull() = 0;

    /*
    * TODO: comment
    *
    * */
    virtual bool isEmpty() = 0;

    /*
    * TODO: comment
    * look at top value
    * */
    virtual const std::string&  peak() = 0;

};
#endif //STACK_STRINGSTACK_H
