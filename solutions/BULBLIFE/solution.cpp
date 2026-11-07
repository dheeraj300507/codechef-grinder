#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N bulbs in total. We are given the lifetimes of N-1 bulbs.
 * Let the sum of the given N-1 bulbs be S.
 * Let the lifetime of the N-th bulb be Y.
 * The condition for the average lifetime is:
 * (S + Y) / N >= X
 * 
 * Multiplying by N (since N > 0):
 * S + Y >= N * X
 * Y >= N * X - S
 * 
 * Since Y must be a non-negative integer, the minimum value of Y is:
 * max(0, N * X - S)
 * 
 * Constraints:
 * N <= 100, X <= 1000, A_i <= 1000.
 * The maximum possible value for N * X is 100 * 1000 = 100,000.
 * This fits comfortably within a standard 32-bit integer, but we will use 
 * long long to be safe and follow best practices.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    
    long long sum_given = 0;
    for (int i = 0; i < N - 1; ++i) {
        long long a;
        cin >> a;
        sum_given += a;
    }
    
    // The required sum for all N bulbs to have an average of at least X is N * X.
    long long required_total_sum = (long long)N * X;
    
    // The remaining bulb Y must satisfy: sum_given + Y >= required_total_sum
    // Y >= required_total_sum - sum_given
    long long Y = required_total_sum - sum_given;
    
    // Since Y must be non-negative, if the calculated Y is negative, 
    // it means the current sum already satisfies the condition even if Y = 0.
    if (Y < 0) {
        cout << 0 << "\n";
    } else {
        cout << Y << "\n";
    }
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