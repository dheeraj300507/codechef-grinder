#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let 'ones' be the number of 1s in the string and 'zeros' be the number of 0s.
 * We want to reach a state where the string contains only 0s.
 * 
 * Strategy 1: Delete all 1s.
 * Cost = 'ones'.
 * 
 * Strategy 2: Flip the string, then delete the remaining 1s.
 * If we flip, the 0s become 1s and the 1s become 0s.
 * After flipping, we have 'zeros' number of 1s.
 * Cost = 1 (for flip) + 'zeros' (to delete the new 1s).
 * 
 * Strategy 3: Delete all 1s, then flip (if beneficial).
 * Actually, the flip operation affects the whole string. If we flip, we change 
 * the count of 1s and 0s.
 * 
 * Comparing the two main approaches:
 * 1. Just delete all 1s: Cost = ones
 * 2. Flip once, then delete the resulting 1s: Cost = 1 + zeros
 * 
 * We can also combine these. If we flip, we get 'zeros' number of 1s. 
 * We can then delete those 'zeros' 1s. The total cost is 1 + zeros.
 * 
 * Is there any other way? 
 * If we delete some characters first, then flip, then delete more?
 * Deleting a character before a flip is equivalent to deleting it after a flip 
 * (in terms of count). The order doesn't change the total number of operations 
 * needed to reach the target state.
 * 
 * Thus, the minimum operations is min(ones, zeros + 1).
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ones = 0;
    int zeros = 0;
    for (char c : s) {
        if (c == '1') {
            ones++;
        } else {
            zeros++;
        }
    }

    // Option 1: Delete all ones
    // Option 2: Flip (1 op) + delete all zeros (which became ones)
    int ans = min(ones, zeros + 1);

    cout << ans << "\n";
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