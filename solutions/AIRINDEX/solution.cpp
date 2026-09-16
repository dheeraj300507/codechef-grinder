#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Air Quality Index (AIRINDEX)
 * The condition is that the AQI (X) must be strictly below 100.
 * If X < 100, output YES.
 * Otherwise, output NO.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single input X, 
    // but standard competitive programming practice often involves 
    // handling test cases if specified. Given the constraints and format,
    // we read the integer X.
    int X;
    if (!(cin >> X)) return 0;

    // Check if AQI is strictly below 100
    if (X < 100) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}