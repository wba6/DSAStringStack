/*
#ifndef STACK_DYNAMICLINKEDQUEUE_H
#define STACK_DYNAMICLINKEDQUEUE_H

#include "../Queue.h"
#include "dataClass/Message.h"

class DynamicLinkedQueue : public Queue {
private:
    struct Node {
        const char* data;
        Node *next;

        Node(const char* val) : data(val), next(nullptr) {}
    };

    Node *frontNode; // Pointer to the front of the queue
    Node *rearNode;  // Pointer to the rear of the queue
    size_t queueSize; // Size of the queue

public:
    DynamicLinkedQueue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

    // Enqueue an element to the back of the queue
    int enqueue(const char *value, const int carNumber) override;

    // Dequeue an element from the front of the queue
    const Message dequeue() override;

    // Get the front element without removing it
    const Message head() const override;

    // Check if the queue is empty
    bool isEmpty() const override;

    // Get the size of the queue
    size_t size() const override;

    // Destructor to free memory
    ~DynamicLinkedQueue() override;

    bool isFull() const override;

    int echo() const override;

    const Message tail() const override;
};


#endif //STACK_DYNAMICLINKEDQUEUE_H
*/
