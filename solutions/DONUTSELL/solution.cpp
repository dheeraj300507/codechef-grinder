#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Selling Donuts
 * Approach:
 * We are given N types of donuts with initial counts A_i.
 * M customers arrive sequentially, each requesting a specific type B_i.
 * If A[B_i] > 0, we decrement A[B_i] and the customer is satisfied.
 * If A[B_i] == 0, the customer is sad.
 * 
 * Since N and M are small (up to 100), a simple simulation is O(M) per test case,
 * which is well within the time limits.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    // Use 1-based indexing for convenience to match donut types 1 to N
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int sad_customers = 0;
    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        
        // Check if the requested donut type is available
        if (A[type] > 0) {
            A[type]--;
        } else {
            // No donuts left of this type, customer is sad
            sad_customers++;
        }
    }

    cout << sad_customers << "\n";
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