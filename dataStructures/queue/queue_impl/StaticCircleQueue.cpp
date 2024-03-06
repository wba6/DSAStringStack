
#include "StaticCircleQueue.h"
#include <iostream>

void StaticCircleQueue::enqueue(const char *data) {
    if(strlen(data) > 5){
        std::cerr << "string is too long" << std::endl;
        return;
    }
    if ((rear + 1) % QueueSize == front) {
        std::cerr << "The circular queue is full" << std::endl;
    } else if (front == -1) {
        // First element insertion
        front = 0;
        rear = 0;
        arr[rear] = data;
    } else {
        // Circularly increment the tail index
        rear = (rear + 1) % QueueSize;
        arr[rear] = data;
    }
}

const char * StaticCircleQueue::dequeue() {
    if (rear == -1) {
        std::cerr << "The circular queue is empty" << std::endl;
        return " ";
    } else if (front == rear) {
        // Only one element in the queue
        const char* temp = arr[front];
        front = -1;
        rear = -1;
        return temp;
    } else {
        // Circularly increment the head index
        const char* temp = arr[front];
        front = (front + 1) % QueueSize;
        return temp;
    }
}

const char * StaticCircleQueue::head() const {
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
        std::cout << "position " << i % QueueSize << ": " << arr[i % QueueSize] << "\n";
    }
    std::cout << "position " << rear << ": " << arr[rear] << "\n";

}
