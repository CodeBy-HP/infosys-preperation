#include <iostream>
#include <vector>

class MyCircularDeque {
private:
    std::vector<int> buffer;
    int head;
    int count;
    int capacity;

public:
    MyCircularDeque(int k) : buffer(k), head(0), count(0), capacity(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + capacity) % capacity;
        buffer[head] = value;
        ++count;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        int tail = (head + count) % capacity;
        buffer[tail] = value;
        ++count;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        --count;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        --count;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return buffer[head];
    }

    int getRear() {
        if (isEmpty()) return -1;
        int tail = (head + count - 1) % capacity;
        return buffer[tail];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

int main() {
    MyCircularDeque dq(3);
    std::cout << std::boolalpha;
    std::cout << "insertLast(1):  " << dq.insertLast(1) << " (Expected: true)\n";
    std::cout << "insertLast(2):  " << dq.insertLast(2) << " (Expected: true)\n";
    std::cout << "insertFront(3): " << dq.insertFront(3) << " (Expected: true)\n";
    std::cout << "insertFront(4): " << dq.insertFront(4) << " (Expected: false)\n";
    std::cout << "getRear():      " << dq.getRear() << " (Expected: 2)\n";
    std::cout << "isFull():       " << dq.isFull() << " (Expected: true)\n";
    std::cout << "deleteLast():   " << dq.deleteLast() << " (Expected: true)\n";
    std::cout << "insertFront(4): " << dq.insertFront(4) << " (Expected: true)\n";
    std::cout << "getFront():     " << dq.getFront() << " (Expected: 4)\n";

    return 0;
}
