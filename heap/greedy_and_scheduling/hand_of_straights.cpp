#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cassert>

class HandOfStraights {
public:
    static bool isNStraightHand(const std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        std::unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (const auto& [card, _] : count) {
            minHeap.push(card);
        }

        while (!minHeap.empty()) {
            int start = minHeap.top();
            minHeap.pop();

            if (count[start] == 0) continue;

            int freq = count[start];
            for (int i = 0; i < groupSize; ++i) {
                int card = start + i;
                if (count[card] < freq) {
                    return false;
                }
                count[card] -= freq;
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> h1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    assert(HandOfStraights::isNStraightHand(h1, 3) == true);

    std::vector<int> h2 = {1, 2, 3, 4, 5};
    assert(HandOfStraights::isNStraightHand(h2, 4) == false);

    std::cout << "All Hand of Straights tests passed successfully!\n";
    return 0;
}

