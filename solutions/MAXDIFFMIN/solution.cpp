#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three integers A, B, and C such that A < B < C.
 * We need to find max(A, B, C) - min(A, B, C).
 * Since A < B < C, the maximum value is always C and the minimum value is always A.
 * Therefore, the result is simply C - A.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Given the constraint A < B < C, 
        // max(A, B, C) is C and min(A, B, C) is A.
        long long result = c - a;
        
        cout << result << "\n";
    }
    
    return 0;
}