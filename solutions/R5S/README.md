# [Reach 5 Star (R5S)](https://www.codechef.com/problems/R5S)

- **Difficulty Rating**: 313
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef currently has a rating of $X$. After participating in a contest, their rating changes by $Y$ (where $Y$ can be positive or negative). We need to determine if Chef's new rating ($X + Y$) is at least $2000$. If the new rating is $2000$ or greater, Chef becomes a "5-star" coder.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. 
1. We are given two integers: $X$ (current rating) and $Y$ (rating change).
2. The new rating is calculated as $R_{new} = X + Y$.
3. The condition for being a 5-star coder is $R_{new} \ge 2000$.
4. Since the constraints on $X$ and $Y$ are small (within the range of a standard 32-bit integer), we can perform the addition directly and use an `if-else` statement to print "YES" or "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single addition and a comparison, which takes constant time regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the variables $X$, $Y$, and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Reach 5 Star
 * Logic:
 * Chef's current rating is X.
 * After the contest, the rating becomes X + Y.
 * Chef is 5-star if (X + Y) >= 2000.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // Read current rating and rating change
    if (!(cin >> X >> Y)) return 0;

    // Calculate new rating
    int new_rating = X + Y;

    // Check condition and output result
    if (new_rating >= 2000) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```