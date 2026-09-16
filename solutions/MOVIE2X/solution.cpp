#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef watches the first Y minutes at 2x speed.
 * Time taken for the first Y minutes = Y / 2.
 * The remaining (X - Y) minutes are watched at normal speed (1x).
 * Time taken for the remaining (X - Y) minutes = X - Y.
 * Total time = (Y / 2) + (X - Y).
 * 
 * Constraints:
 * 1 <= X, Y <= 1000
 * Y is even.
 * Time complexity: O(1) per test case.
 * Space complexity: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves handling multiple
    // test cases if specified. Given the prompt asks to handle multiple test cases
    // if requested, we implement the logic to read X and Y.
    
    int X, Y;
    if (cin >> X >> Y) {
        // Calculate total time spent
        // Using long long to prevent overflow, though int is sufficient for 1000
        long long total_time = (Y / 2) + (X - Y);
        cout << total_time << "\n";
    }

    return 0;
}