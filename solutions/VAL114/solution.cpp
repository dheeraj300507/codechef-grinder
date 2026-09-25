#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that Starters 120 is today, and Starters 121 is likely 
 * to be on Valentine's Day. Given N, we need to check if N == 121.
 * 
 * Constraints: 120 <= N <= 123.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        if (N == 121) {
            cout << "Likely" << "\n";
        } else {
            cout << "Unlikely" << "\n";
        }
    }

    return 0;
}