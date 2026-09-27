# [Expense List (EXPENSES)](https://www.codechef.com/problems/EXPENSES)

- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts with an initial monthly income of $2^X$. He has $N$ expenses to cover. For each expense, he spends exactly $50\%$ of his current remaining income. We need to calculate the amount of money remaining after all $N$ expenses are paid.

## Intuition & Mathematical Observation
The problem states that for every expense, Chef spends half of his current balance. Mathematically, this is equivalent to dividing the current amount by 2.

1. **Initial Amount**: $2^X$
2. **After 1st expense**: $\frac{2^X}{2} = 2^{X-1}$
3. **After 2nd expense**: $\frac{2^{X-1}}{2} = 2^{X-2}$
4. **After $N$ expenses**: Following this pattern, after $N$ divisions, the remaining amount will be $2^{X-N}$.

Since the problem guarantees $N < X$, the exponent $(X-N)$ will always be non-negative, ensuring the result is a valid integer. We can efficiently calculate $2^{X-N}$ using the bitwise left-shift operator: `1 << (X - N)`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the bitwise shift operation is performed in constant time. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts with an income of 2^X.
 * For each expense i (from 1 to N), he spends 50% of the remaining amount.
 * This means after each expense, the remaining amount is halved.
 * 
 * Initial amount: 2^X
 * After 1st expense: (2^X) / 2 = 2^(X-1)
 * After 2nd expense: (2^(X-1)) / 2 = 2^(X-2)
 * ...
 * After Nth expense: 2^(X-N)
 * 
 * Since N < X, the result will always be a positive integer.
 * We can compute 2^(X-N) using bitwise shift: 1 << (X - N).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x;
        cin >> n >> x;

        // The remaining amount after N expenses is 2^X / 2^N = 2^(X-N)
        // Using 1LL to ensure the shift operation is performed on a 64-bit integer,
        // preventing overflow for larger values of X.
        long long savings = (1LL << (x - n));
        
        cout << savings << "\n";
    }

    return 0;
}
```