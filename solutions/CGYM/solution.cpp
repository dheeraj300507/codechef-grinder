#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a budget Z.
 * Gym cost = X
 * Trainer cost = Y
 * 
 * Logic:
 * 1. If (X + Y) <= Z, Chef can afford both gym and trainer. Output: 2
 * 2. Else if X <= Z, Chef can afford only the gym. Output: 1
 * 3. Else, Chef cannot afford the gym. Output: 0
 * 
 * Constraints: 1 <= X, Y, Z <= 100. 
 * Integer overflow is not an issue with standard int, but using long long is safe practice.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Check if both gym and trainer are affordable
        if (x + y <= z) {
            cout << "2" << "\n";
        }
        // Check if only gym is affordable
        else if (x <= z) {
            cout << "1" << "\n";
        }
        // Cannot afford gym
        else {
            cout << "0" << "\n";
        }
    }
    
    return 0;
}