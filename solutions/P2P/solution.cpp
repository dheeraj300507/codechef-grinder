#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each index i, we choose either A[i] or B[i].
 * Let x_i be the chosen value (0 or 1).
 * Score = sum(x_i) for i = 1 to N.
 * We want Score to be odd.
 * 
 * Let's categorize indices into three types:
 * 1. Both A[i] and B[i] are '0': We must choose '0'. Contribution to score is 0.
 * 2. Both A[i] and B[i] are '1': We must choose '1'. Contribution to score is 1.
 * 3. One is '0' and one is '1': We can choose either '0' or '1'.
 * 
 * Let 'fixed_ones' be the count of indices where both A[i] and B[i] are '1'.
 * Let 'flexible' be the count of indices where one is '0' and one is '1'.
 * 
 * If 'flexible' > 0, we can toggle the parity of the score by choosing '0' or '1' 
 * at any of these flexible positions. Thus, if 'flexible' > 0, we can always 
 * achieve an odd score (if the current sum is even, flip one flexible choice to 
 * make it odd).
 * 
 * If 'flexible' == 0, the score is fixed at 'fixed_ones'. We just check if 
 * 'fixed_ones' is odd.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int fixed_ones = 0;
    int flexible = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] == '1' && B[i] == '1') {
            fixed_ones++;
        } else if (A[i] != B[i]) {
            flexible++;
        }
    }

    if (flexible > 0) {
        cout << "YES" << "\n";
    } else {
        if (fixed_ones % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}