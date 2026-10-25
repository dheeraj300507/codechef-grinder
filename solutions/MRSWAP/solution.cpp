#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (1-based indexing).
 * This means for each pair (A[i], A[2N + 1 - i]), we can choose which one 
 * goes into the first half (indices 1 to N) and which one goes into the 
 * second half (indices N+1 to 2N).
 * 
 * To maximize the sum of the first half, for each pair (A[i], A[2N + 1 - i]) 
 * where 1 <= i <= N, we should pick the maximum of the two values to be 
 * placed in the first half.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    // The pairs are (A[0], A[2N-1]), (A[1], A[2N-2]), ..., (A[N-1], A[N])
    for (int i = 0; i < N; ++i) {
        int left = A[i];
        int right = A[2 * N - 1 - i];
        max_sum += max(left, right);
    }

    cout << max_sum << "\n";
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