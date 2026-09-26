#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Janmansh and Coins
 * Logic: Total money = (X * 10) + (Y * 5)
 * Constraints: X, Y <= 100. The maximum possible value is (100 * 10) + (100 * 5) = 1500.
 * This fits well within a standard 32-bit integer, but using long long is safe practice.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        if (cin >> x >> y) {
            // Calculate total money
            long long total = (x * 10) + (y * 5);
            cout << total << "\n";
        }
    }

    return 0;
}