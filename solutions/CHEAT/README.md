# [Dracula Eats (CHEAT)](https://www.codechef.com/problems/CHEAT)

- **Difficulty Rating**: 763
- **Solved in**: 2 attempt(s)

## Problem Summary
Dracula eats a large amount of food every Tuesday. Given that the current day is Monday (Day 1), we need to determine how many Tuesdays occur within a period of $N$ days.

## Intuition & Mathematical Observation
The days follow a weekly cycle. Since the first Tuesday occurs on Day 2, subsequent Tuesdays will occur every 7 days thereafter. The sequence of days on which Dracula eats is:
$2, 9, 16, 23, \dots$

This is an arithmetic progression where the $k$-th Tuesday occurs on day $D_k = 2 + (k-1) \times 7$. To find the total number of Tuesdays ($k$) within $N$ days, we solve for the largest $k$ such that:
$$2 + (k-1) \times 7 \le N$$

Rearranging the inequality:
$$(k-1) \times 7 \le N - 2$$
$$k-1 \le \frac{N - 2}{7}$$
$$k \le \frac{N - 2}{7} + 1$$

Since we are dealing with integer days, using integer division in programming effectively gives us the floor of this value. If $N < 2$, the result is 0 because the first Tuesday has not yet occurred.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Today is Monday (Day 1).
 * Tuesday is Day 2.
 * Tuesdays occur on days 2, 9, 16, 23, ...
 * This is an arithmetic progression: a_k = 2 + (k-1) * 7.
 * We need to find the largest k such that 2 + (k-1) * 7 <= N.
 */

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // If N is less than 2, no Tuesday has occurred yet.
        if (n < 2) {
            cout << 0 << "\n";
        } else {
            // Using integer division, (n - 2) / 7 gives the number of full 7-day 
            // cycles after the first Tuesday. Adding 1 accounts for the first Tuesday.
            cout << (n - 2) / 7 + 1 << "\n";
        }
    }
    
    return 0;
}
```