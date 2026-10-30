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

int main() {
    Solution sol;
    std::cout << std::fixed << std::setprecision(5);

    std::vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;
    std::cout << "minmaxGasDist: " << sol.minmaxGasDist(stations, k) << " (Expected: 0.50000)\n";

    return 0;
}
