#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the original sequence be S of length N + K.
 * The average of all elements is V.
 * Sum of all elements = V * (N + K).
 * Let the sum of the remaining N elements be S_A = sum(A_1, ..., A_N).
 * Let the value of the K deleted elements be X.
 * Then, S_A + K * X = V * (N + K).
 * K * X = V * (N + K) - S_A.
 * X = (V * (N + K) - S_A) / K.
 * 
 * Conditions for X to be valid:
 * 1. (V * (N + K) - S_A) must be divisible by K (i.e., remainder is 0).
 * 2. X must be a positive integer (X > 0).
 */

void solve() {
    long long N, K, V;
    cin >> N >> K >> V;
    
    long long sum_A = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum_A += a;
    }
    
    long long total_sum = V * (N + K);
    long long remaining_sum = total_sum - sum_A;
    
    // Check if the remaining sum is positive and divisible by K
    if (remaining_sum > 0 && remaining_sum % K == 0) {
        cout << remaining_sum / K << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}