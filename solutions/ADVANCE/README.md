# [Rating Improvement (ADVANCE)](https://www.codechef.com/problems/ADVANCE)

- **Difficulty Rating**: 400
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a current rating of $X$. To improve his rating, he wants to solve a problem with a difficulty level of $Y$. A problem is considered suitable for Chef if its difficulty $Y$ is at least his current rating $X$, but no more than $X + 200$. We need to determine if a given problem with difficulty $Y$ is suitable for Chef.

## Intuition & Mathematical Observation
The problem asks us to verify if $Y$ falls within the inclusive range $[X, X + 200]$. 

Mathematically, this is equivalent to checking two conditions simultaneously:
1. $Y \ge X$ (The problem is at least as hard as his current rating).
2. $Y \le X + 200$ (The problem is not too difficult, staying within the 200-point threshold).

If both conditions are true, we output `YES`; otherwise, we output `NO`. Since the constraints on $X$ and $Y$ are small ($1 \le X, Y \le 4000$), standard integer types are sufficient to handle the comparison.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic and comparison operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values and do not require any auxiliary data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's rating is X.
 * Recommended difficulty range is [X, X + 200].
 * Chef is solving a problem of difficulty Y.
 * We need to check if X <= Y <= X + 200.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X, Y <= 4000
 * The values fit within standard integer types.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Check if Y is within the inclusive range [X, X + 200]
        if (y >= x && y <= (x + 200)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```