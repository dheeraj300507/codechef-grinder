# [Chef and Socks (CHEFSOCKS)](https://www.codechef.com/problems/CHEFSOCKS)

- **Difficulty Rating**: 212
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy a new pair of socks that costs $A$ rupees. Chef currently has $X$ rupees in his pocket and can borrow $Y$ rupees from his friend. Determine if Chef has enough money (his own money plus the borrowed money) to purchase the socks.

## Intuition & Mathematical Observation
The problem asks whether the sum of Chef's current money ($X$) and the money he can borrow ($Y$) is sufficient to cover the cost of the socks ($A$). 

Mathematically, Chef can afford the socks if:
$$X + Y \geq A$$

If this condition holds true, we output `YES`; otherwise, we output `NO`. Since the constraints involve basic arithmetic, a simple conditional statement is sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single addition and a comparison.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Socks
 * Logic: Chef can afford the socks if his total money (X + Y) is greater than or equal to the cost (A).
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading the cost of socks (A), Chef's money (X), and borrowed money (Y)
    long long A, X, Y;
    if (cin >> A >> X >> Y) {
        // Check if total money (X + Y) is sufficient to cover cost A
        if (X + Y >= A) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```