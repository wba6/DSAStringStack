/*
 * data structures tests main
 *
 * William Aey - Data Structures 2024
 */
#include <iostream>
#include "Helpers.h"
#include "BigramStack.h"
#include "Queue.h"


int main() {
    // Create a stack object.
    BigramStack *myStack = BigramStack::Create(stackType::staticArrayStack);

    //takeUserInput(myStack);
    //TODO: response codes and error handle
    //TODO:LinkedQueue is not up to standard
    //delete myStack;

    Queue* myQueue = Queue::Create(queueType::staticCircleQueue);
    myQueue->enqueue("1");
    myQueue->enqueue("2");
    myQueue->enqueue("3");
    myQueue->enqueue("4");
    myQueue->enqueue("5");
    std::cout << myQueue->dequeue() << std::endl;
    std::cout << myQueue->dequeue() << std::endl;
    std::cout << myQueue->dequeue() << std::endl;
    myQueue->enqueue("6");
    myQueue->enqueue("7");
    myQueue->enqueue("8");
    myQueue->echo();

    takeUserInput(myQueue);

    delete myQueue;
    return 0;
}
