#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string D consisting of only '0's and '1's.
 * We want to make all digits the same by flipping exactly one digit.
 * 
 * Let count0 be the number of '0's and count1 be the number of '1's.
 * 
 * Case 1: Make all digits '1'.
 * This is possible if we have exactly one '0' and the rest are '1's.
 * i.e., count0 == 1.
 * 
 * Case 2: Make all digits '0'.
 * This is possible if we have exactly one '1' and the rest are '0's.
 * i.e., count1 == 1.
 * 
 * Therefore, the condition is (count0 == 1 && count1 == (total_length - 1)) 
 * OR (count1 == 1 && count0 == (total_length - 1)).
 * Simplified: The condition is satisfied if (count0 == 1 and count1 == total_length - 1) 
 * OR (count1 == 1 and count0 == total_length - 1).
 * 
 * Actually, the problem asks if we can make all digits equal by flipping EXACTLY one digit.
 * If count0 == 1 and count1 == 0, we flip the '0' to '1', result is all '1's (length 1).
 * If count1 == 1 and count0 == 0, we flip the '1' to '0', result is all '0's (length 1).
 * If count0 == 1 and count1 > 0, we flip the '0' to '1', result is all '1's.
 * If count1 == 1 and count0 > 0, we flip the '1' to '0', result is all '0's.
 * 
 * In all other cases, flipping one digit will not result in all digits being the same.
 */

void solve() {
    string s;
    cin >> s;
    int count0 = 0;
    int count1 = 0;
    for (char c : s) {
        if (c == '0') count0++;
        else count1++;
    }

    if ((count0 == 1 && count1 == (int)s.length() - 1) || 
        (count1 == 1 && count0 == (int)s.length() - 1)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}