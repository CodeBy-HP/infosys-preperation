#include <iostream>
#include <queue>

class RecentCounter {
private:
    std::queue<int> q;

public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

int main() {
    RecentCounter rc;
    std::cout << "ping(1):    " << rc.ping(1) << " (Expected: 1)\n";
    std::cout << "ping(100):  " << rc.ping(100) << " (Expected: 2)\n";
    std::cout << "ping(3001): " << rc.ping(3001) << " (Expected: 3)\n";
    std::cout << "ping(3002): " << rc.ping(3002) << " (Expected: 3)\n";

    return 0;
}
