#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks us to determine if the temperature T is strictly greater than 30.
 * If T > 30, output "YES".
 * Otherwise, output "NO".
 * 
 * Constraints:
 * 1 <= T <= 50
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Reading the input temperature
    if (!(cin >> t)) return 0;

    // Logic: Check if temperature is strictly greater than 30
    if (t > 30) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}