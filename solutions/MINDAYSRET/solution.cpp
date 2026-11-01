#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N students and a capacity of K students per day.
 * To find the minimum number of days, we need to perform ceiling division of N by K.
 * Mathematically, this is ceil(N / K).
 * Using integer arithmetic, ceil(N / K) can be calculated as (N + K - 1) / K.
 * 
 * Constraints:
 * T <= 10^4, N, K <= 10^2.
 * The calculation (N + K - 1) / K will not overflow standard integers.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Calculate ceiling division: (n + k - 1) / k
        // This works for all positive integers n and k.
        long long days = (n + k - 1) / k;
        
        cout << days << "\n";
    }

    return 0;
}