#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int kthElement(std::vector<int>& arr1, std::vector<int>& arr2, int k) {
        if (arr1.size() > arr2.size()) {
            return kthElement(arr2, arr1, k);
        }

        int m = arr1.size();
        int n = arr2.size();

        int left = std::max(0, k - n);
        int right = std::min(k, m);

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = k - i;

            int maxLeft1 = (i == 0) ? INT_MIN : arr1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : arr1[i];

            int maxLeft2 = (j == 0) ? INT_MIN : arr2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : arr2[j];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                return std::max(maxLeft1, maxLeft2);
            } else if (maxLeft1 > minRight2) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> a = {2, 3, 6, 7, 9};
    std::vector<int> b = {1, 4, 8, 10};
    int k = 5;

    std::cout << "5th element of [2,3,6,7,9] & [1,4,8,10]: " << sol.kthElement(a, b, k) 
              << " (Expected: 6)\n";

    return 0;
}
