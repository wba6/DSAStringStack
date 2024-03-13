
#ifndef STACK_STATICCIRCLEQUEUE_H
#define STACK_STATICCIRCLEQUEUE_H

#include <cstddef>
#include "../Queue.h"
#include "dataClass/Message.h"
#define QueueSize 6

class StaticCircleQueue : public Queue {
public:
    StaticCircleQueue();

    int enqueue(const char *value, const int carNumber) override;

    const Message dequeue() override;

    const Message head() const override;

    bool isEmpty() const override;

    bool isFull() const override;

    size_t size() const override;

    int echo() const override;

    const Message tail() const override;

private:
    int rear = -1, front = -1;
    Message arr[QueueSize];
};


#endif //STACK_STATICCIRCLEQUEUE_H
