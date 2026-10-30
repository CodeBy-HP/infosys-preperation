#include <iostream>
#include <vector>
#include <bitset>

class SubmaskEnumerator {
public:
    std::vector<int> getSubmasks(int mask) {
        std::vector<int> submasks;
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
            submasks.push_back(sub);
        }
        submasks.push_back(0); // 0 is always a submask
        return submasks;
    }
};

int main() {
    SubmaskEnumerator enumerator;
    int mask = 13; // binary 1101 (bits 0, 2, 3)

    std::vector<int> submasks = enumerator.getSubmasks(mask);
    std::cout << "Submasks of 13 (binary 1101):\n";
    for (int s : submasks) {
        std::cout << "Decimal: " << s << "\tBinary: " << std::bitset<4>(s) << "\n";
    }
    std::cout << "Total submasks: " << submasks.size() << " (Expected: 8)\n";

    return 0;
}
