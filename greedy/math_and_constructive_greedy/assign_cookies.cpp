#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class AssignCookies {
public:
    static int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;

        while (child < static_cast<int>(g.size()) && cookie < static_cast<int>(s.size())) {
            if (s[cookie] >= g[child]) {
                child++; // Satisfied child!
            }
            cookie++;    // Move to next cookie regardless
        }
        return child;
    }
};

int main() {
    std::vector<int> g1 = {1, 2, 3};
    std::vector<int> s1 = {1, 1};
    assert(AssignCookies::findContentChildren(g1, s1) == 1);

    std::vector<int> g2 = {1, 2};
    std::vector<int> s2 = {1, 2, 3};
    assert(AssignCookies::findContentChildren(g2, s2) == 2);

    std::vector<int> g3 = {3, 4, 5};
    std::vector<int> s3 = {1, 2};
    assert(AssignCookies::findContentChildren(g3, s3) == 0);

    std::cout << "All Assign Cookies tests passed successfully!\n";
    return 0;
}

