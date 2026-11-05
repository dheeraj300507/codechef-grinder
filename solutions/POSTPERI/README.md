# [Poster Perimeter (POSTPERI)](https://www.codechef.com/problems/POSTPERI)

- **Difficulty Rating**: 812
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a grid of size $N \times M$, we need to choose a rectangular poster with dimensions $l \times w$ (where $1 \le l \le N$ and $1 \le w \le M$). The goal is to minimize the absolute difference between the perimeter of the rectangle, $2 \times (l + w)$, and a target value $K$. That is, we want to minimize $|2(l + w) - K|$.

## Intuition & Mathematical Observation
The constraints for $N, M,$ and $K$ are small ($N, M, K \le 100$). This allows us to use a **Brute Force** approach. Since the total number of possible rectangles is $N \times M$, and the maximum value for $N \times M$ is $10,000$, we can simply iterate through every possible combination of $l$ and $w$.

For each pair $(l, w)$:
1. Calculate the perimeter: $P = 2 \times (l + w)$.
2. Calculate the absolute difference: $diff = |P - K|$.
3. Keep track of the minimum difference found so far.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times M)$, where $T$ is the number of test cases. Given the constraints, the maximum number of operations is approximately $100 \times 100 \times 100 = 10^6$, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the current dimensions and the minimum difference.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N, M, and K. We need to find integers l (1 <= l <= N) and w (1 <= w <= M)
 * such that |2 * (l + w) - K| is minimized.
 * 
 * Constraints:
 * N, M, K <= 100.
 * Since the constraints are very small (up to 100), we can iterate through all possible
 * values of l and w using nested loops.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int min_diff = INT_MAX;

        // Iterate through all possible lengths and widths
        for (int l = 1; l <= n; ++l) {
            for (int w = 1; w <= m; ++w) {
                int perimeter = 2 * (l + w);
                int current_diff = abs(perimeter - k);
                
                if (current_diff < min_diff) {
                    min_diff = current_diff;
                }
            }
        }

        cout << min_diff << "\n";
    }

    return 0;
}
```