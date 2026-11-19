#include <iostream>
#include <vector>

using namespace std;

// =============================================================================
// 1. Fixed-Size Circular Array Queue
// =============================================================================
class CircularArrayQueue {
private:
    int* arr;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;

public:
    CircularArrayQueue(int cap = 1000) : capacity(cap), frontIdx(0), rearIdx(0), count(0) {
        arr = new int[capacity];
    }

    ~CircularArrayQueue() {
        delete[] arr;
    }

    bool enqueue(int x) {
        if (isFull()) {
            cerr << "Queue Overflow!\n";
            return false;
        }
        arr[rearIdx] = x;
        rearIdx = (rearIdx + 1) % capacity;
        count++;
        return true;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        count--;
        return val;
    }

    int front() const {
        if (isEmpty()) return -1;
        return arr[frontIdx];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    int size() const {
        return count;
    }
};

// =============================================================================
// 2. Dynamic Resizing Circular Queue (Unwraps Ring Buffer on Resize)
// =============================================================================
class DynamicCircularQueue {
private:
    int* arr;
    int capacity;
    int frontIdx;
    int count;

    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(frontIdx + i) % capacity];
        }
        delete[] arr;
        arr = newArr;
        frontIdx = 0;
        capacity = newCapacity;
    }

public:
    DynamicCircularQueue(int initCap = 4) : capacity(initCap), frontIdx(0), count(0) {
        arr = new int[capacity];
    }

    ~DynamicCircularQueue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (count == capacity) {
            resize(capacity * 2);
        }
        int rearIdx = (frontIdx + count) % capacity;
        arr[rearIdx] = x;
        count++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        count--;
        if (count > 0 && count == capacity / 4) {
            resize(capacity / 2);
        }
        return val;
    }

    int front() const {
        if (isEmpty()) return -1;
        return arr[frontIdx];
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }
};

int main() {
    cout << "=== Fixed Circular Array Queue ===\n";
    CircularArrayQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << " (Expected: 10)\n";
    cout << "Dequeue: " << q.dequeue() << " (Expected: 10)\n";
    cout << "New Front: " << q.front() << " (Expected: 20)\n";

    cout << "\n=== Dynamic Circular Queue ===\n";
    DynamicCircularQueue dynQ;
    for (int i = 1; i <= 10; i++) dynQ.enqueue(i * 10);
    cout << "Dynamic Front: " << dynQ.front() << " (Expected: 10)\n";
    cout << "Dynamic Dequeue: " << dynQ.dequeue() << " (Expected: 10)\n";
    cout << "Dynamic Size: " << dynQ.size() << " (Expected: 9)\n";

    return 0;
}

