#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three problems with points A, B, and C.
 * All three problems must be solved.
 * A draw occurs if the sum of points for one player equals the sum of points for the other.
 * Let the total sum be S = A + B + C.
 * For a draw to occur, one player must have S/2 points.
 * This implies:
 * 1. S must be even (S % 2 == 0).
 * 2. It must be possible to form S/2 using a subset of {A, B, C}.
 * 
 * Since there are only three numbers, the possible subsets are:
 * - One number: A, B, or C
 * - Two numbers: A+B, A+C, or B+C
 * 
 * If any of these equal S/2, then the remaining numbers will also sum to S/2, resulting in a draw.
 * Mathematically, if A + B = C, then A + B = S/2.
 * Similarly, if A + C = B or B + C = A, a draw is possible.
 */

void solve() {
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return;

    // Check if any single problem is equal to the sum of the other two.
    // This is equivalent to checking if the largest number equals the sum of the other two.
    if ((a + b == c) || (a + c == b) || (b + c == a)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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