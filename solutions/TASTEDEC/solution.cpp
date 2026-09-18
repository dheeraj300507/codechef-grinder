#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Tasty Decisions
 * Logic:
 * - Chocolate packet contains 2 bars of tastiness X: Total = 2 * X
 * - Candy packet contains 5 pieces of tastiness Y: Total = 5 * Y
 * - Compare 2*X and 5*Y and output the result accordingly.
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
        long long x, y;
        cin >> x >> y;
        
        long long chocolate_tastiness = 2 * x;
        long long candy_tastiness = 5 * y;
        
        if (chocolate_tastiness > candy_tastiness) {
            cout << "Chocolate" << "\n";
        } else if (candy_tastiness > chocolate_tastiness) {
            cout << "Candy" << "\n";
        } else {
            cout << "Either" << "\n";
        }
    }
    
    return 0;
}