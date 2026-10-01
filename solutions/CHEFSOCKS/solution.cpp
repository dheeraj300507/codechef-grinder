#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Socks
 * Logic: Chef can afford the socks if his total money (X + Y) is greater than or equal to the cost (A).
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the input format description.
    // However, standard competitive programming practice often involves handling multiple test cases.
    // Given the constraints and description, we read A, X, and Y.
    
    long long A, X, Y;
    if (cin >> A >> X >> Y) {
        // Check if total money (X + Y) is sufficient to cover cost A
        if (X + Y >= A) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}