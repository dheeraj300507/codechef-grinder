#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: International Justice Day
 * Logic: The accused is convicted if X >= Y.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves handling 
    // potential multiple test cases if specified. Given the constraints and 
    // description, we read X and Y.
    long long X, Y;
    if (cin >> X >> Y) {
        if (X >= Y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}