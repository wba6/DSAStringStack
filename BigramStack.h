
#ifndef STACK_BIGRAMSTACK_H
#define STACK_BIGRAMSTACK_H

#include "Bigram.h"

enum stackType {
    dynamicLinkedStack,
    dynamicVectStack,
    staticArrayStack
};

class BigramStack {
protected:
    BigramStack() {};

public:
    //default destructor
    virtual ~BigramStack() = default;

    /*
     * creates a new type of stack
     *
     * @param stackType type : the type of stack to be returned
     * @return void
     * */
    static BigramStack *Create(stackType type);

    /*
     * pushes a new value onto the top of the stack
     *
     * @param const char *s : a char pointer being the value to add onto the stack
     * @return void
     * */
    virtual int push(const char *s) = 0;

    /*
     * pops a value from the top of the stack and returns its value
     *
     * @param NA
     * @return Bigram : the value from the top of the stack
     * */
    virtual Bigram pop() = 0;

    /*
     * clears the list of any values
     *
     * @param NA
     * @return int : returns 1 if successful
     * */
    virtual int reset() = 0;

    /*
     * checks if the list is full
     *
     * @param NA
     * @return bool : true if full, false if not full
     * */
    virtual bool isFull() const = 0;

    /*
     * checks if the list is empty
     *
     * @param NA
     * @return bool : true if empty, false if not empty
     * */
    virtual bool isEmpty() const = 0;

    /*
     * lets you view what is currently on the top of the stack
     *
     * @param NA
     * @return const Bigram & : returns a const reference to the top item on the stack
     * */
    virtual const Bigram &peek() const = 0;

};

#endif //STACK_BIGRAMSTACK_H
