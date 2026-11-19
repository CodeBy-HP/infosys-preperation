#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// =============================================================================
// 1. Monotonic Stack storing (price, span) pairs
// Amortized Time Complexity: O(1) per next() call, O(N) total for N calls
// Space Complexity: O(N) worst-case (strictly decreasing prices)
// =============================================================================
class StockSpannerOptimal {
private:
    // Pair: {price, span}
    stack<pair<int, int>> st;

public:
    StockSpannerOptimal() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

// =============================================================================
// 2. Monotonic Stack storing Day Indices (Previous Greater Element approach)
// Amortized Time Complexity: O(1) per call
// Space Complexity: O(N)
// =============================================================================
class StockSpannerIndexBased {
private:
    vector<int> prices;
    stack<int> st; // stores indices of previous greater elements
    int currentDay;

public:
    StockSpannerIndexBased() : currentDay(0) {}

    int next(int price) {
        prices.push_back(price);

        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        int span = st.empty() ? (currentDay + 1) : (currentDay - st.top());
        st.push(currentDay);
        currentDay++;
        return span;
    }
};

// =============================================================================
// 3. Brute Force Online Scanner (Historical vector scan)
// Time Complexity: O(N) per next() call, O(N^2) total
// Space Complexity: O(N) to store history
// =============================================================================
class StockSpannerBruteForce {
private:
    vector<int> history;

public:
    StockSpannerBruteForce() {}

    int next(int price) {
        history.push_back(price);
        int span = 0;
        for (int i = static_cast<int>(history.size()) - 1; i >= 0; i--) {
            if (history[i] <= price) {
                span++;
            } else {
                break;
            }
        }
        return span;
    }
};

int main() {
    StockSpannerOptimal spanner1;
    StockSpannerIndexBased spanner2;
    StockSpannerBruteForce spanner3;

    vector<int> quotes = {100, 80, 60, 70, 60, 75, 85};
    vector<int> expected = {1, 1, 1, 2, 1, 4, 6};

    cout << "Testing Stock Spanner with quotes: [100, 80, 60, 70, 60, 75, 85]\n";
    for (size_t i = 0; i < quotes.size(); i++) {
        int ans1 = spanner1.next(quotes[i]);
        int ans2 = spanner2.next(quotes[i]);
        int ans3 = spanner3.next(quotes[i]);
        cout << "Day " << i << " (Price " << quotes[i] << ") -> Optimal: " << ans1 
             << " | Index-Stack: " << ans2 
             << " | Brute: " << ans3 
             << " | Expected: " << expected[i] << "\n";
    }

    return 0;
}

