#include <vector>

using namespace std;

bool dfs(int course, vector<vector<int>>& adj, vector<int>& state) {
    // If we step on a node currently in our active dive, we found a cycle!
    if (state[course] == 1) return false;
    
    // If we step on a node we've already fully verified in the past, it's safe.
    if (state[course] == 2) return true;
    
    // Mark as currently VISITING (added to our active path)
    state[course] = 1;
    
    // Dive deeper into all the courses that depend on this one
    for (int next_course : adj[course]) {
        if (!dfs(next_course, adj, state)) {
            return false; // A cycle was detected somewhere deeper
        }
    }
    
    // We survived the dive! Mark this course as fully VISITED (Safe)
    state[course] = 2;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> state(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = safe
    
    // Build the graph (prereq -> course)
    for (auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);
    }
    
    // We must try starting a DFS from every unvisited course, 
    // because the graph might be disconnected into separate chunks.
    for (int i = 0; i < numCourses; i++) {
        if (state[i] == 0) { 
            if (!dfs(i, adj, state)) {
                return false; // If any DFS dive finds a cycle, we fail.
            }
        }
    }
    
    return true;
}