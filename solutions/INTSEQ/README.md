# [An Interesting Sequence (INTSEQ)](https://www.codechef.com/problems/INTSEQ)

- **Difficulty Rating**: 1393
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $K$, we need to find the length of the longest sequence $A_1, A_2, \dots, A_N$ such that for every $i \in [1, N]$, the condition $A_i + S_i = K$ holds, where $S_i$ is the prefix sum $A_1 + A_2 + \dots + A_i$. All elements $A_i$ must be positive integers.

## Intuition & Mathematical Observation
Let's analyze the recurrence relation provided by the condition $A_i + S_i = K$:

1.  **For $i=1$**: $A_1 + S_1 = A_1 + A_1 = 2A_1 = K$. Thus, $A_1 = \frac{K}{2}$.
2.  **For $i > 1$**: We have $A_i + S_i = K$ and $A_{i-1} + S_{i-1} = K$.
    Since $S_i = S_{i-1} + A_i$, substituting this into the first equation gives:
    $A_i + S_{i-1} + A_i = K \implies 2A_i = K - S_{i-1}$.
    From the previous step, $S_{i-1} = K - A_{i-1}$. Substituting this:
    $2A_i = K - (K - A_{i-1}) = A_{i-1} \implies A_i = \frac{A_{i-1}}{2}$.

This reveals that the sequence is a geometric progression where each term is half of the previous term: $A_i = \frac{A_1}{2^{i-1}}$. For all $A_i$ to be integers, $A_1$ must be divisible by $2^{N-1}$. 

Since $A_1 = \frac{K}{2}$, we require $\frac{K}{2}$ to be divisible by $2^{N-1}$, which simplifies to $K$ being divisible by $2^N$. Therefore, the maximum length $N$ is simply the exponent of the highest power of 2 that divides $K$ (also known as the 2-adic valuation of $K$).

## Complexity Analysis
- **Time Complexity**: $O(\log K)$ per test case, as we are repeatedly dividing $K$ by 2 until it becomes odd.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition A_i + S_i = K leads to the recurrence A_i = A_{i-1} / 2.
 * This implies A_1 = K/2, A_2 = K/4, ..., A_N = K / 2^N.
 * For A_N to be an integer, K must be divisible by 2^N.
 * The maximum N is the number of times K is divisible by 2.
 */

void solve() {
    long long K;
    cin >> K;
    
    // Count the number of times K is divisible by 2
    int count = 0;
    while (K > 0 && K % 2 == 0) {
        count++;
        K /= 2;
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```