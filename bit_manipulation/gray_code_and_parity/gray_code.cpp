#include <iostream>
#include <vector>


#include <vector>

class BruteForceSolution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> path;
        std::vector<bool> visited(1 << n, false);
        
        // Start the graph traversal at node 0
        path.push_back(0);
        visited[0] = true;
        
        dfs(0, n, path, visited);
        return path;
    }

private:
    bool dfs(int current, int n, std::vector<int>& path, std::vector<bool>& visited) {
        // Base Case: If we have visited all 2^n nodes
        if (path.size() == (1 << n)) {
            // Check if the last node connects back to the first node (0)
            int diff = current ^ 0; 
            // A number with exactly 1 set bit is a power of 2: (diff & (diff - 1)) == 0
            if (diff > 0 && (diff & (diff - 1)) == 0) {
                return true; // We found a valid Hamiltonian path!
            }
            return false;
        }

        // Try visiting all 'n' possible valid neighbors
        for (int i = 0; i < n; ++i) {
            // Generate neighbor by flipping the i-th bit
            int nextNode = current ^ (1 << i); 

            if (!visited[nextNode]) {
                // 1. Choose
                visited[nextNode] = true;
                path.push_back(nextNode);

                // 2. Explore
                if (dfs(nextNode, n, path, visited)) {
                    return true; // Stop early once we find ONE valid path
                }

                // 3. Unchoose (Backtrack)
                visited[nextNode] = false;
                path.pop_back();
            }
        }
        
        return false;
    }
};

class Solution {
public:
    // Approach 1: Direct formula G(i) = i ^ (i >> 1)
    std::vector<int> grayCode(int n) {
        int total = 1 << n;
        std::vector<int> result;
        result.reserve(total);

        for (int i = 0; i < total; ++i) {
            result.push_back(i ^ (i >> 1));
        }

        return result;
    }

    // Gray code to binary inversion
    int grayToBinary(int g) {
        int b = 0;
        for (; g > 0; g >>= 1) {
            b ^= g;
        }
        return b;
    }

    // LeetCode 1238: Circular permutation starting at 'start'
    std::vector<int> circularPermutation(int n, int start) {
        int total = 1 << n;
        std::vector<int> result;
        result.reserve(total);

        for (int i = 0; i < total; ++i) {
            result.push_back(start ^ (i ^ (i >> 1)));
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> gc = sol.grayCode(2);
    std::cout << "grayCode(2): [ ";
    for (int x : gc) std::cout << x << " ";
    std::cout << "]\n(Expected: [ 0 1 3 2 ])\n";

    // Test Gray to Binary inversion
    std::cout << "grayToBinary(3): " << sol.grayToBinary(3) << " (Expected: 2)\n";

    // Circular permutation
    std::vector<int> cp = sol.circularPermutation(3, 2);
    std::cout << "circularPermutation(n=3, start=2): [ ";
    for (int x : cp) std::cout << x << " ";
    std::cout << "]\n(Starts at 2, each adjacent differs by 1 bit)\n";

    return 0;
}
