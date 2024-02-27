#ifndef STACK_DYNAMICVECTSTACK_H
#define STACK_DYNAMICVECTSTACK_H

#include <vector>
#include "../BigramStack.h"
#include "../../Bigram.h"

class DynamicVectStack : public BigramStack {
public:
    DynamicVectStack() {};

    /*
     * pushes a new value onto the top of the stack
     *
     * @param const char *s : a char pointer being the value to add onto the stack
     * @return void
     * */
    int push(const char *s) override;

    /*
     * pops a value from the top of the stack and returns its value
     *
     * @param NA
     * @return Bigram : the value from the top of the stack
     * */
    Bigram pop() override;

    /*
     * clears the list of any values
     *
     * @param NA
     * @return int : returns 1 if successful
     * */
    int reset() override;

    /*
     * checks if the list is full
     *
     * @param NA
     * @return bool : true if full, false if not full
     * */
    bool isFull() const override;

    /*
     * checks if the list is empty
     *
     * @param NA
     * @return bool : true if empty, false if not empty
     * */
    bool isEmpty() const override;

    /*
     * lets you view what is currently on the top of the stack
     *
     * @param NA
     * @return const Bigram & : returns a const reference to the top item on the stack
     * */
    const Bigram &peek() const override;

    stackType getStackType() override;

private:
    std::vector<Bigram> data;
};


#endif //STACK_DYNAMICVECTSTACK_H
