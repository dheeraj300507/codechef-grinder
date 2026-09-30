#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two numbers A and B. We want to reach a state where A % 3 == 0 or B % 3 == 0.
 * Let a = A % 3 and b = B % 3.
 * Possible values for a and b are {0, 1, 2}.
 * 
 * Case 0: If a == 0 or b == 0, the answer is 0.
 * 
 * Case 1: If we perform one operation:
 * - A becomes |A-B|. Modulo 3, this is |a-b| % 3.
 * - B becomes |A-B|. Modulo 3, this is |a-b| % 3.
 * 
 * Let's check the possible pairs (a, b):
 * - (0, 0), (0, 1), (0, 2) -> 0 ops (already divisible)
 * - (1, 1) -> |1-1| = 0. 1 op.
 * - (2, 2) -> |2-2| = 0. 1 op.
 * - (1, 2) -> |1-2| = 1, |2-1| = 1. After 1 op, we get (1, 1) or (2, 2).
 *   From (1, 1) or (2, 2), we need 1 more op to get 0. Total 2 ops.
 * 
 * Summary:
 * - If a == 0 or b == 0: 0 operations.
 * - If a == b: 1 operation.
 * - If {a, b} == {1, 2}: 2 operations.
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    int a = A % 3;
    int b = B % 3;

    if (a == 0 || b == 0) {
        cout << 0 << "\n";
    } else if (a == b) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
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