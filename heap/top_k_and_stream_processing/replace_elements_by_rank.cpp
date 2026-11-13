#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cassert>

class ReplaceByRank {
public:
    static std::vector<int> replaceWithRank(const std::vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        // Min-heap storing {value, index}
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> minHeap;

        for (int i = 0; i < n; ++i) {
            minHeap.push({arr[i], i});
        }

        std::vector<int> result(n);
        int currentRank = 0;
        long long prevVal = LLONG_MIN;

        while (!minHeap.empty()) {
            auto [val, idx] = minHeap.top();
            minHeap.pop();

            if (val != prevVal) {
                currentRank++;
                prevVal = val;
            }
            result[idx] = currentRank;
        }
        return result;
    }
};

int main() {
    std::vector<int> a1 = {20, 15, 26, 2, 98, 6};
    auto res1 = ReplaceByRank::replaceWithRank(a1);
    std::vector<int> exp1 = {4, 3, 5, 1, 6, 2};
    assert(res1 == exp1);

    std::vector<int> a2 = {1, 2, 5, 2, 1, 60};
    auto res2 = ReplaceByRank::replaceWithRank(a2);
    std::vector<int> exp2 = {1, 2, 3, 2, 1, 4};
    assert(res2 == exp2);

    std::cout << "All Replace Elements by Their Rank tests passed successfully!\n";
    return 0;
}

