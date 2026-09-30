# [Water Park (SPCP1)](https://www.codechef.com/problems/SPCP1)

- **Difficulty Rating**: 485
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to enter a water park. The park has two specific entry requirements based on a person's weight and height:
1. The person's weight must be at most $W$ kg.
2. The person's height must be at least $H$ cm.

Given Chef's weight is $60$ kg and his height is $130$ cm, determine if Chef is allowed to enter the water park based on the provided constraints $W$ and $H$.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given the limits $W$ and $H$ as input. We simply need to compare Chef's fixed attributes against these limits:
*   **Condition 1**: Chef's weight ($60$) $\le W$
*   **Condition 2**: Chef's height ($130$) $\ge H$

If both conditions are true, Chef can enter ("YES"). Otherwise, he cannot ("NO"). Since the constraints for $W$ and $H$ are small ($1 \le W, H \le 1000$), standard integer comparison is perfectly efficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input values.
- **Space Complexity**: $O(1)$ — Only a few integer variables are used to store the input and Chef's stats.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's weight = 60 kg
 * Chef's height = 130 cm
 * 
 * Condition for entry:
 * 1. Weight <= W
 * 2. Height >= H
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W, H;
    // Reading the input constraints W and H
    if (cin >> W >> H) {
        // Chef's stats
        int chefWeight = 60;
        int chefHeight = 130;

        // Check conditions: Weight <= W AND Height >= H
        if (chefWeight <= W && chefHeight >= H) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```