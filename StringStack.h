
#ifndef STACK_STRINGSTACK_H
#define STACK_STRINGSTACK_H

#include <string>



class StringStack{ ;
protected:
    StringStack(){}
    virtual ~StringStack()= default;
public:
    enum stackType{
        dynamicLinkedStack,
        dynamicVectStack,
        staticArrayStringStack
    };
    /*
     * creates a new type of stack
     *
     * @param stackType type : the type of stack to be returned
     * @return void
     * */
    static StringStack *Create(stackType type);

    /*
     * pushes a new value onto the top of the stack
     *
     * @param std::string s : a string value being the value to add onto the stack
     * @return void
     * */
    virtual int push(const std::string &s) = 0;

    /*
     * pops a value from the top of the stack and returns its value
     *
     * @param NA
     * @return std::string : the value from the top of the stack
     * */
    virtual std::string pop() = 0;

    /*
     * clears the list of any values
     *
     * @param NA
     * @return int : returns 1 if successful
     * */
    virtual int  reset() = 0;

    /*
     * checks if the list is full
     *
     * @param NA
     * @return bool : true if full, false if not full
     * */
    virtual bool  isFull() const = 0;

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
     * @return const std::string& : returns a const reference to the top item on the stack
     * */
    virtual const std::string& peek() const = 0;

};
#endif //STACK_STRINGSTACK_H
