#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class WildcardMatching {
public:
    static bool isMatch(const std::string& s, const std::string& p) {
        int n = s.length();
        int m = p.length();

        std::vector<bool> prev(m + 1, false);
        prev[0] = true;

        // Base case for empty string matching pattern prefix
        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] == '*') {
                prev[j] = prev[j - 1];
            }
        }

        for (int i = 1; i <= n; ++i) {
            std::vector<bool> curr(m + 1, false);
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main() {
    assert(WildcardMatching::isMatch("aa", "a") == false);
    assert(WildcardMatching::isMatch("aa", "*") == true);
    assert(WildcardMatching::isMatch("cb", "?a") == false);
    assert(WildcardMatching::isMatch("adceb", "*a*b") == true);
    assert(WildcardMatching::isMatch("acdcb", "a*c?b") == false);

    std::cout << "All Wildcard Matching tests passed successfully!\n";
    return 0;
}

