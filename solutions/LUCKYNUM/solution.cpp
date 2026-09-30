#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYNUM
 * The task is to check if at least one of the three given digits (A, B, C) is equal to 7.
 * Constraints: 0 <= A, B, C <= 9, 1 <= T <= 1000.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // Check if any of the digits is 7
        if (a == 7 || b == 7 || c == 7) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}