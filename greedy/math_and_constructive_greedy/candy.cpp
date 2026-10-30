#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Candy {
public:
    // =========================================================================
    // 1. Two-Pass Greedy Approach (Left-to-Right + Right-to-Left)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int candyTwoPass(const vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;

        vector<int> candies(n, 1);

        // Pass 1: Left to Right (respect left neighbors)
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Pass 2: Right to Left (respect right neighbors with max merge)
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }

    // =========================================================================
    // 2. Single-Pass Slope / Peak-and-Valley Greedy Approach
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int candySlopeOnePass(const vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;

        int totalCandies = 1;
        int up = 0;
        int down = 0;
        int peak = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                // Ascending slope
                up++;
                down = 0;
                peak = up;
                totalCandies += 1 + up;
            } else if (ratings[i] == ratings[i - 1]) {
                // Flat surface
                up = 0;
                down = 0;
                peak = 0;
                totalCandies += 1;
            } else {
                // Descending slope
                down++;
                up = 0;
                totalCandies += 1 + down - (peak >= down ? 1 : 0);
            }
        }

        return totalCandies;
    }
};

int main() {
    Candy solver;

    vector<int> ratings1 = {1, 0, 2};
    cout << "Test 1 [1, 0, 2]:\n";
    cout << "  Two-Pass:  " << solver.candyTwoPass(ratings1) << "\n";
    cout << "  One-Pass:  " << solver.candySlopeOnePass(ratings1) << " (Expected: 5)\n";

    vector<int> ratings2 = {1, 2, 2};
    cout << "Test 2 [1, 2, 2]:\n";
    cout << "  Two-Pass:  " << solver.candyTwoPass(ratings2) << "\n";
    cout << "  One-Pass:  " << solver.candySlopeOnePass(ratings2) << " (Expected: 4)\n";

    return 0;
}

