
#include "StaticCircleQueue.h"
#include <iostream>

void StaticCircleQueue::enqueue(eastl::string data) {
    if ((front == 0 && rear == QueueSize - 1) ||
        ((rear + 1) % QueueSize == front)) {
        std::cerr << "\nQueue Overflow\n";
        return;
    } else if (front == -1) {
        front = 0;
        rear = 0;
        arr[rear] = data;
    } else if (rear == QueueSize - 1 && front != 0) {
        rear = 0;
        arr[rear] = data;
    } else {
        rear++;
        arr[rear] = data;
    }
}

eastl::string StaticCircleQueue::dequeue() {
    if (front == -1) {
        std::cerr << "\nQueue underflow\n";
        return " ";
    }

    eastl::string data = arr[front];
    arr[front] = -1;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == QueueSize - 1)
        front = 0;
    else
        front++;

    return data;
}

eastl::string StaticCircleQueue::head() const {
    return arr[front];
}

bool StaticCircleQueue::isEmpty() const {
    return front == -1;
}

bool StaticCircleQueue::isFull() const {
    return size() == QueueSize;
}

size_t StaticCircleQueue::size() const {
    return std::abs(front - rear)+1;
}

StaticCircleQueue::StaticCircleQueue() {}

void StaticCircleQueue::echo() const {
    for (int i = front; (i % QueueSize) != rear; ++i) {
        std::cout << "position " << i % QueueSize << ": " << arr[i % QueueSize].data() << "\n";
    }
    std::cout << "position " << rear << ": " << arr[rear].data() << "\n";

}
