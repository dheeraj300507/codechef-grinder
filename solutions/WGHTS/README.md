# [Weights (WGHTS)](https://www.codechef.com/problems/WGHTS)

- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an object with weight $W$ and three available weights $X, Y,$ and $Z$, determine if it is possible to measure the object using any combination of the three weights. Each weight can be used at most once.

## Intuition & Mathematical Observation
Since we can use each of the three weights ($X, Y, Z$) either zero or one time, there are a finite number of possible combinations we can form. Specifically, there are $2^3 - 1 = 7$ non-empty combinations:

1. **Single weights**: $X, Y, Z$
2. **Pairs**: $X+Y, X+Z, Y+Z$
3. **All three**: $X+Y+Z$

To solve the problem, we simply check if the target weight $W$ is equal to any of these 7 possible sums. If $W$ matches any of these values, the answer is "YES"; otherwise, it is "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the boolean result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an object of weight W and three available weights X, Y, and Z.
 * We need to determine if W can be formed by any combination of X, Y, and Z.
 * Since we can use one or more weights, the possible combinations are:
 * 1. Single weights: X, Y, Z
 * 2. Pairs: X+Y, X+Z, Y+Z
 * 3. All three: X+Y+Z
 * 
 * We simply check if W equals any of these 7 possible sums.
 */

void solve() {
    long long W, X, Y, Z;
    if (!(cin >> W >> X >> Y >> Z)) return;

    // Check all possible combinations
    bool possible = false;
    
    // Single weights
    if (W == X || W == Y || W == Z) possible = true;
    
    // Pairs
    else if (W == (X + Y) || W == (X + Z) || W == (Y + Z)) possible = true;
    
    // All three
    else if (W == (X + Y + Z)) possible = true;

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
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