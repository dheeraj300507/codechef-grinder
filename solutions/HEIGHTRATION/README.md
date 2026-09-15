# [Height of Rationals (HEIGHTRATION)](https://www.codechef.com/problems/HEIGHTRATION)

- **Difficulty Rating**: 405
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $a$ and $b$ representing a fraction $\frac{a}{b}$, the "height" of this rational number is defined as the maximum of the numerator and the denominator. The task is to output $\max(a, b)$ for the given input.

## Intuition & Mathematical Observation
The problem explicitly defines the height of a rational number $\frac{a}{b}$ as $\max(a, b)$. Since the constraints are small ($1 \le a, b \le 100$), we do not need any complex algorithms or data structures. We simply need to read the two integers from the standard input and print the larger value using the built-in `max()` function.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of operations (reading two integers and comparing them).
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the two integers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Height of Rationals
 * The height of a fraction a/b is defined as max(a, b).
 * Given the constraints 1 <= a, b <= 100, we simply read two integers
 * and output the maximum of the two.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    
    // Read the two integers a and b
    if (cin >> a >> b) {
        // Output the maximum of the two as per the problem definition
        cout << max(a, b) << "\n";
    }

    return 0;
}
```