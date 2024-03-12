
#include "StaticCircleQueue.h"
#include <iostream>

void StaticCircleQueue::enqueue(const char *data) {
    if(strlen(data) > 5){
        std::cerr << "string is too long" << std::endl;
        return;
    }
    if ((rear + 1) % QueueSize == front) {
        std::cerr << "The circular queue is full" << std::endl;
        echo();
        return;
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
        echo();
        return " ";
    } else if (front == rear) {
        // Only one element in the queue
        const char* temp = arr[front].getMessage();
        front = -1;
        rear = -1;
        return temp;
    } else {
        // Circularly increment the head index
        const char* temp = arr[front].getMessage();
        front = (front + 1) % QueueSize;
        return temp;
    }
}

const char * StaticCircleQueue::head() const {
    return arr[front].getMessage();
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
    if(front == -1 || rear == -1){
        std::cout << "All positions empty" << std::endl;
        return;
    }
    std::cout << "position " << front << ": " << arr[front] << "<---Head" << std::endl;
    for (int i = front+1; (i % QueueSize) != rear; ++i) {
        std::cout << "position " << i % QueueSize << ": " << arr[i % QueueSize] << "\n";
    }
    std::cout << "position " << rear << ": " << arr[rear] << "<---Tail" << std::endl;

}

const char *StaticCircleQueue::tail() const {
    return arr[rear].getMessage();
}
