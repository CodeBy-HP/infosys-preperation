#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int> people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = static_cast<int>(people.size()) - 1;
        int shuttles = 0;

        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            shuttles++;
        }
        return shuttles;
    }
};

int main() {
    Solution sol;
    assert(sol.numRescueBoats({1, 2}, 3) == 1);
    assert(sol.numRescueBoats({3, 2, 2, 1}, 3) == 3);
    assert(sol.numRescueBoats({3, 5, 3, 4}, 5) == 4);
    cout << "44_min_number_of_shuttles passed all tests!\n";
    return 0;
}
