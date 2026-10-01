#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts facing North.
 * Each second, he rotates 90 degrees clockwise.
 * The directions in clockwise order are:
 * 0: North
 * 1: East
 * 2: South
 * 3: West
 * 
 * After X seconds, the direction is determined by X % 4.
 * 0 % 4 = 0 -> North
 * 1 % 4 = 1 -> East
 * 2 % 4 = 2 -> South
 * 3 % 4 = 3 -> West
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
        
        int remainder = x % 4;
        
        if (remainder == 0) {
            cout << "North" << "\n";
        } else if (remainder == 1) {
            cout << "East" << "\n";
        } else if (remainder == 2) {
            cout << "South" << "\n";
        } else {
            cout << "West" << "\n";
        }
    }
    
    return 0;
}