#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class BooleanEvaluation {
public:
    static const int MOD = 1e9 + 7;

    static int countWays(const std::string& exp) {
        int n = exp.length();
        // Operands are at even indices 0, 2, 4, ...
        // Operators are at odd indices 1, 3, 5, ...
        std::vector<std::vector<long long>> dpT(n, std::vector<long long>(n, 0));
        std::vector<std::vector<long long>> dpF(n, std::vector<long long>(n, 0));

        // Base case: individual operands
        for (int i = 0; i < n; i += 2) {
            dpT[i][i] = (exp[i] == 'T') ? 1 : 0;
            dpF[i][i] = (exp[i] == 'F') ? 1 : 0;
        }

        // Interval DP over operand span
        for (int len = 3; len <= n; len += 2) {
            for (int i = 0; i <= n - len; i += 2) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k += 2) {
                    char op = exp[k];
                    long long LT = dpT[i][k - 1];
                    long long LF = dpF[i][k - 1];
                    long long RT = dpT[k + 1][j];
                    long long RF = dpF[k + 1][j];

                    if (op == '&') {
                        dpT[i][j] = (dpT[i][j] + (LT * RT) % MOD) % MOD;
                        dpF[i][j] = (dpF[i][j] + (LT * RF) % MOD + (LF * RT) % MOD + (LF * RF) % MOD) % MOD;
                    } else if (op == '|') {
                        dpT[i][j] = (dpT[i][j] + (LT * RT) % MOD + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
                        dpF[i][j] = (dpF[i][j] + (LF * RF) % MOD) % MOD;
                    } else if (op == '^') {
                        dpT[i][j] = (dpT[i][j] + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
                        dpF[i][j] = (dpF[i][j] + (LT * RT) % MOD + (LF * RF) % MOD) % MOD;
                    }
                }
            }
        }
        return dpT[0][n - 1];
    }
};

int main() {
    assert(BooleanEvaluation::countWays("T|T&F^T") == 4);
    assert(BooleanEvaluation::countWays("T^F|F") == 2);
    assert(BooleanEvaluation::countWays("F") == 0);
    assert(BooleanEvaluation::countWays("T") == 1);

    std::cout << "All Boolean Evaluation tests passed successfully!\n";
    return 0;
}

