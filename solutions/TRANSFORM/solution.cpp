#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Mario's transformation cycle:
 * Initial: NORMAL
 * 1 mushroom: HUGE
 * 2 mushrooms: SMALL
 * 3 mushrooms: NORMAL
 * 4 mushrooms: HUGE
 * 5 mushrooms: SMALL
 * 6 mushrooms: NORMAL
 * 
 * The cycle repeats every 3 mushrooms:
 * X % 3 == 0 -> NORMAL
 * X % 3 == 1 -> HUGE
 * X % 3 == 2 -> SMALL
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x;
        cin >> x;
        
        int remainder = x % 3;
        
        if (remainder == 0) {
            cout << "NORMAL" << "\n";
        } else if (remainder == 1) {
            cout << "HUGE" << "\n";
        } else {
            cout << "SMALL" << "\n";
        }
    }
    
    return 0;
}