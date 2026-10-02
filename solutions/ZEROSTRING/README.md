# [Zero String (ZEROSTRING)](https://www.codechef.com/problems/ZEROSTRING)

- **Difficulty Rating**: 1042
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string of length $N$, we want to make all characters in the string '0'. We are allowed two types of operations:
1. **Delete a character**: Remove any character from the string.
2. **Flip the string**: Change all '0's to '1's and all '1's to '0's.

We need to find the minimum number of operations required to transform the string into a string consisting only of '0's.

## Intuition & Mathematical Observation
To reach a state where the string contains only '0's, we can analyze the two primary strategies:

1. **Direct Deletion**: We simply delete every '1' currently present in the string. If there are `ones` number of '1's, the cost is exactly `ones`.
2. **Flip and Delete**: We perform one flip operation. After the flip, all original '0's become '1's. To make the string all '0's, we must then delete all these new '1's. If there are `zeros` number of '0's, the cost is `1 (for the flip) + zeros`.

**Why these are the only two strategies:**
- Any sequence of operations involving multiple flips is redundant. Flipping twice is equivalent to doing nothing, and flipping once is sufficient to change the state of the string.
- Deleting characters before or after a flip does not change the total count of operations required to reach the target state.
- Therefore, the minimum operations required is simply the minimum of the two strategies: `min(ones, zeros + 1)`.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once to count the number of '0's and '1's.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if we process the string character by character).

## Solution Code

```cpp
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
 * After flipping, the original 'zeros' become '1's.
 * Cost = 1 (for flip) + 'zeros' (to delete the new 1s).
 * 
 * The minimum operations is min(ones, zeros + 1).
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

    // Calculate minimum of the two strategies
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
```