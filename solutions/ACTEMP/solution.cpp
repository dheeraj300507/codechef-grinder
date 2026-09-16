#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice wants temperature T >= A.
 * Charlie wants temperature T >= C.
 * Combining these, T must be >= max(A, C).
 * Bob wants temperature T <= B.
 * 
 * For a valid temperature T to exist, we need:
 * max(A, C) <= T <= B
 * 
 * This is possible if and only if:
 * max(A, C) <= B
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // The condition for a valid temperature is that the lower bound
        // (the maximum of Alice's and Charlie's requirements) must be 
        // less than or equal to the upper bound (Bob's requirement).
        if (max(a, c) <= b) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}