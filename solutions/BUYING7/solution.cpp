#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Expensive Buying
 * Approach:
 * To find the sum of the K most expensive items, we can sort the array of prices
 * in descending order and sum the first K elements. Alternatively, sort in 
 * ascending order and sum the last K elements.
 * 
 * Time Complexity: O(T * N log N)
 * Space Complexity: O(N)
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<long long> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    // Sort the prices in ascending order
    sort(C.begin(), C.end());
    
    // Sum the last K elements (the K largest)
    long long total_cost = 0;
    for (int i = N - 1; i >= N - K; --i) {
        total_cost += C[i];
    }
    
    cout << total_cost << "\n";
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