
#include "StaticCircleQueue.h"
#include <iostream>
#include <cstring>

int StaticCircleQueue::enqueue(const char *data, const int carNumber) {
    if(strlen(data) > 5){
        std::cerr << "string is too long" << std::endl;
        return -1;
    }
    if ((rear + 1) % QueueSize == front) {
        std::cerr << "The circular queue is full" << std::endl;
        echo();
        return -1;
    } else if (front == -1) {
        // First element insertion
        front = 0;
        rear = 0;
        arr[rear].setMessage(data);
        arr[rear].setCar(carNumber);
    } else {
        // Circularly increment the tail index
        rear = (rear + 1) % QueueSize;
        arr[rear].setMessage(data);
        arr[rear].setCar(carNumber);
    }
    return 1;
}

const Message StaticCircleQueue::dequeue() {
    if (rear == -1) {
        std::cerr << "The circular queue is empty" << std::endl;
        echo();
        return Message("",0);
    } else if (front == rear) {
        // Only one element in the queue
        Message& temp = arr[front];
        front = -1;
        rear = -1;
        return temp;
    } else {
        // Circularly increment the head index
        Message& temp = arr[front];
        front = (front + 1) % QueueSize;
        return temp;
    }
}

const Message StaticCircleQueue::head() const {
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

int StaticCircleQueue::echo() const {
    if(front == -1 || rear == -1){
        std::cout << "All positions empty" << std::endl;
        return -1;
    }
    if(front == rear){
        std::cout << "position " << front << ": " << arr[front] << "<---Rear and Head" << std::endl;
        return 1;
    }
    if(front != -1){
    std::cout << "position " << front << ": " << arr[front] << "<---Head" << std::endl;
    }
    for (int i = front+1; (i % QueueSize) != rear; ++i) {
        std::cout << "position " << i % QueueSize << ": " << arr[i % QueueSize] << "\n";
    }
    if(rear != -1) {
        std::cout << "position " << rear << ": " << arr[rear] << "<---Tail" << std::endl;
    }
    return 1;
}

const Message StaticCircleQueue::tail() const {
    return arr[rear];
}
