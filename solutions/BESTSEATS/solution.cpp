#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Best Seats
 * The goal is to find the minimum sum of two adjacent elements in an array A of size N.
 * Since N is small (up to 100), a simple linear scan O(N) is optimal.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_cost with a value larger than any possible sum.
    // Max A_i is 100, so max sum is 200.
    long long min_cost = 1e18;
    
    // Iterate through the array and check the sum of every pair of adjacent seats.
    for (int i = 0; i < N - 1; ++i) {
        long long current_sum = (long long)A[i] + A[i + 1];
        if (current_sum < min_cost) {
            min_cost = current_sum;
        }
    }
    
    cout << min_cost << "\n";
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