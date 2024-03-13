
#ifndef DATASTRUCTURES_MESSAGE_H
#define DATASTRUCTURES_MESSAGE_H

#include <ostream>

class Message {
public:
    Message(const char* data){
        setMessage(data);
    }

    Message() = default;

    bool operator<(const Message &rhs) const {
        return message < rhs.message;
    }

    bool operator>(const Message &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Message &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Message &rhs) const {
        return !(*this < rhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const Message &message) {
        os << message.message;
        return os;
    }

    [[nodiscard]] const char *getMessage() const {
        return message;
    }

    void setMessage(const char* data){
        for (int i = 0; data[i] != '\0' && i < 5; ++i) {
            message[i] = data[i];
        }
    }

    bool operator==(const Message &rhs) const {
        return message == rhs.message;
    }

    bool operator!=(const Message &rhs) const {
        return !(rhs == *this);
    }


private:
    char message[5]{""};
};

#endif //DATASTRUCTURES_MESSAGE_H
