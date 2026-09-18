#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: October Marathon
 * Logic:
 * - If X < 3: GOLD
 * - If 3 <= X < 6: SILVER
 * - If X >= 6: BRONZE
 * 
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single input X per run based on the 
    // sample format, but standard competitive programming practice often 
    // involves a test case count. Given the constraints and format:
    int X;
    if (!(cin >> X)) return 0;

    if (X < 3) {
        cout << "GOLD" << "\n";
    } else if (X < 6) {
        cout << "SILVER" << "\n";
    } else {
        cout << "BRONZE" << "\n";
    }

    return 0;
}