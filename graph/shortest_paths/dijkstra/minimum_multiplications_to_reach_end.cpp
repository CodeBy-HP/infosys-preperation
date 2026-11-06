#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class MinimumMultiplications {
public:
    static const int MOD = 100000;

    static int minimumMultiplications(const std::vector<int>& arr, int start, int end) {
        if (start == end) return 0;

        std::vector<int> dist(MOD, 1e9);
        dist[start] = 0;

        // Queue storing {steps, number}
        std::queue<std::pair<int, int>> q;
        q.push({0, start});

        while (!q.empty()) {
            auto [steps, curr] = q.front();
            q.pop();

            if (curr == end) return steps;

            for (int factor : arr) {
                int nextNum = (1LL * curr * factor) % MOD;
                if (steps + 1 < dist[nextNum]) {
                    dist[nextNum] = steps + 1;
                    if (nextNum == end) return steps + 1;
                    q.push({steps + 1, nextNum});
                }
            }
        }
        return -1;
    }
};

int main() {
    std::vector<int> a1 = {2, 5, 7};
    int start1 = 3, end1 = 30;
    // 3 * 2 = 6, 6 * 5 = 30 -> 2 steps
    assert(MinimumMultiplications::minimumMultiplications(a1, start1, end1) == 2);

    std::vector<int> a2 = {3, 4, 65};
    int start2 = 7, end2 = 66175;
    assert(MinimumMultiplications::minimumMultiplications(a2, start2, end2) == 4);

    std::cout << "All Minimum Multiplications to Reach End tests passed successfully!\n";
    return 0;
}

