#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class MinimumDeletions {
public:
    // =========================================================================
    // 1. Hash Set Greedy Approach (Collision Resolution)
    // Time Complexity: O(N)
    // Space Complexity: O(1) (at most 26 elements in set)
    // =========================================================================
    int minDeletionsHashSet(const string& s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        unordered_set<int> seen;
        int deletions = 0;

        for (int count : freq) {
            if (count == 0) continue;

            while (count > 0 && seen.count(count)) {
                count--;
                deletions++;
            }

            if (count > 0) {
                seen.insert(count);
            }
        }

        return deletions;
    }

    // =========================================================================
    // 2. Sorting-Based Greedy Approach (No Hash Set, O(1) Space)
    // Sort frequencies descending; ensure freq[i] < freq[i - 1].
    // Time Complexity: O(N + 26 log 26) = O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int minDeletionsSorting(const string& s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        sort(freq.rbegin(), freq.rend()); // Sort descending

        int deletions = 0;
        int maxAllowed = freq[0];

        for (int count : freq) {
            if (count == 0) break;

            if (count > maxAllowed) {
                deletions += (count - maxAllowed);
            } else {
                maxAllowed = count;
            }

            // Next character can have at most maxAllowed - 1
            maxAllowed = max(0, maxAllowed - 1);
        }

        return deletions;
    }

    // =========================================================================
    // 3. Max-Heap Greedy Approach
    // Time Complexity: O(N + 26 log 26) = O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int minDeletionsMaxHeap(const string& s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        priority_queue<int> pq;
        for (int count : freq) {
            if (count > 0) pq.push(count);
        }

        int deletions = 0;

        while (pq.size() > 1) {
            int top = pq.top();
            pq.pop();

            if (top == pq.top()) {
                if (top > 1) {
                    pq.push(top - 1);
                }
                deletions++;
            }
        }

        return deletions;
    }
};

int main() {
    MinimumDeletions solver;

    string s1 = "aaabbbcc";
    cout << "Test 1 (\"aaabbbcc\"):\n";
    cout << "  Hash Set: " << solver.minDeletionsHashSet(s1) << "\n";
    cout << "  Sorting:  " << solver.minDeletionsSorting(s1) << "\n";
    cout << "  Max-Heap: " << solver.minDeletionsMaxHeap(s1) << " (Expected: 2)\n";

    string s2 = "ceabaacb";
    cout << "Test 2 (\"ceabaacb\"):\n";
    cout << "  Sorting:  " << solver.minDeletionsSorting(s2) << " (Expected: 2)\n";

    return 0;
}

