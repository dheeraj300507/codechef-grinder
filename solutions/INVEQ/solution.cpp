#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make all characters in a binary string equal using the minimum number of operations.
 * An operation consists of flipping a continuous block of identical characters.
 * 
 * Let's count the number of contiguous blocks of '0's and '1's.
 * For example, in "101111000":
 * Blocks are: "1", "0", "1111", "000"
 * Count of '0' blocks = 2
 * Count of '1' blocks = 2
 * 
 * If we want to make the whole string '0's, we need to flip all '1' blocks.
 * If we want to make the whole string '1's, we need to flip all '0' blocks.
 * 
 * The minimum number of operations will be min(count of '0' blocks, count of '1' blocks).
 * 
 * Example 1: 101111000
 * '1' blocks: 2, '0' blocks: 2. Min is 2.
 * Example 2: 0110
 * '0' blocks: 2, '1' blocks: 1. Min is 1.
 * Example 3: 1
 * '1' blocks: 1, '0' blocks: 0. Min is 0.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    int zero_blocks = 0;
    int one_blocks = 0;

    // Count transitions to identify blocks
    // A new block starts if the current character is different from the previous one
    // or if it's the first character.
    if (s[0] == '0') zero_blocks++;
    else one_blocks++;

    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '0') zero_blocks++;
            else one_blocks++;
        }
    }

    cout << min(zero_blocks, one_blocks) << "\n";
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