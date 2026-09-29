#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: WECNITK - Access Code Equality
 * The task is to check if the input string S is exactly "WECNITK".
 * The problem specifies that the comparison is case-sensitive.
 * Time Complexity: O(1) per test case (string length is fixed at 7).
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single input string S.
    // However, standard competitive programming practice often involves 
    // test cases. Given the problem description format, we handle the 
    // single input provided.
    string s;
    if (cin >> s) {
        if (s == "WECNITK") {
            cout << "Welcome to Web Club!" << "\n";
        } else {
            cout << "Access denied" << "\n";
        }
    }

    return 0;
}