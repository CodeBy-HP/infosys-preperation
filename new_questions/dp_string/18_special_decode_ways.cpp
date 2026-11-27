#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long MOD = 1e9 + 7;

    int ways1(char c) {
        if (c == '*') return 9;
        if (c == '0') return 0;
        return 1;
    }

    int ways2(char c0, char c1) {
        if (c0 == '*' && c1 == '*') return 15; // 11..19 (9) + 21..26 (6)
        if (c0 == '*') return (c1 <= '6') ? 2 : 1;
        if (c1 == '*') {
            if (c0 == '1') return 9;
            if (c0 == '2') return 6;
            return 0;
        }
        int num = (c0 - '0') * 10 + (c1 - '0');
        return (num >= 10 && num <= 26) ? 1 : 0;
    }

public:
    int numDecodings(const string& s) {
        int n = s.size();
        if (n == 0) return 0;

        long long prev2 = 1;
        long long prev1 = ways1(s[0]);

        for (int i = 2; i <= n; i++) {
            long long curr = (ways1(s[i - 1]) * prev1 + ways2(s[i - 2], s[i - 1]) * prev2) % MOD;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    assert(sol.numDecodings("226") == 3);
    assert(sol.numDecodings("*") == 9);
    assert(sol.numDecodings("1*") == 18);
    assert(sol.numDecodings("2*") == 15);
    assert(sol.numDecodings("**") == 96);
    cout << "18_special_decode_ways passed all tests!\n";
    return 0;
}
