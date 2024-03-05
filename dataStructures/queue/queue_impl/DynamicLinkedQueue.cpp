
#include "DynamicLinkedQueue.h"
#include <iostream>


// Enqueue an element to the back of the queue
void DynamicLinkedQueue::enqueue(int value) {
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
int DynamicLinkedQueue::dequeue() {
    if (!isEmpty()) {
        int val = frontNode->data;
        Node *temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        queueSize--;
        return val;
    } else {
        std::cerr << "Queue is empty. Cannot dequeue.\n";
    }
    return -1;
}

// Get the front element without removing it
int DynamicLinkedQueue::peek() const {
    if (!isEmpty()) {
        return frontNode->data;
    } else {
        std::cerr << "Queue is empty.\n";
        return -1; // Return a sentinel value
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
