#include <bits/stdc++.h>

using namespace std;

/**
 * Problem Analysis:
 * Total apples = N, Total boxes = K.
 * Candidate 1: Puts 1 apple in each of the K boxes, repeating this N/K times.
 * Result 1: Every box gets exactly (N/K) apples.
 * 
 * Candidate 2: Puts K apples into a single box at a time.
 * Total rounds = N/K. In each round, the candidate picks a box with the minimum number of apples.
 * Let M = N/K be the number of rounds.
 * If M is a multiple of K, then in each round, the candidate will eventually fill each box 
 * exactly (M/K) times. Since each time they add K apples, each box will end up with 
 * (M/K) * K = M = N/K apples. This matches Candidate 1.
 * 
 * If M is NOT a multiple of K, the distribution will be uneven. 
 * Specifically, if M = qK + r (where 0 < r < K), some boxes will have (q+1) * K apples 
 * and others will have q * K apples. This differs from Candidate 1.
 * 
 * Therefore, the distributions are the same if and only if (N/K) is divisible by K.
 * (N/K) % K == 0  =>  N % (K*K) == 0.
 * 
 * Constraints: N, K up to 10^18. Use long long.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // The condition for the distributions to be the same is (N/K) % K == 0.
        // This is equivalent to N % (K * K) == 0.
        // Note: K*K can exceed 10^18 if K > 10^9. 
        // However, N is at most 10^18. If K > 10^9, K*K > 10^18.
        // If K > sqrt(N), then N/K < K, so N/K % K cannot be 0 unless N/K is 0 (not possible here).
        
        long long m = n / k;
        if (m % k == 0) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }

    return 0;
}