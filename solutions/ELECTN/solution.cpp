#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: ELECTN - Elections in Chefland
 * Approach: Iterate through the array of ages and count how many are >= X.
 * Time Complexity: O(T * N), where T is the number of test cases and N is the number of people.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int eligible_count = 0;
        for (int i = 0; i < n; ++i) {
            int age;
            cin >> age;
            // A person is eligible if their age is at least X
            if (age >= x) {
                eligible_count++;
            }
        }

        cout << eligible_count << "\n";
    }

    return 0;
}