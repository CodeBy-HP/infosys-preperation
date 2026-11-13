#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Optimized_CyclicPrefixXOR {
private:
    // Helper function to calculate max score for a given array direction
    long long getMaxScore(const vector<int>& A) {
        int N = A.size();
        
        // Step 1: Create a prefix XOR array of size 2N to handle the cyclic nature seamlessly
        vector<int> pref(2 * N + 1, 0);
        for (int i = 0; i < 2 * N; i++) {
            pref[i + 1] = pref[i] ^ A[i % N];
        }

        // Step 2: Initialize bit counts for the first window of size N (pref[1] to pref[N])
        vector<int> bitCount(30, 0);
        for (int i = 1; i <= N; i++) {
            for (int b = 0; b < 30; b++) {
                if ((pref[i] >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }

        long long maxScore = 0;

        // Step 3: Slide the window across all N possible starting indices
        for (int S = 0; S < N; S++) {
            long long currentScore = 0;
            
            // Calculate the score for the current starting index S bit by bit
            for (int b = 0; b < 30; b++) {
                long long ones = bitCount[b];
                
                // If the base prefix (pref[S]) has this bit set, XORing will flip 1s to 0s and 0s to 1s.
                if ((pref[S] >> b) & 1) {
                    ones = N - ones; 
                }
                
                // Add the contribution of this bit to the total score
                currentScore += ones * (1LL << b);
            }
            maxScore = max(maxScore, currentScore);

            // Slide the window forward: remove the outgoing element, add the incoming element
            if (S + N + 1 <= 2 * N) {
                for (int b = 0; b < 30; b++) {
                    if ((pref[S + 1] >> b) & 1) bitCount[b]--;
                    if ((pref[S + N + 1] >> b) & 1) bitCount[b]++;
                }
            }
        }
        return maxScore;
    }

public:
    long long maximumCyclicPrefixXOR(vector<int>& arr) {
        // Find max score going Right (Clockwise)
        long long maxRight = getMaxScore(arr);

        // Reverse the array to simulate going Left (Counter-Clockwise)
        vector<int> revArr = arr;
        reverse(revArr.begin(), revArr.end());
        
        // Find max score going Left
        long long maxLeft = getMaxScore(revArr);

        return max(maxRight, maxLeft);
    }
};

class MaxCyclicPrefixXORSum {
private:
    long long evaluateDirection(const vector<int>& arr) {
        int n = arr.size();
        // Duplicate array to handle cyclic wrap-around
        vector<int> doubled(2 * n);
        for (int i = 0; i < 2 * n; i++) doubled[i] = arr[i % n];

        vector<int> prefixXor(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            prefixXor[i + 1] = prefixXor[i] ^ doubled[i];
        }

        long long maxVal = 0;

        // Try each starting index
        for (int start = 0; start < n; start++) {
            long long currentSum = 0;
            int basePrefix = prefixXor[start];

            for (int len = 1; len <= n; len++) {
                int currXor = prefixXor[start + len] ^ basePrefix;
                currentSum += currXor;
            }
            maxVal = max(maxVal, currentSum);
        }

        return maxVal;
    }

public:
    // =========================================================================
    // 1. Cyclic Prefix XOR Search
    // Time Complexity: O(N^2) / O(30 * N) bitwise
    // Space Complexity: O(N)
    // =========================================================================
    long long maxCyclicXORSum(vector<int>& arr) {
        long long resForward = evaluateDirection(arr);

        // Reverse to evaluate other direction
        reverse(arr.begin(), arr.end());
        long long resBackward = evaluateDirection(arr);

        return max(resForward, resBackward);
    }
};

int main() {
    MaxCyclicPrefixXORSum solver;

    vector<int> arr = {1, 2, 4, 5, 8};
    cout << "Max Cyclic Prefix XOR Sum: " << solver.maxCyclicXORSum(arr) << " (Expected: 53)\n";

    return 0;
}
