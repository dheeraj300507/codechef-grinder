#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Podium Finish
 * The problem asks for the total time gap between the Chef (3rd place) and the winner (1st place).
 * We are given:
 * A = Time gap between Chef and runner up (2nd place)
 * B = Time gap between runner up and winner
 * 
 * The total time gap between Chef and the winner is simply the sum of the two gaps: A + B.
 * 
 * Constraints: 1 <= T <= 100, 1 <= A, B <= 10.
 * The sum will not exceed 20, so standard 'int' is sufficient.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        // Calculate the total time gap
        int total_gap = a + b;
        
        // Output the result followed by a newline
        cout << total_gap << "\n";
    }

    return 0;
}