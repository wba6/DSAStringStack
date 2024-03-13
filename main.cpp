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
    //BigramStack *myStack = BigramStack::Create(stackType::staticArrayStack);

    //takeUserInput(myStack);
    //TODO:LinkedQueue is not up to standard
    //delete myStack;

    Queue* myQueue = Queue::Create(queueType::staticCircleQueue);
//    myQueue->enqueue("Cool", 96);
//    myQueue->enqueue("yea", 21);
//    myQueue->enqueue("3", 0);
//    myQueue->enqueue("4", 0);
//    myQueue->enqueue("5", 0);
//    std::cout << myQueue->dequeue() << std::endl;
//    std::cout << myQueue->dequeue() << std::endl;
//    std::cout << myQueue->dequeue() << std::endl;
//    myQueue->enqueue("6", 0);
//    myQueue->enqueue("7", 0);
//    myQueue->enqueue("8", 0);
    myQueue->echo();

    takeUserInput(myQueue);

    delete myQueue;
    return 0;
}
