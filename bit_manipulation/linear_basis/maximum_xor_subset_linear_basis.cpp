#include <iostream>
#include <vector>
#include <cstdint>

class LinearBasis {
private:
    uint64_t basis[64];

public:
    LinearBasis() {
        for (int i = 0; i < 64; ++i) basis[i] = 0;
    }

    // Insert element into linear basis
    bool insert(uint64_t x) {
        for (int i = 63; i >= 0; --i) {
            if ((x >> i) & 1) {
                if (!basis[i]) {
                    basis[i] = x;
                    return true; // Successfully inserted
                }
                x ^= basis[i];
                if (x == 0) {
                return false; 
            }
            }
        }
        return false; // x is linearly dependent
    }

    // Find the maximum XOR sum obtainable from any subset
    uint64_t getMaxXor() {
        uint64_t maxXor = 0;
        for (int i = 63; i >= 0; --i) {
            if ((maxXor ^ basis[i]) > maxXor) {
                maxXor ^= basis[i];
            }
        }
        return maxXor;
    }

    // Check if target can be formed as XOR of a subset
    bool canForm(uint64_t target) {
        for (int i = 63; i >= 0; --i) {
            if ((target >> i) & 1) {
                if (!basis[i]) return false;
                target ^= basis[i];
            }
        }
        return target == 0;
    }
};

int main() {
    LinearBasis lb;
    std::vector<uint64_t> nums = {12, 15, 7, 2};

    for (uint64_t x : nums) {
        lb.insert(x);
    }

    std::cout << "Maximum Subset XOR of {12, 15, 7, 2}: " << lb.getMaxXor() 
              << " (Expected: 15)\n";

    std::vector<uint64_t> nums2 = {2, 4, 8};
    LinearBasis lb2;
    for (uint64_t x : nums2) lb2.insert(x);
    std::cout << "Maximum Subset XOR of {2, 4, 8}:        " << lb2.getMaxXor() 
              << " (Expected: 14)\n";
    std::cout << std::boolalpha;
    std::cout << "Can form 6 from {2, 4, 8}:              " << lb2.canForm(6) 
              << " (Expected: true, 2 ^ 4 = 6)\n";
    std::cout << "Can form 5 from {2, 4, 8}:              " << lb2.canForm(5) 
              << " (Expected: false)\n";

    return 0;
}
