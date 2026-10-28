#include <iostream>
#include <string>

using namespace std;

int solve(const string& s) {
    int n = s.length();
    int freqL = 0;
    int freqR = 0;
    int count = 0;
    bool can_gain_split = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            freqL++;
        } else {
            freqR++;
        }

        int diff = freqL - freqR;

        if (diff == 0) {
            count++;
        }

        if (!can_gain_split && i < n - 1) {
            if (diff == 2 && s[i] == 'L' && s[i+1] == 'R') {
                can_gain_split = true;
            } else if (diff == -2 && s[i] == 'R' && s[i+1] == 'L') {
                can_gain_split = true;
            }
        }
    }

    return can_gain_split ? count + 1 : count;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    string s;
    cin >> s;

    cout << solve(s) << "\n";

    return 0;
}