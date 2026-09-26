#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Today is Monday (Day 1).
 * Tuesday is Day 2.
 * Tuesdays occur on days 2, 9, 16, 23, ...
 * This is an arithmetic progression: a_k = 2 + (k-1) * 7.
 * We need to find the largest k such that 2 + (k-1) * 7 <= N.
 * (k-1) * 7 <= N - 2
 * k - 1 <= (N - 2) / 7
 * k <= (N - 2) / 7 + 1
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        if (n < 2) {
            cout << 0 << "\n";
        } else {
            // Using integer division, (n - 2) / 7 gives the number of full 7-day 
            // cycles after the first Tuesday. Adding 1 accounts for the first Tuesday.
            cout << (n - 2) / 7 + 1 << "\n";
        }
    }
    
    return 0;
}