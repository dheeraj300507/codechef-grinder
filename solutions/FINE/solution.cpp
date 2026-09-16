#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Overspeeding Fine
 * Logic:
 * - If X <= 70: Fine = 0
 * - If 70 < X <= 100: Fine = 500
 * - If X > 100: Fine = 2000
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        if (x <= 70) {
            cout << 0 << "\n";
        } else if (x <= 100) {
            cout << 500 << "\n";
        } else {
            cout << 2000 << "\n";
        }
    }
    
    return 0;
}