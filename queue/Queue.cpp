//
// Created by brade on 2/27/2024.
//

#include "Queue.h"
#include "queue_impl/DynamicLinkedQueue.h"
#include <iostream>

Queue *Queue::Create(queueType type) {
    switch (type) {
        case queueType::dynamicLinkedQueue:
            return new DynamicLinkedQueue;
    }
    std::cerr << "Type not implemented" << std::endl;
    return nullptr;
}
