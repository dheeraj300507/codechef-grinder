#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 3 bricks with widths W1, W2, W3 and strength S.
 * We can reverse the stack at any time.
 * We want to minimize the number of hits.
 * 
 * Since there are only 3 bricks, we can either:
 * 1. Try to break them in the order W1, W2, W3.
 * 2. Try to break them in the reversed order W3, W2, W1.
 * 
 * For a given order (a, b, c):
 * - If a + b + c <= S, we need 1 hit.
 * - If a + b <= S, we need 1 hit for (a, b) and 1 hit for (c), total 2 hits.
 * - If a <= S, we need 1 hit for (a), and then we look at (b, c).
 *   - If b + c <= S, that's 1 more hit, total 2 hits.
 *   - If b + c > S, that's 2 more hits, total 3 hits.
 * 
 * Given the constraints (S <= 8, Wi <= 2), the sum of all bricks is at most 6.
 * Since S >= 1 and Wi >= 1, it is guaranteed that we can always break them.
 * The maximum number of hits is 3.
 */

int solve_hits(int S, int w1, int w2, int w3) {
    // Try to take as many as possible in one hit
    if (w1 + w2 + w3 <= S) {
        return 1;
    }
    // Try to take two in the first hit
    if (w1 + w2 <= S) {
        return 1 + 1; // 1 hit for (w1, w2), 1 hit for (w3)
    }
    // Otherwise, take one, then check remaining
    if (w2 + w3 <= S) {
        return 1 + 1; // 1 hit for (w1), 1 hit for (w2, w3)
    }
    // Worst case: 3 hits
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int S, W1, W2, W3;
        cin >> S >> W1 >> W2 >> W3;

        // Option 1: Order W1, W2, W3
        int hits1 = solve_hits(S, W1, W2, W3);
        
        // Option 2: Order W3, W2, W1 (Reversed)
        int hits2 = solve_hits(S, W3, W2, W1);

        cout << min(hits1, hits2) << "\n";
    }

    return 0;
}