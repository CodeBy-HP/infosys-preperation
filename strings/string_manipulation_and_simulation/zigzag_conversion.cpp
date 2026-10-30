#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ZigzagConversion {
public:
    // =========================================================================
    // 1. Row Bouncing Simulation
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    string convert(const string& s, int numRows) {
        if (numRows <= 1 || (int)s.size() <= numRows) return s;

        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;

            // Bounce at top and bottom boundaries
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currRow += goingDown ? 1 : -1;
        }

        string result = "";
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};

int main() {
    ZigzagConversion solver;

    cout << "\"PAYPALISHIRING\", numRows=3: " 
         << solver.convert("PAYPALISHIRING", 3) << " (Expected: PAHNAPLSIIGYIR)\n";

    cout << "\"PAYPALISHIRING\", numRows=4: " 
         << solver.convert("PAYPALISHIRING", 4) << " (Expected: PINALSIGYAHRPI)\n";

    return 0;
}
