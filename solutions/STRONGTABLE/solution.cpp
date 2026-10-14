#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Suppose we choose a subset of k legs with strengths W_1, W_2, ..., W_k.
 * Let the minimum strength among these be W_min.
 * The weight W distributed equally is W/k.
 * For the table to hold, W/k <= W_i for all i in the subset.
 * This implies W/k <= W_min, so W <= k * W_min.
 * To maximize W, we should pick a subset of size k such that all legs have strength >= W_min.
 * If we sort the strengths in non-decreasing order: W_1 <= W_2 <= ... <= W_N,
 * and we decide that the minimum strength in our subset is W_i,
 * then to maximize the number of legs k, we should pick all legs from index i to N.
 * The number of such legs is (N - i + 1).
 * The maximum weight for this choice is (N - i + 1) * W_i.
 * We iterate through all possible i and find the maximum value.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    // Sort the strengths to easily count how many legs have strength >= W_i
    sort(w.begin(), w.end());

    long long max_weight = 0;
    for (int i = 0; i < n; ++i) {
        // If we pick w[i] as the minimum strength, 
        // we can include all legs from i to n-1.
        // The number of legs is (n - i).
        long long current_weight = w[i] * (n - i);
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }

    cout << max_weight << "\n";
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