#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to satisfy: A[0] <= A[1] >= A[2] <= A[3] >= A[4] ...
 * 
 * A simple strategy is to sort the array first.
 * Let the sorted array be S[0], S[1], ..., S[N-1].
 * 
 * If we place the elements in the order:
 * S[0], S[1], S[2], S[3], ...
 * 
 * We can swap adjacent pairs (S[i], S[i+1]) for all even i.
 * Specifically, if we have sorted array S:
 * For every i from 0 to N-2 with step 2:
 * Swap S[i] and S[i+1].
 * 
 * Let's trace:
 * Sorted: 2, 5, 10
 * i=0: Swap(S[0], S[1]) -> 5, 2, 10
 * Check: 5 <= 2 (False). Wait, the logic should be:
 * 
 * Correct Strategy:
 * Sort the array.
 * The pattern A[0] <= A[1] >= A[2] <= A[3] ...
 * If we sort the array, we have S[0] <= S[1] <= S[2] <= S[3] ...
 * If we swap every adjacent pair (S[i], S[i+1]) where i is even:
 * We get S[1], S[0], S[3], S[2], S[5], S[4]...
 * 
 * Let's check:
 * A[0] = S[1], A[1] = S[0]. Since S[0] <= S[1], then A[0] >= A[1]. This is wrong.
 * 
 * Let's try:
 * Just sort the array and swap adjacent pairs (S[i], S[i+1]) where i is odd?
 * No, simply:
 * Sort the array.
 * For i = 0 to N-2 step 2:
 *   swap(S[i], S[i+1])
 * 
 * Example: 2, 5, 10
 * i=0: swap(2, 5) -> 5, 2, 10
 * A[0]=5, A[1]=2, A[2]=10. 
 * 5 <= 2 (False).
 * 
 * Correct approach:
 * Sort the array.
 * For i = 1 to N-2 step 2:
 *   swap(S[i], S[i+1])
 * 
 * Example: 2, 5, 10
 * i=1: swap(5, 10) -> 2, 10, 5
 * A[0]=2, A[1]=10, A[2]=5.
 * 2 <= 10 (True), 10 >= 5 (True). Correct.
 * 
 * Example: 1, 2, 3, 4
 * Sorted: 1, 2, 3, 4
 * i=1: swap(2, 3) -> 1, 3, 2, 4
 * A[0]=1, A[1]=3, A[2]=2, A[3]=4.
 * 1 <= 3 (True), 3 >= 2 (True), 2 <= 4 (True). Correct.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    for (int i = 1; i + 1 < n; i += 2) {
        swap(a[i], a[i + 1]);
    }
    
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}