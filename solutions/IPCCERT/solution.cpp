#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: IPCCERT
 * Time Complexity: O(N * K)
 * Space Complexity: O(1) (excluding input storage)
 * 
 * Logic:
 * For each student, we calculate the sum of lecture times T_{i,j}.
 * We check two conditions:
 * 1. Total time >= M
 * 2. Questions asked Q_i <= 10
 * If both are true, the student is eligible.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    int K;

    if (!(cin >> N >> M >> K)) return 0;

    int eligible_count = 0;

    for (int i = 0; i < N; ++i) {
        long long total_time = 0;
        for (int j = 0; j < K; ++j) {
            long long t;
            cin >> t;
            total_time += t;
        }
        
        long long Q;
        cin >> Q;

        // Check criteria:
        // 1. Total time watched >= M
        // 2. Questions asked <= 10
        if (total_time >= M && Q <= 10) {
            eligible_count++;
        }
    }

    cout << eligible_count << "\n";

    return 0;
}