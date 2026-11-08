#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has a set of N integers and Berta has a set of M integers.
 * We need to find the number of elements in Alice's set that are also present in Berta's set.
 * Since all numbers within a single collection are distinct, we simply need to count
 * how many elements from Alice's collection exist in Berta's collection.
 * 
 * Constraints:
 * Ai, Bi <= 10^6.
 * N, M <= 10^5.
 * Time Limit: 2.5s.
 * 
 * Approach:
 * We can use a boolean array or a hash set to store Berta's numbers for O(1) average lookup.
 * Given the constraint Ai, Bi <= 10^6, a boolean array of size 1,000,001 is efficient
 * in terms of both time and memory.
 */

const int MAX_VAL = 1000000;
bool berta_has[MAX_VAL + 1];

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> alice(n);
    for (int i = 0; i < n; ++i) {
        cin >> alice[i];
    }

    // Reset the boolean array for Berta's numbers
    // Note: Since we only need to clear indices that were set, 
    // we can keep track of them or just use a fresh array/vector.
    // Given the constraints and time limit, a simple memset or vector reset is fine.
    vector<int> berta(m);
    for (int i = 0; i < m; ++i) {
        cin >> berta[i];
        berta_has[berta[i]] = true;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (berta_has[alice[i]]) {
            count++;
        }
    }

    cout << count << "\n";

    // Cleanup for next test case
    for (int i = 0; i < m; ++i) {
        berta_has[berta[i]] = false;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}