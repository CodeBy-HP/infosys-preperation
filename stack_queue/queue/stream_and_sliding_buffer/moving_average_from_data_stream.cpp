#include <iostream>
#include <queue>
#include <iomanip>

class MovingAverage {
private:
    std::queue<int> q;
    int maxSize;
    double runningSum;

public:
    MovingAverage(int size) : maxSize(size), runningSum(0.0) {}

    double next(int val) {
        if ((int)q.size() == maxSize) {
            runningSum -= q.front();
            q.pop();
        }
        q.push(val);
        runningSum += val;
        return runningSum / q.size();
    }
};

int main() {
    MovingAverage ma(3);
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "next(1):  " << ma.next(1) << " (Expected: 1.00000)\n";
    std::cout << "next(10): " << ma.next(10) << " (Expected: 5.50000)\n";
    std::cout << "next(3):  " << ma.next(3) << " (Expected: 4.66667)\n";
    std::cout << "next(5):  " << ma.next(5) << " (Expected: 6.00000)\n";

    return 0;
}
