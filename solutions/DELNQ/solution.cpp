#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to delete one of two adjacent characters if they are different.
 * This means if there is at least one '0' and at least one '1' in the string, 
 * we can always reduce the string length.
 * 
 * Specifically:
 * 1. If the string contains both '0' and '1', we can keep performing operations 
 *    until only one character remains. Why? Because as long as there is at least 
 *    one '0' and one '1', there must be at least one adjacent pair (0,1) or (1,0) 
 *    somewhere in the string. We can use this pair to delete one character, 
 *    reducing the length by 1, and potentially creating new adjacent pairs. 
 *    We can continue this until only one character is left.
 * 2. If the string consists of only '0's or only '1's, no operation can ever be 
 *    performed because there are no adjacent characters that are different. 
 *    In this case, the length remains N.
 * 
 * Therefore:
 * - If count('0') > 0 and count('1') > 0, the answer is 1.
 * - Otherwise, the answer is N.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool hasZero = false;
    bool hasOne = false;

    for (char c : s) {
        if (c == '0') hasZero = true;
        if (c == '1') hasOne = true;
    }

    if (hasZero && hasOne) {
        cout << 1 << "\n";
    } else {
        cout << n << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}