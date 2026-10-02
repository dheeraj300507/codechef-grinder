#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exist 7 positive integers g1, g2, ..., g7 such that:
 * g1 >= 1
 * g2 >= 2 * g1
 * g3 >= 2 * g2
 * ...
 * g7 >= 2 * g6
 * And the sum g1 + g2 + ... + g7 <= X.
 * 
 * To minimize the sum, we should pick the smallest possible values:
 * g1 = 1
 * g2 = 2 * g1 = 2
 * g3 = 2 * g2 = 4
 * g4 = 2 * g3 = 8
 * g5 = 2 * g4 = 16
 * g6 = 2 * g5 = 32
 * g7 = 2 * g6 = 64
 * 
 * The minimum sum is 1 + 2 + 4 + 8 + 16 + 32 + 64 = 127.
 * If X >= 127, it is possible to satisfy the condition.
 * If X < 127, it is impossible because any other set of values satisfying the 
 * condition will result in a sum strictly greater than 127.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // The minimum sum required for 7 days is 127.
        // 1 + 2 + 4 + 8 + 16 + 32 + 64 = 127
        if (x >= 127) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}