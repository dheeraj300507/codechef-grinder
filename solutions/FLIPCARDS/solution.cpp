#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards total.
 * X cards are face-up.
 * (N - X) cards are face-down.
 * 
 * To make all cards face-up, we must flip all (N - X) face-down cards.
 * To make all cards face-down, we must flip all X face-up cards.
 * 
 * The goal is to find the minimum number of operations, which is simply:
 * min(X, N - X)
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
        
        // The number of operations to make all face-up is (n - x)
        // The number of operations to make all face-down is x
        // We take the minimum of these two values.
        int result = min(x, n - x);
        
        cout << result << "\n";
    }
    
    return 0;
}