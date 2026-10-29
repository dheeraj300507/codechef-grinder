# [Non Adjacent Flips (NONADJFLIP)](https://www.codechef.com/problems/NONADJFLIP)

- **Difficulty Rating**: 1128
- **Solved in**: 3 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to make all characters '0' using the minimum number of operations. In one operation, we can choose a set of indices such that no two chosen indices are adjacent, and flip the bits at those indices (0 becomes 1, 1 becomes 0). We need to determine the minimum number of operations required.

## Intuition & Mathematical Observation
The problem asks for the minimum operations to clear all '1's. Let's analyze the constraints based on the configuration of '1's:

1.  **0 Operations**: If the string contains no '1's, the string is already all zeros. The cost is **0**.
2.  **1 Operation**: If there are '1's present, but no two '1's are adjacent, we can simply select all indices where $S[i] == '1'$ and flip them in a single operation. Since no two '1's are adjacent, this set of indices satisfies the "non-adjacent" condition. The cost is **1**.
3.  **2 Operations**: If there is at least one pair of adjacent '1's (e.g., "11"), we cannot flip both in the same operation. However, we can always clear the string in at most 2 operations. For example, we can flip all '1's at odd indices in the first operation and all '1's at even indices in the second operation. Since any binary string can be partitioned into two sets of non-adjacent indices, 2 is the maximum number of operations required for any string containing '1's.

**Logic Summary:**
- If no '1's: Output `0`.
- If '1's exist but no adjacent '1's: Output `1`.
- If adjacent '1's exist: Output `2`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string, as we perform a single linear scan to check for the presence of '1's and adjacent '1's.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <iostream>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * - 0 operations: String contains no '1's.
 * - 1 operation: String contains '1's, but no two '1's are adjacent.
 * - 2 operations: String contains at least one pair of adjacent '1's.
 * 
 * Complexity:
 * Time: O(N) per test case.
 * Space: O(N) to store the string.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    bool has_ones = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_ones = true;
            if (i > 0 && S[i - 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_ones) {
        cout << 0 << "\n";
    } else if (has_adjacent_ones) {
        // If there are adjacent ones, we need 2 operations.
        cout << 2 << "\n";
    } else {
        // If there are ones but no adjacent ones, 1 operation is sufficient.
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations to prevent TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```