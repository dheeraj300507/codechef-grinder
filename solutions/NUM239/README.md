# [Counting Pretty Numbers (NUM239)](https://www.codechef.com/problems/NUM239)

- **Difficulty Rating**: 873
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a range $[L, R]$. A number is defined as "pretty" if its last digit is 2, 3, or 9. The task is to count the total number of pretty numbers within the inclusive range $[L, R]$.

## Intuition & Mathematical Observation
To solve this efficiently for large ranges, we use the prefix sum principle:
$$\text{Result} = f(R) - f(L - 1)$$
where $f(N)$ is a function that counts the number of pretty numbers from $1$ to $N$.

**Key Observations:**
1. **Periodic Pattern:** In every block of 10 consecutive integers (e.g., 0–9, 10–19, 20–29), the last digits repeat the sequence $0, 1, 2, 3, 4, 5, 6, 7, 8, 9$.
2. **Pretty Numbers per Block:** Within any block of 10, there are exactly 3 pretty numbers (those ending in 2, 3, and 9).
3. **Calculating $f(N)$:**
   - The number of full blocks of 10 in $N$ is given by $\lfloor N / 10 \rfloor$. Each block contributes 3 to the count.
   - For the remaining part ($N \pmod{10}$), we manually check if the last digit is $\ge 2$, $\ge 3$, or $\ge 9$ to increment the count accordingly.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are performing a constant number of arithmetic operations regardless of the size of $L$ and $R$, the solution is extremely efficient.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A number is "pretty" if its last digit is 2, 3, or 9.
 * We need to count how many such numbers exist in the range [L, R].
 * 
 * Approach:
 * Let f(N) be the count of pretty numbers in the range [1, N].
 * The answer for [L, R] is f(R) - f(L - 1).
 * 
 * In every block of 10 numbers (e.g., 0-9, 10-19, ...), there are exactly 3 pretty numbers:
 * the ones ending in 2, 3, and 9.
 */

long long countPretty(int n) {
    if (n < 0) return 0;
    // Each full block of 10 contains 3 pretty numbers
    long long count = (n / 10) * 3;
    
    // Check the remaining digits in the incomplete block
    int rem = n % 10;
    if (rem >= 2) count++;
    if (rem >= 3) count++;
    if (rem >= 9) count++;
    
    return count;
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int L, R;
        cin >> L >> R;
        // The count in [L, R] is f(R) - f(L-1)
        cout << countPretty(R) - countPretty(L - 1) << "\n";
    }
    return 0;
}
```