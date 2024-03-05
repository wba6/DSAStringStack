//
// Created by brade on 3/5/2024.
//

#ifndef STACK_STATICCIRCLEQUEUE_H
#define STACK_STATICCIRCLEQUEUE_H

#include <cstddef>
#include "../Queue.h"

#define QueueSize 5

class StaticCircleQueue : public Queue {
public:
    StaticCircleQueue();

    void enqueue(int value) override;

    int dequeue() override;

    int peek() const override;

    bool isEmpty() const override;

    bool isFull() const override;

    size_t size() const override;

private:
    int rear = -1, front = -1;
    int arr[QueueSize];
};


#endif //STACK_STATICCIRCLEQUEUE_H
