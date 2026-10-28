# [Make Subarray (MAKESUB)](https://www.codechef.com/problems/MAKESUB)

- **Difficulty Rating**: 940
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to make all the '1's in the string form a single contiguous block. We are allowed to change any '0' to a '1'. We need to find the minimum number of operations (changing '0' to '1') required to satisfy this condition.

## Intuition & Mathematical Observation
To make all '1's contiguous, we must fill in all the gaps between the leftmost '1' and the rightmost '1'. 

1. **Identify the boundaries**: Find the index of the first occurrence of '1' (`first`) and the last occurrence of '1' (`last`).
2. **Handle edge cases**: If the string contains no '1's, the condition is already satisfied (a set of zero '1's is technically contiguous), so the cost is 0.
3. **Calculate the cost**: Any '0' located between the `first` index and the `last` index breaks the contiguity of the '1's. Therefore, every '0' in the range $[first, last]$ must be flipped to '1'. The total number of flips required is exactly the count of '0's in that range.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass (or two simple passes) over the string to find the indices and count the zeros.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if we process the string character by character (though $O(N)$ is standard for string storage).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make all black cells (1s) form a single contiguous block.
 * We can only change 0s to 1s.
 * 
 * Let the first occurrence of '1' be at index 'first' and the last 
 * occurrence of '1' be at index 'last'.
 * If there are no '1's, the cost is 0.
 * If there are '1's, all cells between 'first' and 'last' must be '1'.
 * Any '0' in the range [first, last] must be changed to '1'.
 * 
 * The number of changes required is simply the count of '0's 
 * between the first '1' and the last '1'.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int first = -1;
    int last = -1;

    // Find the boundaries of the existing 1s
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    // If no '1's exist, condition is already satisfied.
    if (first == -1) {
        cout << 0 << "\n";
        return;
    }

    // Count '0's between first and last '1'
    int changes = 0;
    for (int i = first; i <= last; ++i) {
        if (S[i] == '0') {
            changes++;
        }
    }

    cout << changes << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```