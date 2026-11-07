# [Good Quality Bulbs (BULBLIFE)](https://www.codechef.com/problems/BULBLIFE)

- **Difficulty Rating**: 846
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the lifetimes of $N-1$ bulbs and a target average lifetime $X$. We need to find the minimum non-negative integer lifetime $Y$ for the $N$-th bulb such that the average lifetime of all $N$ bulbs is at least $X$.

## Intuition & Mathematical Observation
The average of $N$ bulbs is defined as:
$$\frac{\sum_{i=1}^{N-1} A_i + Y}{N} \ge X$$

Let $S$ be the sum of the lifetimes of the $N-1$ given bulbs ($S = \sum_{i=1}^{N-1} A_i$). The inequality becomes:
$$S + Y \ge N \times X$$
$$Y \ge (N \times X) - S$$

Since the lifetime $Y$ cannot be negative, if the calculated value $(N \times X) - S$ is less than 0, it means the current bulbs already satisfy the average requirement even if the $N$-th bulb has a lifetime of 0. Therefore, the answer is $\max(0, N \times X - S)$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N-1$ bulbs once to calculate their sum.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N bulbs in total. We are given the lifetimes of N-1 bulbs.
 * Let the sum of the given N-1 bulbs be S.
 * Let the lifetime of the N-th bulb be Y.
 * The condition for the average lifetime is:
 * (S + Y) / N >= X
 * 
 * Multiplying by N (since N > 0):
 * S + Y >= N * X
 * Y >= N * X - S
 * 
 * Since Y must be a non-negative integer, the minimum value of Y is:
 * max(0, N * X - S)
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    
    long long sum_given = 0;
    for (int i = 0; i < N - 1; ++i) {
        long long a;
        cin >> a;
        sum_given += a;
    }
    
    // The required sum for all N bulbs to have an average of at least X is N * X.
    long long required_total_sum = (long long)N * X;
    
    // The remaining bulb Y must satisfy: sum_given + Y >= required_total_sum
    // Y >= required_total_sum - sum_given
    long long Y = required_total_sum - sum_given;
    
    // Since Y must be non-negative, if the calculated Y is negative, 
    // it means the current sum already satisfies the condition even if Y = 0.
    if (Y < 0) {
        cout << 0 << "\n";
    } else {
        cout << Y << "\n";
    }
}

int main() {
    // Fast I/O
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