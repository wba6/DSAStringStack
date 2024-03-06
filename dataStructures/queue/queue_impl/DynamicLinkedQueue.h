#ifndef STACK_DYNAMICLINKEDQUEUE_H
#define STACK_DYNAMICLINKEDQUEUE_H

#include "../Queue.h"

class DynamicLinkedQueue : public Queue {
private:
    struct Node {
        eastl::string data;
        Node *next;

        Node(eastl::string val) : data(val), next(nullptr) {}
    };

    Node *frontNode; // Pointer to the front of the queue
    Node *rearNode;  // Pointer to the rear of the queue
    size_t queueSize; // Size of the queue

public:
    DynamicLinkedQueue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

    // Enqueue an element to the back of the queue
    void enqueue(eastl::string value) override;

    // Dequeue an element from the front of the queue
    eastl::string dequeue() override;

    // Get the front element without removing it
    eastl::string head() const override;

    // Check if the queue is empty
    bool isEmpty() const override;

    // Get the size of the queue
    size_t size() const override;

    // Destructor to free memory
    ~DynamicLinkedQueue() override;

    bool isFull() const override;

    void echo() const override;
};


#endif //STACK_DYNAMICLINKEDQUEUE_H
