#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: Utkarsh and Placement tests
 * Approach:
 * Since there are only 3 companies, we can determine the preference rank 
 * by checking the position of the offered companies in the preference string.
 * The company that appears earlier in the preference list is the one chosen.
 */

void solve() {
    char p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    
    char x, y;
    cin >> x >> y;
    
    // We check the preference order directly.
    // If x is the first preference, it's the answer.
    // If x is the second preference, it's the answer only if y is the third.
    // Otherwise, y is the answer.
    
    if (x == p1 || (x == p2 && y == p3)) {
        cout << x << "\n";
    } else {
        cout << y << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}