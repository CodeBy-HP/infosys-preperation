#include <iostream>
#include <vector>
#include <cassert>

class LemonadeChange {
public:
    static bool lemonadeChange(const std::vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else { // bill == 20, need 15 change
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> b1 = {5, 5, 5, 10, 20};
    assert(LemonadeChange::lemonadeChange(b1) == true);

    std::vector<int> b2 = {5, 5, 10, 10, 20};
    assert(LemonadeChange::lemonadeChange(b2) == false);

    std::vector<int> b3 = {5, 5, 5, 20};
    assert(LemonadeChange::lemonadeChange(b3) == true);

    std::cout << "All Lemonade Change tests passed successfully!\n";
    return 0;
}

