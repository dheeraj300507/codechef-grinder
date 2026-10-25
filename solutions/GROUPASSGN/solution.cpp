#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are 2N students with roll numbers 1 to 2N.
 * The groups are formed as:
 * Group 1: (1, 2N)
 * Group 2: (2, 2N - 1)
 * ...
 * Group k: (k, 2N - k + 1)
 * ...
 * Group N: (N, N + 1)
 * 
 * Given Chef's roll number X, we need to find his partner Y.
 * From the pattern, for any roll number X, the partner Y satisfies:
 * X + Y = 2N + 1
 * Therefore, Y = 2N + 1 - X.
 * 
 * Constraints:
 * N <= 10^8, so 2N + 1 can be up to 2*10^8 + 1.
 * This fits within a standard 32-bit signed integer, but using long long 
 * is safer and good practice for competitive programming to avoid overflow 
 * in intermediate calculations.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        // Calculate partner using the derived formula
        long long partner = (2 * n + 1) - x;
        
        cout << partner << "\n";
    }
    
    return 0;
}