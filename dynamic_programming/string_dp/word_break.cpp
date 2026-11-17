#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <cassert>

class WordBreak {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        // Convert array to Hash Set for O(1) lookups
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        // dp[i] represents whether s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        
        // Base case: The empty string is always a valid starting point
        dp[0] = true;
        
        // i represents the end of the substring we are checking
        for (int i = 1; i <= n; i++) {
            
            // j represents the start of the substring. 
            // We look backward to see if we can jump from a previous safe pad
            for (int j = 0; j < i; j++) {
                
                // ACTION EDGE: If the pad at 'j' is safe AND the word between 'j' and 'i' is valid
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true; // Mark pad 'i' as safe!
                    break;        // We only need ONE valid way to reach 'i', so we stop looking
                }
                
            }
        }
        
        // If the final pad is safe, the entire string can be broken
        return dp[n];
    }
};

int main() {
    assert(WordBreak::wordBreak("leetcode", {"leet", "code"}) == true);
    assert(WordBreak::wordBreak("applepenapple", {"apple", "pen"}) == true);
    assert(WordBreak::wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) == false);

    std::cout << "All Word Break tests passed successfully!\n";
    return 0;
}

