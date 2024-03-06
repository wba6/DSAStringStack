
#include "DynamicLinkedQueue.h"
#include <iostream>


// Enqueue an element to the back of the queue
void DynamicLinkedQueue::enqueue(const char *value) {
    if(strlen(value) > 5){
        std::cerr << "string is too long" << std::endl;
        return;
    }
    Node *newNode = new Node(value);
    if (isEmpty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    queueSize++;
}

// Dequeue an element from the front of the queue
const char * DynamicLinkedQueue::dequeue() {
    if (!isEmpty()) {
        const char* val = frontNode->data;
        Node *temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        queueSize--;
        return val;
    } else {
        std::cerr << "Queue is empty. Cannot dequeue.\n";
    }
    return " ";
}

// Get the front element without removing it
const char * DynamicLinkedQueue::head() const {
    if (!isEmpty()) {
        return frontNode->data;
    } else {
        std::cerr << "Queue is empty.\n";
        return " ";
    }
}

// Check if the queue is empty
bool DynamicLinkedQueue::isEmpty() const {
    return queueSize == 0;
}

// Get the size of the queue
size_t DynamicLinkedQueue::size() const {
    return queueSize;
}

// Destructor to free memory
DynamicLinkedQueue::~DynamicLinkedQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

bool DynamicLinkedQueue::isFull() const {
    return false;
}

void DynamicLinkedQueue::echo() const {
    Node* tempNode = frontNode;
    while(tempNode->next != nullptr){
        std::cout << tempNode->data << '\n';
        tempNode = tempNode->next;
    }
    std::cout << tempNode->data << '\n';
}

const char *DynamicLinkedQueue::tail() const {
    return rearNode->data;
}
