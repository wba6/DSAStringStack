
#ifndef STACK_STATICCIRCLEQUEUE_H
#define STACK_STATICCIRCLEQUEUE_H

#include <cstddef>
#include "../Queue.h"

#define QueueSize 5

class StaticCircleQueue : public Queue {
public:
    StaticCircleQueue();

    void enqueue(eastl::string value) override;

    eastl::string dequeue() override;

    eastl::string head() const override;

    bool isEmpty() const override;

    bool isFull() const override;

    size_t size() const override;

    void echo() const override;

private:
    int rear = -1, front = -1;
    eastl::string arr[QueueSize];
};


#endif //STACK_STATICCIRCLEQUEUE_H
