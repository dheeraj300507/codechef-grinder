# [Signal (P2BAR)](https://www.codechef.com/problems/P2BAR)

- **Difficulty Rating**: 657
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string of length $N$, we need to count the total number of '1's that appear after the **first** occurrence of a '0'. If no '0' exists in the string, the answer is 0.

## Intuition & Mathematical Observation
The problem requires us to track the state of the string as we iterate through it. 
1. We need a "trigger" to know when we have encountered the first '0'. A boolean flag `foundSilence` is perfect for this.
2. Once `foundSilence` becomes `true`, every '1' we encounter from that point forward contributes to our total count.
3. If we encounter a '0' before the flag is set, we simply flip the flag to `true`. If we encounter subsequent '0's, the flag remains `true`, and we continue counting '1's.

This approach ensures we only count '1's that satisfy the condition of appearing after at least one '0'.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string.
- **Space Complexity**: $O(N)$ to store the input string. (This can be optimized to $O(1)$ if reading character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to count the number of '1's that appear after the first occurrence of a '0'.
 * 
 * Algorithm:
 * 1. Iterate through the string.
 * 2. Maintain a boolean flag `foundSilence` initialized to false.
 * 3. If we encounter a '0', set `foundSilence` to true.
 * 4. If we encounter a '1' and `foundSilence` is true, increment the counter.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    long long count = 0;
    bool foundSilence = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            foundSilence = true;
        } else if (S[i] == '1') {
            if (foundSilence) {
                count++;
            }
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O for performance
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