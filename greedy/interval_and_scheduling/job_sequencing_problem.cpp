#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

struct Job {
    int id;
    int dead;
    int profit;
};

class JobSequencing {
private:
    class DSU {
        std::vector<int> parent;
    public:
        DSU(int n) {
            parent.resize(n + 1);
            std::iota(parent.begin(), parent.end(), 0);
        }
        int findParent(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findParent(parent[node]); // Path compression
        }
        void markSlotUsed(int slot) {
            parent[slot] = findParent(slot - 1);
        }
    };

public:
    // Approach 1: Linear Slot Search - O(N log N + N * D_max) Time
    static std::pair<int, int> JobSchedulingLinear(std::vector<Job>& jobs, int n) {
        std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        int maxDeadline = 0;
        for (const auto& j : jobs) {
            maxDeadline = std::max(maxDeadline, j.dead);
        }

        std::vector<int> slot(maxDeadline + 1, -1);
        int countJobs = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; ++i) {
            for (int t = jobs[i].dead; t > 0; --t) {
                if (slot[t] == -1) {
                    slot[t] = jobs[i].id;
                    countJobs++;
                    totalProfit += jobs[i].profit;
                    break;
                }
            }
        }
        return {countJobs, totalProfit};
    }

    // Approach 2: DSU Fast Slot Finding - O(N log N + N * alpha(D_max)) Time
    static std::pair<int, int> JobSchedulingDSU(std::vector<Job>& jobs, int n) {
        std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        int maxDeadline = 0;
        for (const auto& j : jobs) {
            maxDeadline = std::max(maxDeadline, j.dead);
        }

        DSU dsu(maxDeadline);
        int countJobs = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; ++i) {
            int availableSlot = dsu.findParent(jobs[i].dead);
            if (availableSlot > 0) {
                countJobs++;
                totalProfit += jobs[i].profit;
                dsu.markSlotUsed(availableSlot);
            }
        }
        return {countJobs, totalProfit};
    }
};

int main() {
    std::vector<Job> jobs1 = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };
    auto res1_lin = JobSequencing::JobSchedulingLinear(jobs1, 4);
    auto res1_dsu = JobSequencing::JobSchedulingDSU(jobs1, 4);
    assert(res1_lin == std::make_pair(2, 60)); // job 3 (40) at slot 1, job 1 (20) at slot 4
    assert(res1_dsu == std::make_pair(2, 60));

    std::vector<Job> jobs2 = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };
    auto res2_lin = JobSequencing::JobSchedulingLinear(jobs2, 5);
    auto res2_dsu = JobSequencing::JobSchedulingDSU(jobs2, 5);
    assert(res2_lin == std::make_pair(3, 142)); // 100 + 27 + 15 = 142
    assert(res2_dsu == std::make_pair(3, 142));

    std::cout << "All Job Sequencing Problem tests passed successfully!\n";
    return 0;
}

