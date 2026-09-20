#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: The Ides of March
 * The problem asks to check if the given day N is 15.
 * Constraints: 1 <= N <= 15.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // The problem description implies a single input N per run, 
    // but standard competitive programming practice handles potential 
    // multiple test cases if specified. Given the constraints, 
    // we read N and compare.
    if (cin >> N) {
        if (N == 15) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}