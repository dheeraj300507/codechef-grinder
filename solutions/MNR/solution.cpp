#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are allowed to delete at most two elements from an array of size N.
 * To minimize (max - min), we should sort the array first.
 * Let the sorted array be A[0], A[1], ..., A[N-1].
 * After deleting two elements, we have three optimal strategies to minimize the range:
 * 1. Delete the two smallest elements: The new range is A[N-1] - A[2].
 * 2. Delete the two largest elements: The new range is A[N-3] - A[0].
 * 3. Delete the smallest and the largest element: The new range is A[N-2] - A[1].
 * 
 * Since we can delete "at most" two elements, these strategies cover all cases
 * because deleting fewer elements would result in a range at least as large as 
 * these options.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N <= 3) {
        cout << 0 << "\n";
        return;
    }

    sort(A.begin(), A.end());

    // Option 1: Delete two smallest
    long long opt1 = A[N - 1] - A[2];
    // Option 2: Delete two largest
    long long opt2 = A[N - 3] - A[0];
    // Option 3: Delete one smallest and one largest
    long long opt3 = A[N - 2] - A[1];

    long long ans = min({opt1, opt2, opt3});
    cout << ans << "\n";
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