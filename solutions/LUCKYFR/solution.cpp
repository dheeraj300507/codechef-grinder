#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYFR - Lucky Four
 * Approach:
 * For each test case, we read the number as a string. This allows us to easily
 * iterate through each digit of the number regardless of its size (up to 10^9).
 * We count the occurrences of the character '4' in the string.
 * Time Complexity: O(T * D), where T is the number of test cases and D is the 
 * number of digits in the integer (max 10). This is well within the 1s limit.
 * Space Complexity: O(D) to store the string representation of the number.
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

        int count = 0;
        for (char c : s) {
            if (c == '4') {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}