# [Chess Format (CHSFORMT)](https://www.codechef.com/problems/CHSFORMT)

- **Difficulty Rating**: 844
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to categorize a chess game format based on the total duration of the game, which is the sum of the time control for the player ($a$) and the increment per move ($b$). The categories are defined as follows:
- **Bullet**: Total time < 3 minutes.
- **Blitz**: 3 $\le$ Total time $\le$ 10 minutes.
- **Rapid**: 11 $\le$ Total time $\le$ 60 minutes.
- **Classical**: Total time > 60 minutes.

Given $a$ and $b$, we need to output the corresponding category index (1, 2, 3, or 4).

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. By calculating the sum $S = a + b$, we can map the result directly to the specified ranges:
1. If $S < 3$, output `1`.
2. If $3 \le S \le 10$, output `2`.
3. If $11 \le S \le 60$, output `3`.
4. If $S > 60$, output `4`.

Since the constraints on $a$ and $b$ are small, a simple `long long` (or even `int`) is sufficient to store the sum without overflow.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic and comparison operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chess Format
 * Logic:
 * Calculate sum = a + b.
 * Check the conditions provided:
 * 1) Bullet: sum < 3
 * 2) Blitz: 3 <= sum <= 10
 * 3) Rapid: 11 <= sum <= 60
 * 4) Classical: sum > 60
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long sum = a + b;
        
        if (sum < 3) {
            cout << 1 << "\n";
        } else if (sum >= 3 && sum <= 10) {
            cout << 2 << "\n";
        } else if (sum >= 11 && sum <= 60) {
            cout << 3 << "\n";
        } else {
            cout << 4 << "\n";
        }
    }
    
    return 0;
}
```