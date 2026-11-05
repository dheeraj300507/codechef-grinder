#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks whether the count of '1's (Yes) and '0's (No) in the hero's 
 * responses matches the count of '1's and '0's in the correct answers.
 * Since there are only 3 questions, we can simply count the number of 1s 
 * in both sets. If the count of 1s is the same, the count of 0s must also 
 * be the same (since total questions = 3).
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a1, a2, a3;
        int b1, b2, b3;

        cin >> a1 >> a2 >> a3;
        cin >> b1 >> b2 >> b3;

        // Calculate the sum of 1s for both sets
        int sum_a = a1 + a2 + a3;
        int sum_b = b1 + b2 + b3;

        // If the number of 'Yes' (1s) matches, the number of 'No' (0s) 
        // must also match because the total number of questions is fixed at 3.
        if (sum_a == sum_b) {
            cout << "Pass" << "\n";
        } else {
            cout << "Fail" << "\n";
        }
    }

    return 0;
}