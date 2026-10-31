#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string a palindrome. A string is a palindrome if A[i] == A[N-1-i] for all i.
 * Let's look at pairs (A[i], A[N-1-i]).
 * If A[i] == A[N-1-i], they are already "balanced" and don't need to be changed.
 * If A[i] != A[N-1-i], they are "mismatched".
 * 
 * Let 'diff' be the number of indices i < N/2 such that A[i] != A[N-1-i].
 * Each operation can fix at most one mismatched pair.
 * Specifically, if we have a mismatch at (i, N-1-i), we can perform an operation
 * to make them both 0 or both 1.
 * 
 * If we have 'diff' mismatched pairs, we need at least 'diff' operations to make
 * those pairs equal.
 * 
 * Key insight:
 * If we have 'diff' mismatches, we can fix all of them in 'diff' operations.
 * If N is odd, the middle element doesn't affect the palindrome property.
 * If N is even, or if we have extra operations available, we can potentially 
 * change pairs that are already equal without breaking the palindrome property.
 * 
 * For this specific problem, the minimum number of operations to fix 'diff' 
 * mismatches is exactly ceil(diff / 2.0).
 * Why? Because one operation can fix two mismatched pairs if we choose indices 
 * carefully, or fix one pair if we choose indices within the same pair.
 * Actually, the logic simplifies to:
 * We need to fix all 'diff' pairs. Each operation can resolve 2 mismatches 
 * (by picking one index from one mismatched pair and one from another).
 * Thus, the answer is (diff + 1) / 2.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int diff = 0;
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            diff++;
        }
    }

    // Each operation can fix 2 mismatched pairs.
    // If diff is odd, we need (diff/2) + 1 operations.
    // If diff is even, we need (diff/2) operations.
    // This is equivalent to (diff + 1) / 2.
    cout << (diff + 1) / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}