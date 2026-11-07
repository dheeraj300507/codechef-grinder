#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the sum of all elements in the array A.
 * If we remove an element A[i], the new sum is S' = S - A[i].
 * We want S' to be even.
 * 
 * Case 1: S is even.
 * For S' = S - A[i] to be even, A[i] must be even.
 * So, if S is even, we need at least one even number in the array.
 * 
 * Case 2: S is odd.
 * For S' = S - A[i] to be even, A[i] must be odd.
 * So, if S is odd, we need at least one odd number in the array.
 * 
 * Simplified logic:
 * - If total sum is even, we need an even number to remove.
 * - If total sum is odd, we need an odd number to remove.
 * 
 * Actually, we can just iterate through all elements and check if (S - A[i]) % 2 == 0.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    bool found = false;
    for (int i = 0; i < N; ++i) {
        if ((total_sum - A[i]) % 2 == 0) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
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