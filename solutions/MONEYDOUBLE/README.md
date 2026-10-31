# [Money Double (MONEYDOUBLE)](https://www.codechef.com/problems/MONEYDOUBLE)

- **Difficulty Rating**: 784
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts with an initial amount of $X$ rupees and has $Y$ years to increase this amount. Each year, Chef can perform exactly one of two operations:
1. **Add 1000**: $X = X + 1000$
2. **Double**: $X = X \times 2$

The goal is to maximize the final amount of money after $Y$ years.

## Intuition & Mathematical Observation
To maximize the final amount, we need to make the optimal choice at each of the $Y$ steps. 

Let's compare the two operations:
- Adding 1000 is more beneficial when the current amount $X$ is small (specifically, when $X < 1000$).
- Doubling is more beneficial when the current amount $X$ is large (specifically, when $X > 1000$).
- If $X = 1000$, both operations result in 2000.

Since $Y$ is very small (up to 10), we can use a **Greedy Approach**. At each year, we calculate the result of both possible operations and choose the one that yields the larger value for the current year. Because the doubling operation is multiplicative, it scales the value significantly; by choosing the maximum at every step, we ensure the growth is maximized over the $Y$-year duration.

## Complexity Analysis
- **Time Complexity**: $O(Y)$ per test case. Since $Y \le 10$, this is effectively $O(1)$ per test case. Given $T$ test cases, the total time complexity is $O(T \times Y)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current amount and the loop index.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * At each year, we have two choices: add 1000 or double the amount.
 * We greedily choose the operation that results in a larger value 
 * for the current year. Given the small constraints (Y <= 10), 
 * this local optimization leads to the global maximum.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Iterate through each year and pick the best operation
        for (int i = 0; i < y; ++i) {
            long long add_option = x + 1000;
            long long double_option = x * 2;
            
            // Greedily choose the maximum of the two options
            if (add_option > double_option) {
                x = add_option;
            } else {
                x = double_option;
            }
        }
        cout << x << "\n";
    }

    return 0;
}
```