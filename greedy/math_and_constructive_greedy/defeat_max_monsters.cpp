#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * Defeat the Maximum Number of Monsters (Greedy RPG Combat)
 * 
 * Problem:
 * Given initial HP and N monsters with (power, bonus).
 * Must have HP >= power to defeat monster; upon defeat HP += bonus.
 * Maximize number of monsters defeated.
 * 
 * Time Complexity: O(N log N)
 * Space Complexity: O(1) auxiliary
 */

struct Monster {
    long long power;
    long long bonus;
};

class Solution {
public:
    int defeatMaxMonsters(long long initial_hp, std::vector<Monster>& monsters) {
        // Step 1: Sort monsters ascending by power requirement
        std::sort(monsters.begin(), monsters.end(), [](const Monster& a, const Monster& b) {
            if (a.power != b.power) {
                return a.power < b.power;
            }
            return a.bonus > b.bonus; // Tie-breaker: larger bonus first
        });

        // Step 2: Greedily fight weakest monsters first
        long long current_hp = initial_hp;
        int defeated_count = 0;

        for (const auto& monster : monsters) {
            if (current_hp >= monster.power) {
                current_hp += monster.bonus;
                defeated_count++;
            } else {
                // Because monsters are sorted by power, no subsequent monster can be defeated
                break;
            }
        }

        return defeated_count;
    }
};

int main() {
    Solution solver;

    // Test 1: Standard case
    {
        long long initial_hp = 10;
        std::vector<Monster> monsters = {{12, 5}, {10, 2}, {15, 10}};
        int ans = solver.defeatMaxMonsters(initial_hp, monsters);
        std::cout << "Test 1: Expected = 3, Actual = " << ans << std::endl;
        assert(ans == 3);
    }

    // Test 2: Cannot defeat any monster
    {
        long long initial_hp = 5;
        std::vector<Monster> monsters = {{10, 100}, {20, 50}};
        int ans = solver.defeatMaxMonsters(initial_hp, monsters);
        std::cout << "Test 2: Expected = 0, Actual = " << ans << std::endl;
        assert(ans == 0);
    }

    // Test 3: Partial defeat before getting stuck
    {
        long long initial_hp = 10;
        std::vector<Monster> monsters = {{5, 2}, {12, 1}, {20, 50}};
        // Fight 1: HP = 10 >= 5 -> HP = 12
        // Fight 2: HP = 12 >= 12 -> HP = 13
        // Monster 3: HP = 13 < 20 -> Stop!
        // Defeated = 2
        int ans = solver.defeatMaxMonsters(initial_hp, monsters);
        std::cout << "Test 3: Expected = 2, Actual = " << ans << std::endl;
        assert(ans == 2);
    }

    std::cout << "All Defeat Monsters test cases passed successfully!" << std::endl;
    return 0;
}

