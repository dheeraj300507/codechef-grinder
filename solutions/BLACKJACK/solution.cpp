#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two numbers A and B.
 * We need to find a third number X such that A + B + X = 21.
 * This implies X = 21 - (A + B).
 * The constraint on X is 1 <= X <= 10.
 * If the calculated X satisfies this constraint, we output X.
 * Otherwise, we output -1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int sum_ab = a + b;
        int x = 21 - sum_ab;
        
        // Check if the required third number is within the valid range [1, 10]
        if (x >= 1 && x <= 10) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}