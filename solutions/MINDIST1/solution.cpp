#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows reversing any substring of length 3.
 * Reversing a substring of length 3 (e.g., abc -> cba) preserves the parity of the indices 
 * of the 1s. Specifically, if we have a 1 at index i, after reversing a substring 
 * containing i, the new index i' will satisfy i' % 2 == i % 2.
 * 
 * Let the positions of 1s be p1, p2, ..., pk.
 * If there exists at least one pair of 1s such that their indices have different parity 
 * (i.e., one is at an even index and one is at an odd index), we can always bring them 
 * to be adjacent (distance 1).
 * 
 * If all 1s are at indices of the same parity (all even or all odd), the distance 
 * between any two 1s will always be even. The minimum distance will be 2.
 * 
 * Exception: If the string contains at least one '1' at an even index and at least one '1' 
 * at an odd index, the answer is 1. Otherwise, the answer is 2.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool has_even = false;
    bool has_odd = false;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (i % 2 == 0) {
                has_even = true;
            } else {
                has_odd = true;
            }
        }
    }

    if (has_even && has_odd) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}