#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

struct Meeting {
    int start;
    int end;
    int id;
};

class NMeetingsInOneRoom {
public:
    static int maxMeetings(const std::vector<int>& start, const std::vector<int>& end, int n) {
        std::vector<Meeting> meetings(n);
        for (int i = 0; i < n; ++i) {
            meetings[i] = {start[i], end[i], i + 1};
        }

        // Sort by end time ascending
        std::sort(meetings.begin(), meetings.end(), [](const Meeting& a, const Meeting& b) {
            if (a.end != b.end) return a.end < b.end;
            return a.id < b.id;
        });

        int count = 1;
        int lastEndTime = meetings[0].end;

        for (int i = 1; i < n; ++i) {
            if (meetings[i].start > lastEndTime) {
                count++;
                lastEndTime = meetings[i].end;
            }
        }
        return count;
    }
};

int main() {
    std::vector<int> s1 = {1, 3, 0, 5, 8, 5};
    std::vector<int> e1 = {2, 4, 6, 7, 9, 9};
    // Pick (1,2), (3,4), (5,7), (8,9) -> 4 meetings
    assert(NMeetingsInOneRoom::maxMeetings(s1, e1, 6) == 4);

    std::vector<int> s2 = {10, 12, 20};
    std::vector<int> e2 = {20, 25, 30};
    assert(NMeetingsInOneRoom::maxMeetings(s2, e2, 3) == 1);

    std::cout << "All N Meetings in One Room tests passed successfully!\n";
    return 0;
}

