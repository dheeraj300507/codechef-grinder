#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts with an income of 2^X.
 * For each expense i (from 1 to N), he spends 50% of the remaining amount.
 * This means after each expense, the remaining amount is halved.
 * 
 * Initial amount: 2^X
 * After 1st expense: (2^X) / 2 = 2^(X-1)
 * After 2nd expense: (2^(X-1)) / 2 = 2^(X-2)
 * ...
 * After Nth expense: 2^(X-N)
 * 
 * Since N < X, the result will always be a positive integer.
 * We can compute 2^(X-N) using bitwise shift: 1 << (X - N).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x;
        cin >> n >> x;

        // The remaining amount after N expenses is 2^X / 2^N = 2^(X-N)
        // Using long long to ensure no overflow, though constraints (X <= 20) 
        // fit within a standard 32-bit integer.
        long long savings = (1LL << (x - n));
        
        cout << savings << "\n";
    }

    return 0;
}