#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: FLOW008 - Helping Chef
 * Logic: If N < 10, print "Thanks for helping Chef!", else print "-1".
 * Constraints: -20 <= N <= 20. 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long n;
        cin >> n;

        if (n < 10) {
            cout << "Thanks for helping Chef!" << "\n";
        } else {
            cout << "-1" << "\n";
        }
    }

    return 0;
}