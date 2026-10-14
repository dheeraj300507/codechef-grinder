#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Processing a string (KOL15A)
 * Approach: Iterate through each character of the string. If the character is a digit
 * (checked using isdigit()), convert it to its integer value by subtracting '0'
 * and add it to a running sum.
 * 
 * Time Complexity: O(T * |S|), where T is the number of test cases and |S| is the length of the string.
 * Space Complexity: O(|S|) to store the input string.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string s;
        cin >> s;

        long long sum = 0;
        for (char c : s) {
            // Check if the character is a digit '0'-'9'
            if (c >= '0' && c <= '9') {
                sum += (c - '0');
            }
        }

        cout << sum << "\n";
    }

    return 0;
}