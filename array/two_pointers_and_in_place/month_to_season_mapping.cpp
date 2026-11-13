#include <iostream>
#include <string>
#include <cassert>

/**
 * Month to Season Mapping
 * 
 * Maps month integer (1 - 12) to season with guard-clause boundary checks.
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

class Solution {
public:
    std::string getSeason(int month) {
        // Step 1: Guard clause for invalid ranges
        if (month < 1 || month > 12) {
            return "Invalid month";
        }

        // Step 2: Seasonal intervals
        if (month >= 3 && month <= 5) {
            return "Season: Spring";
        }
        if (month >= 6 && month <= 8) {
            return "Season: Summer";
        }
        if (month >= 9 && month <= 11) {
            return "Season: Autumn";
        }
        
        // Months 12, 1, and 2 fall through to Winter
        return "Season: Winter";
    }
};

int main() {
    Solution solver;

    // Test cases
    assert(solver.getSeason(4) == "Season: Spring");
    assert(solver.getSeason(7) == "Season: Summer");
    assert(solver.getSeason(10) == "Season: Autumn");
    assert(solver.getSeason(12) == "Season: Winter");
    assert(solver.getSeason(1) == "Season: Winter");
    assert(solver.getSeason(2) == "Season: Winter");
    assert(solver.getSeason(0) == "Invalid month");
    assert(solver.getSeason(13) == "Invalid month");

    std::cout << "All Month to Season Mapping test cases passed successfully!" << std::endl;
    return 0;
}

