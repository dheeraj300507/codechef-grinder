#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A player i (1-indexed) mishears or whispers wrongly if the message they 
 * received (A[i]) is different from the message the previous player (i-1) 
 * whispered (A[i-1]), OR if the message they whispered (A[i]) is different 
 * from the message the next player (i+1) received (A[i+1]).
 * 
 * Essentially, if A[i] != A[i+1], then either player i whispered it wrong 
 * or player i+1 misheard it. Both players are involved in the discrepancy.
 * We need to count all unique indices i such that A[i] != A[i+1] or A[i] != A[i-1].
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Use a boolean array to mark players involved in a discrepancy
    vector<bool> is_wrong(n, false);
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != a[i + 1]) {
            is_wrong[i] = true;
            is_wrong[i + 1] = true;
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (is_wrong[i]) {
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}