#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A student i is happy if A[i] > max(A[0], A[1], ..., A[i-1]).
 * For the first student (i=0), there are no students before them, 
 * so the condition is vacuously true (or simply, they are the first, 
 * so they are always happy).
 * 
 * We can maintain a running maximum of the scores seen so far.
 * For each student i:
 * 1. If i == 0, they are happy.
 * 2. If A[i] > current_max, they are happy and we update current_max.
 * 3. Otherwise, they are not happy.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array, or O(1) if processed on the fly.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int current_max = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] > current_max) {
            cout << 1 << (i == N - 1 ? "" : " ");
            current_max = A[i];
        } else {
            cout << 0 << (i == N - 1 ? "" : " ");
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}