#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> findClosestElements(const std::vector<int>& arr, int k, int x) {
        int left = 0;
        int right = (int)arr.size() - k;

        // Binary search for the starting index of the k-length window
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1; // arr[mid + k] is closer than arr[mid]
            } else {
                right = mid;
            }
        }

        return std::vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {1, 2, 3, 4, 5};

    std::vector<int> res1 = sol.findClosestElements(arr, 4, 3);
    std::cout << "findClosestElements(k=4, x=3):  [ ";
    for (int v : res1) std::cout << v << " ";
    std::cout << "]\n(Expected: [ 1 2 3 4 ])\n";

    std::vector<int> res2 = sol.findClosestElements(arr, 4, -1);
    std::cout << "findClosestElements(k=4, x=-1): [ ";
    for (int v : res2) std::cout << v << " ";
    std::cout << "]\n(Expected: [ 1 2 3 4 ])\n";

    return 0;
}
