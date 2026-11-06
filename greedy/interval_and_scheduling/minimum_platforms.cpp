#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class MinimumPlatforms {
public:
    static int findPlatform(std::vector<int>& arr, std::vector<int>& dep, int n) {
        std::sort(arr.begin(), arr.end());
        std::sort(dep.begin(), dep.end());

        int maxPlatforms = 0;
        int currentPlatforms = 0;

        int i = 0; // arrival pointer
        int j = 0; // departure pointer

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                currentPlatforms++;
                maxPlatforms = std::max(maxPlatforms, currentPlatforms);
                i++;
            } else {
                currentPlatforms--;
                j++;
            }
        }
        return maxPlatforms;
    }
};

int main() {
    std::vector<int> arr1 = {900, 940, 950, 1100, 1500, 1800};
    std::vector<int> dep1 = {910, 1200, 1120, 1130, 1900, 2000};
    assert(MinimumPlatforms::findPlatform(arr1, dep1, 6) == 3);

    std::vector<int> arr2 = {900, 1235, 1100};
    std::vector<int> dep2 = {1000, 1240, 1200};
    assert(MinimumPlatforms::findPlatform(arr2, dep2, 3) == 1);

    std::cout << "All Minimum Number of Platforms tests passed successfully!\n";
    return 0;
}

