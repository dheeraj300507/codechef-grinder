# [Devouring Donuts (DEVDON)](https://www.codechef.com/problems/DEVDON)

- **Difficulty Rating**: 241
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total number of calories consumed by a person. We are given two integers: $X$, representing the number of donuts eaten, and $Y$, representing the calories contained in a single donut. The goal is to output the product of $X$ and $Y$.

## Intuition & Mathematical Observation
The problem is a straightforward application of basic arithmetic. Since each donut contains $Y$ calories and the person eats $X$ donuts, the total calories consumed is simply the product:
$$\text{Total Calories} = X \times Y$$

Given the constraints:
- $1 \le X \le 10$
- $200 \le Y \le 300$

The maximum possible value is $10 \times 300 = 3000$. This value is well within the range of a standard 32-bit integer (`int` in C++), so no special handling for large numbers is required.

## Complexity Analysis
- **Time Complexity**: $O(1)$. The solution performs a single multiplication operation, which takes constant time regardless of the input values.
- **Space Complexity**: $O(1)$. We only use a fixed amount of memory to store the variables $X$, $Y$, and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Devouring Donuts
 * The problem asks to calculate the total calories consumed by multiplying 
 * the number of donuts (X) by the calories per donut (Y).
 * 
 * Constraints:
 * 1 <= X <= 10
 * 200 <= Y <= 300
 * 
 * The maximum possible result is 10 * 300 = 3000, which fits easily 
 * within a standard 32-bit integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading X and Y from standard input
    long long X, Y;
    if (cin >> X >> Y) {
        // Calculating total calories
        long long total_calories = X * Y;
        
        // Outputting the result
        cout << total_calories << "\n";
    }

    return 0;
}
```