#ifndef QUEUE_H
#define QUEUE_H

#include <queue>

template <typename T>
class Queue {
private:
    std::queue<T> data;

public:
    void enqueue(const T& value) {
        data.push(value);
    }

    T dequeue() {
        T value = data.front();
        data.pop();
        return value;
    }

    T front() const {
        return data.front();
    }

    bool isEmpty() const {
        return data.empty();
    }

    size_t getSize() const {
        return data.size();
    }
};

#endif // QUEUE_H
