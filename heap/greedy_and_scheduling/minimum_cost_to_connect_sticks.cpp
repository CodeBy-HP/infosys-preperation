#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class ConnectSticks {
public:
    static int connectSticks(const std::vector<int>& sticks) {
        if (sticks.size() <= 1) return 0;

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(sticks.begin(), sticks.end());
        int totalCost = 0;

        while (minHeap.size() > 1) {
            int first = minHeap.top();
            minHeap.pop();

            int second = minHeap.top();
            minHeap.pop();

            int cost = first + second;
            totalCost += cost;
            minHeap.push(cost);
        }
        return totalCost;
    }
};

int main() {
    std::vector<int> s1 = {2, 4, 3};
    // 2 + 3 = 5 (cost 5, sticks: 4, 5)
    // 4 + 5 = 9 (cost 9) -> Total = 5 + 9 = 14
    assert(ConnectSticks::connectSticks(s1) == 14);

    std::vector<int> s2 = {1, 8, 3, 5};
    // 1 + 3 = 4 (cost 4, sticks: 4, 5, 8)
    // 4 + 5 = 9 (cost 9, sticks: 8, 9)
    // 8 + 9 = 17 (cost 17) -> Total = 4 + 9 + 17 = 30
    assert(ConnectSticks::connectSticks(s2) == 30);

    std::vector<int> s3 = {5};
    assert(ConnectSticks::connectSticks(s3) == 0);

    std::cout << "All Minimum Cost to Connect Sticks tests passed successfully!\n";
    return 0;
}

