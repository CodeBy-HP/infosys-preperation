#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class CourseScheduleII {
public:
    static std::vector<int> findOrder(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course); // prerequisite -> course
            inDegree[course]++;
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        std::vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int nextCourse : adj[curr]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        if (order.size() == static_cast<size_t>(numCourses)) {
            return order;
        }
        return {}; // Cycle prevented completing all courses
    }
};

int main() {
    int n1 = 2;
    std::vector<std::vector<int>> pre1 = {{1, 0}};
    auto res1 = CourseScheduleII::findOrder(n1, pre1);
    assert(res1 == std::vector<int>({0, 1}));

    int n2 = 4;
    std::vector<std::vector<int>> pre2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    auto res2 = CourseScheduleII::findOrder(n2, pre2);
    assert(res2.size() == 4);
    assert(res2[0] == 0 && res2[3] == 3);

    int n3 = 2;
    std::vector<std::vector<int>> pre3 = {{1, 0}, {0, 1}}; // Cycle
    auto res3 = CourseScheduleII::findOrder(n3, pre3);
    assert(res3.empty());

    std::cout << "All Course Schedule II tests passed successfully!\n";
    return 0;
}

