#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chessboard Distance
 * The distance is defined as max(|X1 - X2|, |Y1 - Y2|).
 * Constraints: 1 <= X, Y <= 10^5.
 * The differences will fit in standard integer types, but using long long 
 * is safe practice for competitive programming to prevent overflow in 
 * arithmetic operations.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Calculate absolute differences
        long long diff_x = abs(x1 - x2);
        long long diff_y = abs(y1 - y2);
        
        // The chessboard distance is the maximum of the two absolute differences
        long long distance = max(diff_x, diff_y);
        
        cout << distance << "\n";
    }
    
    return 0;
}