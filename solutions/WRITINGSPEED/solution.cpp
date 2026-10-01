#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Rahul has 5 pages to write.
 * He has a total of 60 minutes.
 * He takes X minutes per page.
 * Total time taken = 5 * X.
 * Condition: 5 * X <= 60.
 * Simplifying: X <= 12.
 * 
 * Constraints: 1 <= X <= 1000.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // The problem description implies a single input X, 
    // but standard competitive programming practice often involves 
    // reading until EOF or a specific number of test cases.
    // Given the problem format, we read X directly.
    if (cin >> X) {
        if (5 * X <= 60) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}