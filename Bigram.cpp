//
// Created by William on 2/9/2024.
//

#include "Bigram.h"

int Bigram::setFirst(char value) {
    first = value;
    validateBigram();
    return 1;
}

int Bigram::setSecond(char value) {
    second = value;
    validateBigram();
    return 1;
}

int Bigram::setBigram(const char *value) {
    first = value[0];
    second = value[1];
    return 1;
}

char Bigram::getFirst() const {
    return first;
}

char Bigram::getSecond() const {
    return second;
}
