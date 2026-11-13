#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findNumOfValidWords(const std::vector<std::string>& words, 
                                        const std::vector<std::string>& puzzles) {
        // Step 1: Precompute frequency of word bitmasks
        std::unordered_map<int, int> wordMaskCount;
        for (const std::string& w : words) {
            int mask = 0;
            for (char c : w) {
                mask |= (1 << (c - 'a'));
            }
            // If word has more than 7 unique characters, it can never fit in any puzzle
            if (__builtin_popcount(mask) <= 7) {
                wordMaskCount[mask]++;
            }
        }

        std::vector<int> result;
        result.reserve(puzzles.size());

        // Step 2: For each puzzle, enumerate submasks of its last 6 characters
        for (const std::string& p : puzzles) {
            int firstBit = 1 << (p[0] - 'a');

            // restMask consists of characters 1 through 6
            int restMask = 0;
            for (size_t i = 1; i < p.size(); ++i) {
                restMask |= (1 << (p[i] - 'a'));
            }

            int validWords = 0;
            // Submask enumeration: sub goes through all subsets of restMask
            int sub = restMask;
            while (true) {
                int candidateMask = sub | firstBit;
                auto it = wordMaskCount.find(candidateMask);
                if (it != wordMaskCount.end()) {
                    validWords += it->second;
                }

                if (sub == 0) break;
                sub = (sub - 1) & restMask;
            }

            result.push_back(validWords);
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> words = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    std::vector<std::string> puzzles = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};

    std::vector<int> res = sol.findNumOfValidWords(words, puzzles);
    std::cout << "Valid words count: [ ";
    for (int x : res) std::cout << x << " ";
    std::cout << "]\n(Expected: [ 1 1 3 2 4 0 ])\n";

    return 0;
}
