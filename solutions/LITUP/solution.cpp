#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N stalls and need to place exactly two floodlights at distinct positions i and j (1 <= i, j <= N, i != j).
 * A light at position p covers stalls [max(1, p-K), min(N, p+K)].
 * Two lights at i and j cover the union of [max(1, i-K), min(N, i+K)] and [max(1, j-K), min(N, j+K)].
 * We need to check if this union covers all stalls from 1 to N.
 * Since N is small (up to 100), we can iterate over all pairs (i, j) with 1 <= i < j <= N.
 * For each pair, check if the union covers [1, N] and calculate the cost C[i] + C[j].
 * Keep track of the minimum cost found.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> C(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> C[i];
    }

    long long min_cost = -1;

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            // Light 1 covers [max(1, i-K), min(N, i+K)]
            // Light 2 covers [max(1, j-K), min(N, j+K)]
            
            int start1 = max(1, i - K);
            int end1 = min(N, i + K);
            int start2 = max(1, j - K);
            int end2 = min(N, j + K);

            // Check if the union covers [1, N]
            // The union of two intervals [s1, e1] and [s2, e2] covers [1, N] if:
            // 1. min(s1, s2) == 1
            // 2. max(e1, e2) == N
            // 3. The gap between the two intervals is covered or they overlap.
            //    Sorted intervals: [a, b] and [c, d] where a <= c.
            //    They cover [1, N] if a=1, d=N, and c <= b + 1.
            
            int s1 = start1, e1 = end1;
            int s2 = start2, e2 = end2;
            
            if (s1 > s2) {
                swap(s1, s2);
                swap(e1, e2);
            }
            
            // Now s1 <= s2.
            // Condition: s1 == 1, e2 == N, and s2 <= e1 + 1
            if (s1 == 1 && e2 == N && s2 <= e1 + 1) {
                long long current_cost = (long long)C[i] + C[j];
                if (min_cost == -1 || current_cost < min_cost) {
                    min_cost = current_cost;
                }
            }
        }
    }

    cout << min_cost << "\n";
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