
#ifndef DATASTRUCTURES_MESSAGE_H
#define DATASTRUCTURES_MESSAGE_H

#include <ostream>

class Message {
public:
    Message(const char* data, int carNumber){
        setMessage(data);
        car = carNumber;
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
        os << "sending \"" << message.message << "\" to car number: " << message.car;
        return os;
    }

    [[nodiscard]] const char *getMessage() const {
        return message;
    }

    [[nodiscard]] const char *getCarMessage() const {
        return message + car;
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

    void setCar(int car) {
        Message::car = car;
    }

    int getCar() const {
        return car;
    }


private:
    char message[6]{""};
    int car = {0};
};

#endif //DATASTRUCTURES_MESSAGE_H
