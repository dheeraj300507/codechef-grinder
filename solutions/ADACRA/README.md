# [Ada and crayons (ADACRA)](https://www.codechef.com/problems/ADACRA)

- **Difficulty Rating**: 1099
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string consisting of characters 'U' (Up) and 'D' (Down). We can perform an operation where we choose any contiguous segment of the string and flip all characters within that segment ('U' becomes 'D', and 'D' becomes 'U'). The goal is to find the minimum number of operations required to make all characters in the string identical (either all 'U's or all 'D's).

## Intuition & Mathematical Observation
The key to solving this problem is to view the string as a sequence of **contiguous blocks**. For example, the string `UUDDDUUU` can be broken down into three blocks: `UU`, `DDD`, and `UUU`.

- If we want to make the entire string 'U', we must flip every block of 'D's.
- If we want to make the entire string 'D', we must flip every block of 'U's.

Because each operation can flip an entire contiguous block of identical characters, the minimum number of operations to make the string all 'U's is exactly the number of 'D' blocks. Similarly, the minimum number of operations to make the string all 'D's is the number of 'U' blocks. 

Therefore, the final answer is simply:
$$\min(\text{count of 'U' blocks}, \text{count of 'D' blocks})$$

We can count these blocks by iterating through the string and incrementing a counter whenever we encounter a character that is different from the previous one (or at the start of the string).

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string to count the blocks.
- **Space Complexity**: $O(1)$ (excluding the space required to store the input string), as we only use a few integer variables to keep track of the block counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a string of 'U' and 'D'. We want to make all characters the same.
 * A flip operation on a segment [i, j] changes all 'U' to 'D' and 'D' to 'U'.
 * 
 * Let's count the number of contiguous blocks of 'U's and 'D's.
 * For example, "UUDDDUUU" has blocks: "UU", "DDD", "UUU".
 * Number of 'U' blocks = 2, Number of 'D' blocks = 1.
 * 
 * To make all 'U', we need to flip all 'D' blocks.
 * To make all 'D', we need to flip all 'U' blocks.
 * The minimum number of steps is simply min(count of 'U' blocks, count of 'D' blocks).
 */

void solve() {
    string s;
    cin >> s;
    if (s.empty()) {
        cout << 0 << "\n";
        return;
    }

    int u_blocks = 0;
    int d_blocks = 0;

    // Count contiguous blocks
    for (int i = 0; i < s.length(); ++i) {
        // A new block starts if it's the first character or different from the previous
        if (i == 0 || s[i] != s[i - 1]) {
            if (s[i] == 'U') {
                u_blocks++;
            } else {
                d_blocks++;
            }
        }
    }

    cout << min(u_blocks, d_blocks) << "\n";
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
```