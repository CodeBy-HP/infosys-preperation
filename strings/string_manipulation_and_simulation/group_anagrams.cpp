#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class GroupAnagrams {
public:
    // =========================================================================
    // 1. Sorted String Hash Key
    // Time Complexity: O(N * K log K) where N = strs.size(), K = max string length
    // Space Complexity: O(N * K)
    // =========================================================================
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& pair : groups) {
            result.push_back(move(pair.second));
        }

        return result;
    }
};

int main() {
    GroupAnagrams solver;

    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groups = solver.groupAnagrams(words);

    cout << "Anagram Groups:\n";
    for (const auto& group : groups) {
        cout << "  [ ";
        for (const string& w : group) cout << "\"" << w << "\" ";
        cout << "]\n";
    }

    return 0;
}
