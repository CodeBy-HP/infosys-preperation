#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cassert>

class AlienDictionary {
public:
    static std::string alienOrder(const std::vector<std::string>& words) {
        std::unordered_map<char, std::unordered_set<char>> adj;
        std::unordered_map<char, int> inDegree;

        // Initialize unique characters
        for (const auto& word : words) {
            for (char ch : word) {
                inDegree[ch] = 0;
            }
        }

        // Build directed edges from adjacent pairs
        for (size_t i = 0; i + 1 < words.size(); ++i) {
            const std::string& w1 = words[i];
            const std::string& w2 = words[i + 1];
            size_t minLen = std::min(w1.length(), w2.length());
            bool diffFound = false;

            for (size_t j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    diffFound = true;
                    break;
                }
            }

            // Illegal prefix case: w1 is longer and w2 is prefix of w1
            if (!diffFound && w1.length() > w2.length()) {
                return "";
            }
        }

        // Kahn's BFS
        std::queue<char> q;
        for (const auto& [ch, deg] : inDegree) {
            if (deg == 0) q.push(ch);
        }

        std::string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result.push_back(curr);

            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.length() == inDegree.size()) {
            return result;
        }
        return ""; // Cycle detected
    }
};

int main() {
    std::vector<std::string> words1 = {"wrt", "wrf", "er", "ett", "rftt"};
    std::string res1 = AlienDictionary::alienOrder(words1);
    assert(res1 == "wertf");

    std::vector<std::string> words2 = {"z", "x"};
    assert(AlienDictionary::alienOrder(words2) == "zx");

    std::vector<std::string> words3 = {"z", "x", "z"}; // Cycle
    assert(AlienDictionary::alienOrder(words3) == "");

    std::vector<std::string> words4 = {"abc", "ab"}; // Invalid prefix
    assert(AlienDictionary::alienOrder(words4) == "");

    std::cout << "All Alien Dictionary tests passed successfully!\n";
    return 0;
}

