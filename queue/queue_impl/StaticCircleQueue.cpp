//
// Created by brade on 3/5/2024.
//

#include "StaticCircleQueue.h"
#include <iostream>

void StaticCircleQueue::enqueue(int data) {
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

int StaticCircleQueue::dequeue() {
    if (front == -1) {
        std::cerr << "\nQueue underflow\n";
        return -1;
    }

    int data = arr[front];
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

int StaticCircleQueue::peek() const {
    return arr[front];
}

bool StaticCircleQueue::isEmpty() const {
    return false;
}

bool StaticCircleQueue::isFull() const {
    return false;
}

size_t StaticCircleQueue::size() const {
    return std::abs(front - rear);
}

StaticCircleQueue::StaticCircleQueue() {}
