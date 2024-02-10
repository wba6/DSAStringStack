#ifndef STACK_BIGRAM_H
#define STACK_BIGRAM_H


#include <ostream>

class Bigram {
private:
    void validateBigram() {
        if (first == ' ' && second != ' ') {
            first = second;
            second = ' ';
        }
    }

public:
    Bigram(const char *value)
            : first(value[0]), second(value[1]) {};

    Bigram() = default;

    int setFirst(char value);

    int setSecond(char value);

    int setBigram(const char *value);

    char getFirst() const;

    char getSecond() const;

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

    void operator=(const char *c) {
        setBigram(c);
        validateBigram();
    }

private:
    char first;
    char second;
};


#endif //STACK_BIGRAM_H
