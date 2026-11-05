# [Access Control (ACCESS)](https://www.codechef.com/problems/ACCESS)

- **Difficulty Rating**: 1096
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a string $S$ of length $N$ representing a sequence of events at a door, and an integer $X$. 
- If $S[i] == '1'$, it represents a card swipe that grants you $X$ entries.
- If $S[i] == '0'$, it represents an attempt to enter the door, which consumes 1 entry.
- You start with 0 entries. If you encounter a '0' when your current entry count is 0, you cannot pass. Determine if it is possible to complete the entire sequence.

## Intuition & Mathematical Observation
The problem can be modeled as a simple simulation. We maintain a variable `current_swipes` to track how many entries we currently have available.

1. **Renewal**: Whenever we encounter a '1', our `current_swipes` is immediately reset to $X$. This is because the problem implies that a swipe grants $X$ entries, effectively resetting the counter to the maximum capacity.
2. **Consumption**: Whenever we encounter a '0', we must have at least one entry available. If `current_swipes > 0`, we decrement the count by 1. If `current_swipes == 0`, it is impossible to proceed, so we terminate and output "NO".
3. **Greedy Approach**: Since the rules are deterministic and there are no choices to make, a single linear pass through the string is sufficient to verify the validity of the sequence.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string exactly once.
- **Space Complexity**: $O(N)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - We start with 0 swipes.
 * - If S[i] == '1', swipes become X.
 * - If S[i] == '0', we must have at least 1 swipe, and then we decrement it.
 * - If at any point we encounter '0' and swipes == 0, the process is invalid.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    string S;
    cin >> S;

    int current_swipes = 0;
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            // Renewal: reset swipes to X
            current_swipes = X;
        } else {
            // Swipe: check if we have any swipes left
            if (current_swipes > 0) {
                current_swipes--;
            } else {
                // No swipes left, cannot access the door
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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
```