# [Factorial (FCTRL)](https://www.codechef.com/problems/FCTRL)

- **Difficulty Rating**: 878
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, the task is to find the number of trailing zeros in the decimal representation of $N!$ (N factorial). Since $N$ can be as large as $10^9$, we need an efficient way to calculate this without computing the actual factorial.

## Intuition & Mathematical Observation
A trailing zero is created by the product of $2 \times 5$. In the prime factorization of $N!$, the number of trailing zeros is determined by the number of pairs of $(2, 5)$. 

Since factors of 2 are much more abundant than factors of 5 in any factorial, the number of trailing zeros is strictly limited by the number of times the prime factor **5** appears in the prime factorization of $N!$.

According to **Legendre's Formula**, the exponent of a prime $p$ in $N!$ is:
$$E_p(N!) = \sum_{k=1}^{\infty} \lfloor \frac{N}{p^k} \rfloor$$

For $p=5$, we calculate:
$$\text{Trailing Zeros} = \lfloor \frac{N}{5} \rfloor + \lfloor \frac{N}{25} \rfloor + \lfloor \frac{N}{125} \rfloor + \dots$$
We continue this summation until $5^k > N$.

## Complexity Analysis
- **Time Complexity**: $O(T \times \log_5 N)$, where $T$ is the number of test cases. Since $\log_5(10^9) \approx 13$, the solution performs very few operations per test case, easily fitting within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the count and the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The number of trailing zeros in N! is determined by the number of times 
 * the factor 5 appears in the prime factorization of N!.
 * 
 * Using Legendre's Formula:
 * Count = floor(N/5) + floor(N/25) + floor(N/125) + ...
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;
    
    long long count = 0;
    // Divide n by powers of 5 and add to count
    // Each iteration effectively calculates floor(N/5^k)
    while (n >= 5) {
        n /= 5;
        count += n;
    }
    cout << count << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```