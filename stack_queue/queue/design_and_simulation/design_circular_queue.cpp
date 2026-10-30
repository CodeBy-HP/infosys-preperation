#include <iostream>
#include <vector>

class MyCircularQueue {
private:
    std::vector<int> buffer;
    int head;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) : buffer(k), head(0), count(0), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        int tail = (head + count) % capacity;
        buffer[tail] = value;
        ++count;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        --count;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return buffer[head];
    }

    int Rear() {
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
    MyCircularQueue q(3);
    std::cout << std::boolalpha;
    std::cout << "enQueue(1): " << q.enQueue(1) << " (Expected: true)\n";
    std::cout << "enQueue(2): " << q.enQueue(2) << " (Expected: true)\n";
    std::cout << "enQueue(3): " << q.enQueue(3) << " (Expected: true)\n";
    std::cout << "enQueue(4): " << q.enQueue(4) << " (Expected: false)\n";
    std::cout << "Rear():     " << q.Rear() << " (Expected: 3)\n";
    std::cout << "isFull():   " << q.isFull() << " (Expected: true)\n";
    std::cout << "deQueue():  " << q.deQueue() << " (Expected: true)\n";
    std::cout << "enQueue(4): " << q.enQueue(4) << " (Expected: true)\n";
    std::cout << "Rear():     " << q.Rear() << " (Expected: 4)\n";

    return 0;
}
