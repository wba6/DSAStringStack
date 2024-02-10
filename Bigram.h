#ifndef STACK_BIGRAM_H
#define STACK_BIGRAM_H


#include <ostream>
#include <ctype.h>

class Bigram {
private:
    /*
     * validates the bigram by moving all characters to left of spaces
     *
     * @param NA :
     * @return void :
     * */
    void validateBigram();

public:
    //const char constructor, will only use first two values
    Bigram(const char *value)
            : first(value[0]), second(value[1]) { validateBigram(); };

    //default constructor
    Bigram() = default;

    /*
     * sets the first character of the bigram
     *
     * @param char value : the value to set the first character too
     * @return int : returns 1 if successful
     * */
    int setFirst(char value);

    /*
     * sets the second character of the bigram
     *
     * @param char value : the value to set the second character too
     * @return int : returns 1 if successful
     * */
    int setSecond(char value);

    /*
     * sets the entire bigram to the first two values in parameter
     *
     * @param const char *value : the value to set the bigram too
     * @return int : returns 1 if successful
     * */
    int setBigram(const char *value);

    /*
     * gets the first character from the bigram
     *
     * @param NA :
     * @return char : returns the value of the first character of the bigram
     * */
    char getFirst() const;

    /*
     * gets the second character from the bigram
     *
     * @param NA :
     * @return char : returns the value of the second character of the bigram
     * */
    char getSecond() const;

    bool operator==(const Bigram &rhs) const {
        return first == rhs.first &&
               second == rhs.second;
    }

    bool operator==(const char *rhs) const {
        return first == rhs[0] &&
               second == rhs[1];
    }

    bool operator!=(const Bigram &rhs) const {
        return !(rhs == *this);
    }

    bool operator!=(const char *rhs) const {
        return !(*this == rhs);
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
