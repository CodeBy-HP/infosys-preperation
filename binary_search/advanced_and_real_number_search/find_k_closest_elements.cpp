#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int low = 0, high = n - k - 1;
        int ans = n - k; // Default: rightmost possible window [n - k .. n - 1]

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Compare left edge arr[mid] vs next right element arr[mid + k]
            // Signed diff (no abs) handles duplicates safely
            if (x - arr[mid] > arr[mid + k] - x) {
                low = mid + 1;  // Shifting right gets closer to x
            } else {
                ans = mid;      // mid beats or ties mid + 1 -> save and search left
                high = mid - 1;
            }
        }

        return vector<int>(arr.begin() + ans, arr.begin() + ans + k);
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
