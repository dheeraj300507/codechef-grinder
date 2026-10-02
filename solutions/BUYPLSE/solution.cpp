#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Buy Please
 * The problem asks to calculate the total cost: (a * x) + (b * y).
 * Constraints: 1 <= a, b, x, y <= 10^3.
 * Maximum possible value: (10^3 * 10^3) + (10^3 * 10^3) = 2 * 10^6.
 * This fits comfortably within a standard 32-bit integer, but using long long 
 * is a safe practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, x, y;
    
    // Reading the 4 space-separated integers
    if (cin >> a >> b >> x >> y) {
        // Calculating total cost
        long long total_cost = (a * x) + (b * y);
        
        // Output the result
        cout << total_cost << "\n";
    }

    return 0;
}