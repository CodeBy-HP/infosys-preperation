#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class InsertInterval {
public:
    static std::vector<std::vector<int>> insert(const std::vector<std::vector<int>>& intervals,
                                                std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        int n = intervals.size();
        int i = 0;

        // Phase 1: Add all intervals ending before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Phase 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // Phase 3: Add all remaining intervals starting after newInterval ends
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main() {
    std::vector<std::vector<int>> intervals1 = {{1, 3}, {6, 9}};
    std::vector<int> new1 = {2, 5};
    auto res1 = InsertInterval::insert(intervals1, new1);
    std::vector<std::vector<int>> exp1 = {{1, 5}, {6, 9}};
    assert(res1 == exp1);

    std::vector<std::vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    std::vector<int> new2 = {4, 8};
    auto res2 = InsertInterval::insert(intervals2, new2);
    std::vector<std::vector<int>> exp2 = {{1, 2}, {3, 10}, {12, 16}};
    assert(res2 == exp2);

    std::vector<std::vector<int>> intervals3 = {};
    std::vector<int> new3 = {5, 7};
    auto res3 = InsertInterval::insert(intervals3, new3);
    std::vector<std::vector<int>> exp3 = {{5, 7}};
    assert(res3 == exp3);

    std::cout << "All Insert Interval tests passed successfully!\n";
    return 0;
}

