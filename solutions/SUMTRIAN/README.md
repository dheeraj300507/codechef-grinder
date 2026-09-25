# [Sums in a Triangle (SUMTRIAN)](https://www.codechef.com/problems/SUMTRIAN)

- **Difficulty Rating**: 869
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a triangle of numbers, we need to find the maximum sum of a path starting from the top vertex and moving to adjacent numbers on the row below until we reach the base of the triangle. Specifically, from an element at index `(i, j)`, one can move to either `(i+1, j)` or `(i+1, j+1)`.

## Intuition & Mathematical Observation
This is a classic Dynamic Programming problem. While one might initially consider a greedy approach (always picking the larger child), that strategy fails because a smaller number might lead to a much larger sum further down the path.

To solve this optimally, we use **Bottom-Up Dynamic Programming**:
1. Instead of calculating from the top down, we start from the second-to-last row and work our way up to the top.
2. For any element at `triangle[i][j]`, the maximum path sum starting from this position to the bottom is the value of the current element plus the maximum of the two possible paths below it: `max(triangle[i+1][j], triangle[i+1][j+1])`.
3. By updating the triangle in-place, `triangle[0][0]` will eventually contain the maximum path sum for the entire triangle.

This approach avoids recursion and redundant calculations, ensuring an efficient solution.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$, where $N$ is the number of rows in the triangle. We visit each element in the triangle exactly once during the bottom-up update.
- **Space Complexity**: $O(N^2)$ to store the triangle. This could be optimized to $O(N)$ by only storing the current and previous rows, but given $N < 100$, $O(N^2)$ is well within limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We use a bottom-up DP approach. By starting from the second-to-last row,
 * we calculate the maximum path sum for each node based on the results
 * already computed for the row below it.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    // Using a 2D vector to store the triangle
    vector<vector<int>> triangle(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    // Bottom-up DP approach
    // We modify the triangle in-place to store the max path sums
    // Start from the second to last row and move upwards
    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    // The result is at the top of the triangle
    cout << triangle[0][0] << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```