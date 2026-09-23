#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A group of three people with ages A, B, and C is "perfect" if:
 * 1. A = B + C
 * 2. B = A + C
 * 3. C = A + B
 * 
 * Since the constraints are small (1 <= A, B, C <= 100), standard integer types
 * are sufficient. We check these three conditions for each test case.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Check if any one age is the sum of the other two
        if ((a == b + c) || (b == a + c) || (c == a + b)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}