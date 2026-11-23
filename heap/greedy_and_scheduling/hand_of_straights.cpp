#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cassert>

class HandOfStraights {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for (int card : hand) freq[card]++;

        // Min-Heap of {cardValue, count}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& [val, cnt] : freq) {
            pq.push({val, cnt});
        }

        int m = n / groupSize;
        while (m--) {
            vector<pair<int, int>> temp;
            int prev = -1;

            for (int i = 0; i < groupSize; i++) {
                if (pq.empty()) return false;

                auto [val, cnt] = pq.top();
                pq.pop();

                if (i > 0 && val != prev + 1) return false;
                prev = val;

                if (cnt > 1) {
                    temp.push_back({val, cnt - 1});
                }
            }

            for (auto& p : temp) {
                pq.push(p);
            }
        }

        return pq.empty();
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

