#include "Helpers.h"
#include <iostream>
#include <string>
#include "BigramStack.h"
#include "Queue.h"

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

    //test head
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
        if(line.find("head") != std::string::npos){
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

void takeUserInput(Queue *queue) {
    std::cout
            << "Type eq for enqueue or deq for dequeue, if push follow it by a space then a value\nType exit to finish\n"
            << std::endl;
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line.find("deq") != std::string::npos) {
            std::cout << queue->dequeue() << std::endl;
            std::cout << std::endl;
        } else if (line.find("eq") != std::string::npos) {
            int carNumber;
            std::string message;
            std::cout << "Please enter the car ID to be delivered to: ";
            std::cin >> carNumber;
            std::cout << "\nPlease enter the message to be delivered: ";
            std::cin>> message;
            queue->enqueue(message.c_str(),carNumber);
            std::cout << std::endl;

            //queue->enqueue(line.substr(line.find("eq") + 3, line.length()).c_str(), 0);
        } else if (line.find("head") != std::string::npos) {
            std::cout << queue->head() << std::endl;
            std::cout << std::endl;
        } else if (line.find("echo") != std::string::npos) {
            queue->echo();
            std::cout << std::endl;
        } else if (line.find("exit") != std::string::npos) {
            break;
        }
    }
}