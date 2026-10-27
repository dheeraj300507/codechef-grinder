#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a right-angled triangle formed by the ladder side, the base, and the height.
 * Let B be the base (separation), LS be the left side, and RS be the right side.
 * Let H be the height of the ladder.
 * 
 * Case 1: Minimum RS
 * This occurs when the height H is minimized. The smallest possible height is when 
 * the LS is the hypotenuse and B is one leg.
 * H^2 + B^2 = LS^2 => H = sqrt(LS^2 - B^2)
 * Then, for the right side (RS), RS^2 = H^2 + B^2 (if we consider the triangle 
 * formed by RS, H, and B). Wait, the problem states the ladder is an inverted 'V'.
 * The two sides LS and RS meet at height H above the ground.
 * The base B is split into two segments x and y such that x + y = B.
 * LS^2 = H^2 + x^2
 * RS^2 = H^2 + y^2
 * 
 * To minimize RS:
 * RS is minimized when H is minimized. The smallest H occurs when the LS is 
 * perpendicular to the ground (H = LS). But wait, the problem says "at one extreme 
 * LS can be vertical". If LS is vertical, then H = LS.
 * Then RS^2 = H^2 + B^2 = LS^2 + B^2 (Maximum RS).
 * 
 * If RS is vertical, then H = RS.
 * Then LS^2 = H^2 + B^2 => RS^2 = LS^2 - B^2 => RS = sqrt(LS^2 - B^2) (Minimum RS).
 * 
 * So:
 * Min RS = sqrt(LS^2 - B^2)
 * Max RS = sqrt(LS^2 + B^2)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        double b, ls;
        cin >> b >> ls;
        
        // Calculate minimum RS: sqrt(LS^2 - B^2)
        // Calculate maximum RS: sqrt(LS^2 + B^2)
        double min_rs = sqrt(max(0.0, ls * ls - b * b));
        double max_rs = sqrt(ls * ls + b * b);
        
        cout << fixed << setprecision(5) << min_rs << " " << max_rs << "\n";
    }
    
    return 0;
}