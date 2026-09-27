# [Balls and Boxes (BALLBOX)](https://www.codechef.com/problems/BALLBOX)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ balls and $K$ boxes, determine if it is possible to distribute all $N$ balls into the $K$ boxes such that:
1. Every box contains at least one ball.
2. No two boxes contain the same number of balls.

## Intuition & Mathematical Observation
To satisfy the condition that every box has a distinct number of balls and at least one ball, the most efficient way to use the balls is to assign the smallest possible distinct positive integers to the boxes: $1, 2, 3, \dots, K$.

The sum of these $K$ integers is given by the arithmetic series formula:
$$\text{Sum} = \sum_{i=1}^{K} i = \frac{K(K + 1)}{2}$$

*   **If $N < \frac{K(K+1)}{2}$**: It is impossible to satisfy the conditions because even the smallest possible distribution requires more balls than we have.
*   **If $N \ge \frac{K(K+1)}{2}$**: It is always possible. We can fill the first $K-1$ boxes with $1, 2, \dots, K-1$ balls respectively. The remaining balls, $N - \frac{(K-1)K}{2}$, will be placed in the $K$-th box. Since $N \ge \frac{K(K+1)}{2}$, the $K$-th box will receive at least $K$ balls, ensuring all values are distinct and each box has at least one ball.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic comparison. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated minimum sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N balls into K boxes such that:
 * 1. Each box has at least 1 ball.
 * 2. No two boxes have the same number of balls.
 * 
 * The minimum sum of K distinct positive integers is K * (K + 1) / 2.
 * If N is at least this sum, we can always distribute the balls.
 */

void solve() {
    long long N, K;
    cin >> N >> K;

    // The minimum sum of K distinct positive integers is K*(K+1)/2
    // Using long long to prevent overflow for K up to 10^4
    long long min_sum = K * (K + 1) / 2;

    if (N >= min_sum) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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