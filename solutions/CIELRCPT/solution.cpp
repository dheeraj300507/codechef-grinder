#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The menu prices are powers of 2: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048.
 * This is equivalent to representing a number in binary, but with a constraint:
 * we only have powers of 2 up to 2^11 (2048).
 * 
 * To minimize the number of items, we should use the largest possible menu prices first (Greedy approach).
 * Since we can use the 2048 menu multiple times, for any price p:
 * 1. Use as many 2048 menus as possible: count += p / 2048, p %= 2048.
 * 2. For the remaining p, use the binary representation (sum of powers of 2).
 *    The number of items for the remainder is simply the number of set bits (popcount).
 */

void solve() {
    int p;
    cin >> p;
    
    int count = 0;
    
    // Use the largest menu (2048) as much as possible
    count += p / 2048;
    p %= 2048;
    
    // For the remainder, use the binary representation (powers of 2)
    // __builtin_popcount returns the number of set bits in an integer
    count += __builtin_popcount(p);
    
    cout << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}