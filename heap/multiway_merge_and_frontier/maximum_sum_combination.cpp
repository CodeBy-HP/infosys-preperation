#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>

class MaxSumCombinations {
public:
    static std::vector<int> maxCombinations(std::vector<int>& A, std::vector<int>& B, int C) {
        int n = A.size();
        std::sort(A.begin(), A.end(), std::greater<int>());
        std::sort(B.begin(), B.end(), std::greater<int>());

        // Max-heap storing tuple: {sum, i, j}
        std::priority_queue<std::tuple<int, int, int>> maxHeap;
        std::set<std::pair<int, int>> visited;

        maxHeap.push({A[0] + B[0], 0, 0});
        visited.insert({0, 0});

        std::vector<int> result;

        while (static_cast<int>(result.size()) < C && !maxHeap.empty()) {
            auto [sum, i, j] = maxHeap.top();
            maxHeap.pop();

            result.push_back(sum);

            // Candidate 1: (i + 1, j)
            if (i + 1 < n && !visited.count({i + 1, j})) {
                maxHeap.push({A[i + 1] + B[j], i + 1, j});
                visited.insert({i + 1, j});
            }

            // Candidate 2: (i, j + 1)
            if (j + 1 < n && !visited.count({i, j + 1})) {
                maxHeap.push({A[i] + B[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> A1 = {3, 2};
    std::vector<int> B1 = {1, 4};
    int C1 = 2;
    // A sorted desc: 3, 2
    // B sorted desc: 4, 1
    // Combinations: 3+4=7, 2+4=6, 3+1=4, 2+1=3
    // Top 2: [7, 6]
    auto res1 = MaxSumCombinations::maxCombinations(A1, B1, C1);
    assert(res1 == std::vector<int>({7, 6}));

    std::vector<int> A2 = {1, 4, 2, 3};
    std::vector<int> B2 = {2, 5, 1, 6};
    int C2 = 4;
    auto res2 = MaxSumCombinations::maxCombinations(A2, B2, C2);
    // Top sums: 4+6=10, 3+6=9, 4+5=9, 2+6=8
    assert(res2 == std::vector<int>({10, 9, 9, 8}));

    std::cout << "All Maximum Sum Combination tests passed successfully!\n";
    return 0;
}

