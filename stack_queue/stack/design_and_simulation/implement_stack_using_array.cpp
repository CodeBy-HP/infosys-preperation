#include <iostream>
#include <vector>

using namespace std;

// =============================================================================
// 1. Fixed-Capacity Array Implementation
// =============================================================================
class FixedArrayStack {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    FixedArrayStack(int cap = 1000) : capacity(cap), topIndex(-1) {
        arr = new int[capacity];
    }

    ~FixedArrayStack() {
        delete[] arr;
    }

    bool push(int x) {
        if (topIndex >= capacity - 1) {
            cerr << "Stack Overflow!\n";
            return false;
        }
        arr[++topIndex] = x;
        return true;
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Underflow sentinel
        }
        return arr[topIndex--];
    }

    int top() const {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }
};

// =============================================================================
// 2. Dynamic Resizing Array Implementation (Amortized O(1) Push)
// =============================================================================
class DynamicArrayStack {
private:
    int* arr;
    int capacity;
    int topIndex;

    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i <= topIndex; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArrayStack(int initCap = 4) : capacity(initCap), topIndex(-1) {
        arr = new int[capacity];
    }

    ~DynamicArrayStack() {
        delete[] arr;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            resize(capacity * 2);
        }
        arr[++topIndex] = x;
    }

    int pop() {
        if (isEmpty()) return -1;
        int val = arr[topIndex--];
        if (topIndex > 0 && topIndex == capacity / 4) {
            resize(capacity / 2);
        }
        return val;
    }

    int top() const {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    cout << "=== Fixed Array Stack ===\n";
    FixedArrayStack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << " (Expected: 30)\n";
    cout << "Pop: " << st.pop() << " (Expected: 30)\n";
    cout << "Size: " << st.size() << " (Expected: 2)\n";

    cout << "\n=== Dynamic Array Stack ===\n";
    DynamicArrayStack dynSt;
    for (int i = 1; i <= 10; i++) dynSt.push(i * 5);
    cout << "Dynamic Top: " << dynSt.top() << " (Expected: 50)\n";
    cout << "Dynamic Size: " << dynSt.size() << " (Expected: 10)\n";

    return 0;
}

