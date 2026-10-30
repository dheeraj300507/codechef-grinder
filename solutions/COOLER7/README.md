# [Cooler (COOLER7)](https://www.codechef.com/problems/COOLER7)

- **Difficulty Rating**: 555
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to calculate the total time required to cool a device from an initial temperature $N$ to a target temperature $M$. The rule provided is that cooling the device from temperature $T$ to $T-1$ takes exactly $T$ minutes. We need to find the sum of time taken for each step from $N$ down to $M$.

## Intuition & Mathematical Observation
To cool the device from $N$ to $M$, we perform a series of steps:
1. $N \to N-1$ takes $N$ minutes.
2. $N-1 \to N-2$ takes $N-1$ minutes.
3. ...
4. $(M+1) \to M$ takes $M+1$ minutes.

The total time is the sum of integers from $M+1$ to $N$:
$$\text{Total Time} = N + (N-1) + (N-2) + \dots + (M+1)$$

This is an arithmetic progression. The formula for the sum of an arithmetic series is:
$$\text{Sum} = \frac{\text{number of terms} \times (\text{first term} + \text{last term})}{2}$$

- **Number of terms**: $N - M$
- **First term**: $N$
- **Last term**: $M+1$

Substituting these into the formula:
$$\text{Total Time} = \frac{(N - M) \times (N + M + 1)}{2}$$

Since $N \le 40$, the result is small and fits comfortably within a standard `long long` (or even `int`) data type.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation is performed using a constant-time mathematical formula.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To drop the temperature from T to T-1, it takes T minutes.
 * To go from N to M, we need to perform (N - M) steps.
 * The total time is the sum of integers from (M+1) to N.
 * Sum = N + (N-1) + ... + (M+1)
 * 
 * Using the arithmetic progression sum formula:
 * Sum = (Number of terms) * (First term + Last term) / 2
 * Number of terms = N - M
 * Sum = (N - M) * (N + M + 1) / 2
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // Calculate total time using the derived formula
        long long total_time = (n + m + 1) * (n - m) / 2;
        
        cout << total_time << "\n";
    }

    return 0;
}
```