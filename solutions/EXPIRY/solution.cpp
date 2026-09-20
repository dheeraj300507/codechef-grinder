#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Eikooc has N loaves of bread.
 * They expire in M days.
 * She can eat K loaves per day.
 * Total capacity to eat bread before expiration is M * K.
 * If M * K >= N, she can eat all the bread.
 * Otherwise, she cannot.
 * 
 * Constraints: N, M, K <= 100.
 * M * K can be at most 10,000, which fits in a standard integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        // Calculate total loaves she can eat within M days
        // Using long long to prevent any potential overflow, 
        // though int is sufficient for these constraints.
        if (m * k >= n) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}