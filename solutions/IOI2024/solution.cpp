#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The IOI 2024 is held from September 1st to September 8th.
 * We are given an integer X representing a date in September.
 * We need to output "YES" if 1 <= X <= 8, otherwise "NO".
 * 
 * Constraints: 1 <= X <= 30.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // The problem description implies a single input X, but standard competitive 
    // programming practice often involves test cases. If the input format 
    // specifies a single integer X, we handle it directly.
    // Based on the provided constraints and format:
    int X;
    if (!(cin >> X)) return 0;

    if (X >= 1 && X <= 8) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}