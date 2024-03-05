//
// Created by brade on 2/27/2024.
//

#include "Queue.h"
#include "queue_impl/DynamicLinkedQueue.h"
#include "queue_impl/StaticCircleQueue.h"
#include <iostream>

Queue *Queue::Create(queueType type) {
    switch (type) {
        case queueType::dynamicLinkedQueue:
            return new DynamicLinkedQueue;
        case queueType::staticCircleQueue:
            return new StaticCircleQueue;
    }
    std::cerr << "Type not implemented" << std::endl;
    return nullptr;
}
