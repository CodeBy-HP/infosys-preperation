#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

class Solution {
private:
    bool canAchieve(const std::vector<int>& stations, double maxDist, int k) {
        int count = 0;
        for (size_t i = 0; i < stations.size() - 1; ++i) {
            double gap = stations[i + 1] - stations[i];
            count += (int)(gap / maxDist);
            if (count > k) return false;
        }
        return count <= k;
    }

public:

// safer approach
    double minmaxGasDist(const std::vector<int>& stations, int k) {
        double left = 0.0;
        double right = stations.back() - stations.front();

        // 80 iterations achieves precision of (10^8 / 2^80) < 10^-16
        for (int iter = 0; iter < 80; ++iter) {
            double mid = left + (right - left) / 2.0;
            if (canAchieve(stations, mid, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return left;
    }
};

// case cause infinite loop in some questions
    double minmaxGasDist(vector<int>& stations, int k) {
            double low = 0.0, high = 0.0;
            for (int i = 1; i < stations.size(); i++) {
                high = max(high, (double)(stations[i] - stations[i - 1]));
            }

            double ans = high;

            while (high - low > 1e-7) {
                double mid = low + (high - low) / 2.0;

                if (canAchieve(stations, k, mid)) {
                    ans = mid;  // Valid -> try an even smaller max distance
                    high = mid;
                } else {
                    low = mid;  // Needs more than k stations -> increase max distance
                }
            }

            return ans;
        }

int main() {
    Solution sol;
    std::cout << std::fixed << std::setprecision(5);

    std::vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;
    std::cout << "minmaxGasDist: " << sol.minmaxGasDist(stations, k) << " (Expected: 0.50000)\n";

    return 0;
}
