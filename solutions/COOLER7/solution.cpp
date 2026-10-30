#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To drop the temperature from T to T-1, it takes T minutes.
 * To go from N to M, we need to perform (N - M) steps.
 * Step 1: N -> N-1 takes N minutes.
 * Step 2: N-1 -> N-2 takes N-1 minutes.
 * ...
 * Step k: (N-k+1) -> (N-k) takes (N-k+1) minutes.
 * 
 * The total time is the sum of integers from (M+1) to N.
 * Sum = N + (N-1) + ... + (M+1)
 * This is an arithmetic progression sum:
 * Sum = (Number of terms) * (First term + Last term) / 2
 * Number of terms = N - M
 * Sum = (N - M) * (N + M + 1) / 2
 * 
 * Constraints: N <= 40, so the result will easily fit in a standard integer.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // The total time is the sum of temperatures from M+1 to N
        // Sum = (N + M + 1) * (N - M) / 2
        long long total_time = (n + m + 1) * (n - m) / 2;
        
        cout << total_time << "\n";
    }

    return 0;
}