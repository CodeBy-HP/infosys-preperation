#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

class ShortestJobFirst {
public:
    static long long averageWaitingTime(std::vector<int>& bt) {
        std::sort(bt.begin(), bt.end());

        long long totalWaitTime = 0;
        long long currentWaitTime = 0;

        for (int b : bt) {
            totalWaitTime += currentWaitTime;
            currentWaitTime += b;
        }

        return totalWaitTime / bt.size(); // Integer division average
    }
};

int main() {
    std::vector<int> bt1 = {4, 3, 7, 1, 2};
    // Sorted: 1, 2, 3, 4, 7
    // Waits: 0, 1, 3, 6, 10 -> Total = 20
    // Avg = 20 / 5 = 4
    assert(ShortestJobFirst::averageWaitingTime(bt1) == 4);

    std::vector<int> bt2 = {1, 2, 3, 4};
    // Sorted: 1, 2, 3, 4
    // Waits: 0, 1, 3, 6 -> Total = 10
    // Avg = 10 / 4 = 2
    assert(ShortestJobFirst::averageWaitingTime(bt2) == 2);

    std::cout << "All Shortest Job First tests passed successfully!\n";
    return 0;
}

