//
// Created by William on 2/9/2024.
//

#ifndef STACK_BIGRAM_H
#define STACK_BIGRAM_H


#include <ostream>

class Bigram {
private:
    void validateBigram(){
        if(first == ' ' && second != ' '){
            first = second;
            second = ' ';
        }
    }
public:
    Bigram(const char *value)
    :first(value[0]), second(value[1]){};
    Bigram() = default;

    int setFirst(char value){first = value; validateBigram(); return 1;};
    int setSecond(char value){first = value; validateBigram(); return 1;};
    int setBigram(char *value){first = value[0]; second = value [1]; return 1;};
    char getFirst() const {return first;};
    char getSecond() const {return second;}

    bool operator==(const Bigram &rhs) const {
        return first == rhs.first &&
               second == rhs.second;
    }

    bool operator!=(const Bigram &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Bigram &bigram) {
        os << bigram.first << bigram.second;
        return os;
    };

    void operator=(const char *c)
    {
        first = c[0];
        second = c[1];
        validateBigram();
    }

private:
    char first;
    char second;
};


#endif //STACK_BIGRAM_H
