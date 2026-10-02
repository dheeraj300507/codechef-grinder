#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Giant Wheel
 * Logic: Alice can ride if her height X >= 60.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single input X per run,
    // but standard competitive programming practice often involves 
    // handling single inputs directly unless specified otherwise.
    int X;
    if (cin >> X) {
        if (X >= 60) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}