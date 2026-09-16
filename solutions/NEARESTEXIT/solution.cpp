#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bus has 100 seats.
 * Exit 1 is at seat 1.
 * Exit 2 is at seat 100.
 * Distance to Exit 1 = |X - 1| = X - 1
 * Distance to Exit 2 = |X - 100| = 100 - X
 * 
 * The passenger chooses the exit with the smaller distance.
 * If X - 1 < 100 - X, then 2X < 101, so X <= 50.
 * If X - 1 > 100 - X, then 2X > 101, so X > 50.
 * 
 * Therefore:
 * If X <= 50, output LEFT.
 * If X > 50, output RIGHT.
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
        
        // Compare distances to seat 1 and seat 100
        // Distance to seat 1 is (x - 1)
        // Distance to seat 100 is (100 - x)
        if (x <= 50) {
            cout << "LEFT" << "\n";
        } else {
            cout << "RIGHT" << "\n";
        }
    }
    
    return 0;
}