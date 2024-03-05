/*
 * Bigram Stack tests main
 *
 * William Aey - Data Structures 2024
 */
#include <iostream>
#include <string>
#include "dataStructures/BigramStack/BigramStack.h"
#include "dataStructures/queue/Queue.h"
int testBigramStackRealValues(BigramStack *myStack);
int testBigramStackErrorValues(BigramStack *myStack);
void takeUserInput(BigramStack *myStack);

int main() {
    // Create a stack object.
    BigramStack *myStack = BigramStack::Create(stackType::staticArrayStack);

    //takeUserInput(myStack);

    //delete myStack;
    Queue* myQueue = Queue::Create(queueType::staticCircleQueue);
    myQueue->enqueue(1);
    myQueue->enqueue(2);
    myQueue->enqueue(3);
    myQueue->enqueue(4);
    myQueue->enqueue(5);
    std::cout << myQueue->dequeue() << std::endl;
    std::cout << myQueue->dequeue() << std::endl;
    std::cout << myQueue->dequeue() << std::endl;
    std::cout << myQueue->dequeue() << std::endl;
    std::cout << myQueue->dequeue() << std::endl;

    return 0;
}

int testBigramStackRealValues(BigramStack *myStack) {
    //push two values onto stack
    myStack->push("ab");
    myStack->push("cd");

    //pop both values and check
    if (myStack->pop() != "CD") {
        return -1;
    }
    if (myStack->pop() != "AB") {
        return -1;
    }


    //push three values with edge conditions
    myStack->push("AB");
    myStack->push(" c");
    myStack->push("g.");

    //pop values and check
    if (myStack->pop() != "G ") {
        return -1;
    }
    if (myStack->pop() != "C ") {
        return -1;
    }
    if (myStack->pop() != "AB") {
        return -1;
    }

    //test peek
    myStack->push("ab");
    myStack->push("cd");
    if (myStack->peek() != "CD") {
        return -1;
    }

    myStack->reset();

    return 1;
}

int testBigramStackErrorValues(BigramStack *myStack) {

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

    myStack->reset();
    return 1;
}

void takeUserInput(BigramStack *myStack){
    std::cout << "Type push or pop, if push follow it by a space then a value\nType test to run test cases\nType exit to finish\n" << std::endl;
    while(true){
        std::string line;
        std::getline(std::cin, line);
        if(line.find("push") != std::string::npos){
            myStack->push(line.substr(line.find("push")+5,line.length()).c_str());
        }
        if(line.find("pop") != std::string::npos){
            std::cout << myStack->pop() << std::endl;
        }
        if(line.find("peek") != std::string::npos){
            std::cout << myStack->peek() << std::endl;
        }
        if(line.find("test") != std::string::npos){
            bool pass = true;
            if (testBigramStackRealValues(myStack) == -1) {
                std::cerr << "Real value test case failed" << std::endl;
                pass = false;
            }

            if (testBigramStackErrorValues(myStack) == -1) {
                std::cerr << "Error value test case failed" << std::endl;
                pass = false;
            }

            std::cout << (pass ? "All tests passed" : "Test failed") << std::endl;
        }
        if(line.find("exit") != std::string::npos){
            break;
        }
    }
}