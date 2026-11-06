#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to reach a state where P[i] != i+1 for all i (using 0-based indexing).
 * If P[i] == i+1, we have a "fixed point".
 * We can swap adjacent elements. Swapping P[i] and P[i+1] can fix at most two 
 * fixed points if they are adjacent.
 * 
 * Strategy:
 * Iterate through the array. If we find a fixed point at index i (P[i] == i+1),
 * we must perform an operation to move it. To minimize operations, we should 
 * greedily pair adjacent fixed points.
 * 
 * If P[i] == i+1 and P[i+1] == i+2, we can swap them in one operation to fix both.
 * If P[i] == i+1 but P[i+1] != i+2, we swap P[i] with P[i+1] to fix P[i].
 * This greedy approach works because each operation can resolve at most 2 fixed points.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int operations = 0;
    for (int i = 0; i < n; ++i) {
        // Check if current position is a fixed point
        if (p[i] == i + 1) {
            // If there is a next element and it is also a fixed point,
            // we can fix both with one swap.
            if (i + 1 < n && p[i + 1] == i + 2) {
                operations++;
                i++; // Skip the next element as it's now fixed
            } else {
                // Otherwise, just swap with the next element (or previous if at end)
                // to fix this one.
                operations++;
            }
        }
    }
    cout << operations << "\n";
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