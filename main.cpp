
#include <iostream>
#include "BigramStack.h"

int testRealValues(BigramStack *myStack);

int main() {
    // Create a stack object.
    BigramStack *myStack = BigramStack::Create(stackType::dynamicVectStack);

    if(testRealValues(myStack) == -1){
        std::cerr << "real value test case failed" << std::endl;
    }
    /*std::cout << "Pushing ab cd" << std::endl;
    myStack->push("ab");
    myStack->push("cd");
    std::cout << "Poping 3 values 1 to many:" << std::endl;
    std::cout << myStack->pop() << std::endl;
    std::cout << myStack->pop() << std::endl;
    std::cout << myStack->pop() << "\n" << std::endl;

    std::cout << "Pushing ab c_\n" << std::endl;
    myStack->push("ab");
    myStack->push("c ");
    std::cout << "Pop 1 value:" << std::endl;
    std::cout << myStack->pop() << "\n" << std::endl;

    std::cout << "Pushing to many values for static implementations\n" << std::endl;
    myStack->push("de");
    myStack->push("f ");
    myStack->push("g.");
    myStack->push("hi");
*/
    delete myStack;
    return 0;
}

int testRealValues(BigramStack *myStack){

    //push two values onto stack
    myStack->push("ab");
    myStack->push("cd");

    //pop both values and check
    if(myStack->pop() != "cd"){
        return -1;
    }
    if(myStack->pop() != "ab"){
        return -1;
    }


    //push three values with edge conditions
    myStack->push("AB");
    myStack->push(" c");
    myStack->push("g.");

    //pop values and check
    if(myStack->pop() != "g "){
        return -1;
    }
    if(myStack->pop() != "c "){
        return -1;
    }
    //TODO: why does this crash only with static?
    if(myStack->pop() != "ab"){
        return -1;
    }
    return 1;
}
