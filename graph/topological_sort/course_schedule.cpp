#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // 1. Setup the Graph (Adjacency List) and Indegree array
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    
    for (auto& pre : prerequisites) {
        int course = pre[0];
        int prereq = pre[1];
        
        // prereq -> course (You must take prereq to unlock course)
        adj[prereq].push_back(course);
        indegree[course]++;
    }
    
    // 2. Find the "Outermost Layer of the Onion"
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    int completed_courses = 0;
    
    // 3. Peel the Onion
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        completed_courses++; // We successfully took this course!
        
        // Look at all the courses that depended on this one
        for (int next_course : adj[curr]) {
            indegree[next_course]--; // Remove the dependency
            
            // If it has no more prerequisites, it becomes part of the new outer layer
            if (indegree[next_course] == 0) {
                q.push(next_course);
            }
        }
    }
    
    // If we peeled every course, we win. If not, there was a cycle.
    return completed_courses == numCourses;
}