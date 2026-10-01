# [Keplers Law (KEPLERSLAW)](https://www.codechef.com/problems/KEPLERSLAW)

- **Difficulty Rating**: 992
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to verify if two planets follow Kepler's Third Law of Planetary Motion. Kepler's Third Law states that the square of the orbital period ($T$) is directly proportional to the cube of the semi-major axis of its orbit ($R$). Mathematically, this is expressed as:
$$\frac{T^2}{R^3} = K$$
Given the orbital periods ($T_1, T_2$) and the semi-major axes ($R_1, R_2$) for two planets, we need to determine if the constant $K$ is the same for both, i.e., if $\frac{T_1^2}{R_1^3} = \frac{T_2^2}{R_2^3}$.

## Intuition & Mathematical Observation
To check the equality $\frac{T_1^2}{R_1^3} = \frac{T_2^2}{R_2^3}$ without dealing with floating-point precision errors (which can occur with division), we can use **cross-multiplication**.

By multiplying both sides by $R_1^3 \times R_2^3$, the equation becomes:
$$T_1^2 \times R_2^3 = T_2^2 \times R_1^3$$

Given the constraints ($T, R \le 10$), the maximum value for these terms is $10^2 \times 10^3 = 10^5$. This fits comfortably within a standard 32-bit integer, though `long long` is used in the implementation for safety and best practices.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations for each input, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Kepler's Law
 * Kepler's 3rd Law states: T^2 / R^3 = constant
 * We need to check if (T1^2 / R1^3) == (T2^2 / R2^3)
 * To avoid floating point precision issues, we can cross-multiply:
 * T1^2 * R2^3 == T2^2 * R1^3
 * 
 * Constraints are small (up to 10), so standard integer types are sufficient.
 * Using long long to be safe against any potential overflow, though not strictly 
 * necessary given the constraints (10^2 * 10^3 = 10^5).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long t1, t2, r1, r2;
        cin >> t1 >> t2 >> r1 >> r2;
        
        // Calculate T1^2 * R2^3 and T2^2 * R1^3
        long long lhs = (t1 * t1) * (r2 * r2 * r2);
        long long rhs = (t2 * t2) * (r1 * r1 * r1);
        
        if (lhs == rhs) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
```