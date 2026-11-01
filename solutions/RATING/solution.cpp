#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given S = X + Y, where X > 0 and Y < 0.
 * We want to maximize the product P = X * Y.
 * Since Y = S - X, we have P = X * (S - X) = SX - X^2.
 * This is a downward-opening parabola with respect to X.
 * The vertex is at X = S/2.
 * However, we have the constraint Y < 0, which means S - X < 0, so X > S.
 * Since X must be an integer and X > S, the smallest possible integer value for X is S + 1.
 * Substituting X = S + 1 into the product formula:
 * P = (S + 1) * (S - (S + 1))
 * P = (S + 1) * (-1)
 * P = -S - 1
 * 
 * Since S can be up to 10^9, -S-1 can be around -10^9, which fits in a 32-bit signed integer,
 * but using long long is safer and good practice for competitive programming.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long s;
        cin >> s;
        
        // The maximum product is achieved when Y is as close to 0 as possible.
        // Given Y < 0 and X > 0, and X + Y = S,
        // Y = S - X. To maximize X * Y, we want Y to be the largest possible negative integer,
        // which is -1.
        // If Y = -1, then X = S + 1.
        // Product = (S + 1) * (-1) = -S - 1.
        
        long long result = -s - 1;
        cout << result << "\n";
    }
    
    return 0;
}