#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class AsteroidCollision {
public:
    // =========================================================================
    // 1. Stack Simulation with Collision Battles
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    vector<int> asteroidCollision(const vector<int>& asteroids) {
        vector<int> st;

        for (int ast : asteroids) {
            bool exploded = false;

            // Collision only possible if stack top moves right (+) and incoming moves left (-)
            while (!st.empty() && st.back() > 0 && ast < 0) {
                if (st.back() < -ast) {
                    st.pop_back(); // Stack asteroid explodes, incoming keeps flying
                    continue;
                } else if (st.back() == -ast) {
                    st.pop_back(); // Both explode
                    exploded = true;
                    break;
                } else {
                    exploded = true; // Incoming asteroid explodes
                    break;
                }
            }

            if (!exploded) {
                st.push_back(ast);
            }
        }

        return st;
    }
};

int main() {
    AsteroidCollision solver;

    vector<int> a1 = {5, 10, -5};
    vector<int> res1 = solver.asteroidCollision(a1);
    cout << "Test 1 [5, 10, -5]: [ ";
    for (int v : res1) cout << v << " ";
    cout << "]\n(Expected: [ 5 10 ])\n";

    vector<int> a2 = {8, -8};
    vector<int> res2 = solver.asteroidCollision(a2);
    cout << "Test 2 [8, -8]:     [ ";
    for (int v : res2) cout << v << " ";
    cout << "]\n(Expected: [ ])\n";

    return 0;
}
