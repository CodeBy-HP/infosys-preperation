#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

struct Item {
    int value;
    int weight;
};

class FractionalKnapsack {
public:
    static double fractionalKnapsack(int W, std::vector<Item>& items, int n) {
        (void)n;
        // Sort items by value/weight ratio descending
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            double r1 = static_cast<double>(a.value) / a.weight;
            double r2 = static_cast<double>(b.value) / b.weight;
            return r1 > r2;
        });

        double totalValue = 0.0;
        int currentWeight = 0;

        for (const auto& item : items) {
            if (currentWeight + item.weight <= W) {
                currentWeight += item.weight;
                totalValue += item.value;
            } else {
                int remain = W - currentWeight;
                totalValue += item.value * (static_cast<double>(remain) / item.weight);
                break;
            }
        }
        return totalValue;
    }
};

int main() {
    std::vector<Item> items1 = {{60, 10}, {100, 20}, {120, 30}};
    int W1 = 50;
    // item 1 (density 6.0): 10 wt, 60 val
    // item 2 (density 5.0): 20 wt, 100 val
    // item 3 (density 4.0): take 20/30 wt -> 80 val
    // Total = 60 + 100 + 80 = 240.0
    double res1 = FractionalKnapsack::fractionalKnapsack(W1, items1, 3);
    assert(std::abs(res1 - 240.0) < 1e-5);

    std::vector<Item> items2 = {{60, 10}, {100, 20}};
    int W2 = 50;
    // Can take both completely: 160.0
    double res2 = FractionalKnapsack::fractionalKnapsack(W2, items2, 2);
    assert(std::abs(res2 - 160.0) < 1e-5);

    std::cout << "All Fractional Knapsack tests passed successfully!\n";
    return 0;
}

