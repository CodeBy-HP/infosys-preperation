#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Infosys OA Variant: Total Standing Passenger-Kilometers across arbitrary 10^9 coordinates
    long long totalStandingPassengerKm(const vector<vector<int>>& trips, int capacity) {
        vector<pair<long long, long long>> events;
        events.reserve(trips.size() * 2);

        for (const auto& t : trips) {
            events.push_back({t[1], t[0]});
            events.push_back({t[2], -t[0]});
        }
        sort(events.begin(), events.end());

        long long standingKm = 0;
        long long currLoad = 0;
        long long prevPos = events.empty() ? 0 : events[0].first;

        size_t i = 0;
        while (i < events.size()) {
            long long currPos = events[i].first;
            long long dist = currPos - prevPos;
            if (dist > 0 && currLoad > capacity) {
                standingKm += (currLoad - capacity) * dist;
            }

            while (i < events.size() && events[i].first == currPos) {
                currLoad += events[i].second;
                i++;
            }
            prevPos = currPos;
        }
        return standingKm;
    }

    // Standard LeetCode 1094: Check if car never exceeds capacity
    bool carPooling(const vector<vector<int>>& trips, int capacity) {
        return totalStandingPassengerKm(trips, capacity) == 0;
    }
};

int main() {
    Solution sol;
    assert(sol.totalStandingPassengerKm({{2, 1, 5}, {3, 3, 7}}, 4) == 2);
    assert(sol.totalStandingPassengerKm({{3, 0, 10}, {4, 2, 6}}, 5) == 8);
    assert(sol.carPooling({{2, 1, 5}, {3, 5, 7}}, 3) == true);
    assert(sol.carPooling({{2, 1, 5}, {3, 3, 7}}, 4) == false);
    cout << "49_car_pooling_standing_passenger_km passed all tests!\n";
    return 0;
}
