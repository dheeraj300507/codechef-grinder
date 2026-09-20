#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A quadrilateral is cyclic if and only if the sum of its opposite angles is 180 degrees.
 * Given angles A, B, C, D in order along the perimeter, the opposite pairs are (A, C) and (B, D).
 * Therefore, the quadrilateral is cyclic if A + C = 180 and B + D = 180.
 * Since the sum of all angles in a quadrilateral is 360 (A + B + C + D = 360),
 * if A + C = 180, then B + D must also be 180 (360 - 180 = 180).
 * Thus, we only need to check if A + C == 180.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        // Check if the sum of opposite angles equals 180
        if (a + c == 180) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}