#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int bruteForce(){
        // calculate prefix sum

        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int k = i + 1; k < n; ++k) {
                for (int j = i + 1; j <= k; ++j) {
                    // Check if prefixXor for 'a' == prefixXor for 'b'
                    if (a == b) {
                        count++;
                    }
                }
            }
        }
        return count;

        // O(N^3)
    }

    int anotherOptimsedN2(){
        // dont even need prefix sum here
        int n = arr.size();
        int count = 0;
        
        // We only need two loops!
        for (int i = 0; i < n - 1; ++i) {
            int currentXor = arr[i]; // Start the chunk
            
            for (int k = i + 1; k < n; ++k) {
                currentXor ^= arr[k]; // Add next element to the chunk
                
                // If the whole chunk from i to k equals 0...
                if (currentXor == 0) {
                    // ...we can drop 'j' anywhere in between!
                    count += (k - i);
                }
            }
        }
        
        return count;
    }


    // Approach 1: O(N^2) using prefix XOR array
    int countTripletsN2(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] ^ arr[i];
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                // If prefix XOR from i to k is 0, any j in between is valid
                if ((pref[k + 1] ^ pref[i]) == 0) {
                    count += (k - i);
                }
            }
        }
        return count;
    }

    // Approach 2: O(N) one-pass using hash map of frequency and index sum
    int countTriplets(vector<int>& arr) {
        unordered_map<int, int> countMap;
        unordered_map<int, int> indexSumMap;
        
        // Base case: A prefix XOR of 0 naturally exists at the very beginning (index 0).
        countMap[0] = 1;
        indexSumMap[0] = 0;
        
        int count = 0;
        int currentXor = 0;
        
        for (int k = 0; k < arr.size(); ++k) {
            currentXor ^= arr[k];
            
            // If we have seen this XOR value before, apply the formula!
            // Formula: (Count * k) - (Sum of previous indices)
            if (countMap.count(currentXor)) {
                count += (countMap[currentXor] * k) - indexSumMap[currentXor];
            }
            
            // Record this current XOR for future 'k's to use as their 'i'
            countMap[currentXor]++;
            indexSumMap[currentXor] += (k + 1);
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {2, 3, 1, 6, 7};
    std::cout << "Test 1 [2,3,1,6,7] (N^2):     " << sol.countTripletsN2(arr1) << " (Expected: 4)\n";
    std::cout << "Test 1 [2,3,1,6,7] (Optimal): " << sol.countTripletsOptimal(arr1) << " (Expected: 4)\n";

    std::vector<int> arr2 = {1, 1, 1, 1, 1};
    std::cout << "Test 2 [1,1,1,1,1] (Optimal): " << sol.countTripletsOptimal(arr2) << " (Expected: 10)\n";

    return 0;
}
