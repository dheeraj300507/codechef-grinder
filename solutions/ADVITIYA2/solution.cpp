#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: ADVITIYA2
 * Logic: The participant qualifies if the sum of the 5 judge responses (0 or 1) 
 * is greater than or equal to 4.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only store a few integer variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            int r;
            cin >> r;
            sum += r;
        }

        // Check if at least 4 judges liked the performance
        if (sum >= 4) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}