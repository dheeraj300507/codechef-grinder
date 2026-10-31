#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string a palindrome. A string is a palindrome if A[i] == A[N-1-i] for all i.
 * Let's look at pairs (A[i], A[N-1-i]).
 * If A[i] == A[N-1-i], they are already "balanced".
 * If A[i] != A[N-1-i], they are "unbalanced".
 * 
 * Let 'm' be the number of pairs (i, N-1-i) such that A[i] != A[N-1-i].
 * For each such pair, we need at least one operation to make them equal.
 * One operation on an unbalanced pair can fix it.
 * If we have 'm' such pairs, we need at least ceil(m/2) operations.
 * 
 * Specifically:
 * - If m == 0, the string is already a palindrome. Answer: 0.
 * - If m > 0, each operation can fix two unbalanced pairs (by picking one index from each pair)
 *   or fix one unbalanced pair (by picking one index from the pair and one from a balanced pair).
 * - The minimum number of operations to fix 'm' mismatches is (m + 1) / 2.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int mismatches = 0;
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            mismatches++;
        }
    }

    // If there are no mismatches, it's already a palindrome.
    // Otherwise, we need (mismatches + 1) / 2 operations.
    cout << (mismatches + 1) / 2 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}