
#include <iostream>
#include "BigramStack.h"

int testRealValues(BigramStack *myStack);
int testErrorValues(BigramStack *myStack);

int main() {
    // Create a stack object.
    BigramStack *myStack = BigramStack::Create(stackType::dynamicVectStack);

    //test cases
    bool pass = true;
    if (testRealValues(myStack) == -1) {
        std::cerr << "Real value test case failed" << std::endl;
        pass = false;
    }

    if (testErrorValues(myStack) == -1) {
        std::cerr << "Error value test case failed" << std::endl;
        pass = false;
    }

    std::cout << (pass ? "All tests passed" : "Test failed") << std::endl;
    delete myStack;
    return 0;
}

int testRealValues(BigramStack *myStack) {

    //push two values onto stack
    myStack->push("ab");
    myStack->push("cd");

    //pop both values and check
    if (myStack->pop() != "cd") {
        return -1;
    }
    if (myStack->pop() != "ab") {
        return -1;
    }


    //push three values with edge conditions
    myStack->push("AB");
    myStack->push(" c");
    myStack->push("g.");

    //pop values and check
    if (myStack->pop() != "g ") {
        return -1;
    }
    if (myStack->pop() != "c ") {
        return -1;
    }
    if (myStack->pop() != "ab") {
        return -1;
    }
    return 1;
}

int testErrorValues(BigramStack *myStack) {

    myStack->push("ab");
    myStack->push("cd");
    myStack->push("cd");

    if(myStack->getStackType() == stackType::staticArrayStack) {
        //push too many values onto stack
        if (myStack->push("cd") != -1) {
            return -1;
        }
    }

    //pop too many values and check
    myStack->pop();
    myStack->pop();
    myStack->pop();
    if (myStack->pop() != "  ") {
        return -1;
    }
    return 1;
}
