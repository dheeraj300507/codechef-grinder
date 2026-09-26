# [Paper Cutting (CUTPAPER)](https://www.codechef.com/problems/CUTPAPER)

- **Difficulty Rating**: 800
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a square piece of paper of size $N \times N$, we need to determine the maximum number of smaller squares of size $K \times K$ that can be cut from it.

## Intuition & Mathematical Observation
To maximize the number of $K \times K$ squares, we consider how many squares can fit along each dimension of the $N \times N$ paper:
1. Along one side of length $N$, the number of segments of length $K$ that can fit is given by the integer division $\lfloor N / K \rfloor$.
2. Since the paper is a square, we can fit $\lfloor N / K \rfloor$ squares along the width and $\lfloor N / K \rfloor$ squares along the height.
3. The total number of $K \times K$ squares is the product of the number of squares along the width and the height:
   $$\text{Total} = \lfloor N / K \rfloor \times \lfloor N / K \rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a square paper of size N x N.
 * We want to cut out squares of size K x K.
 * Along one side of length N, we can fit floor(N / K) squares of length K.
 * Since the paper is a square, we can fit floor(N / K) squares along the width
 * and floor(N / K) squares along the height.
 * The total number of K x K squares is (N / K) * (N / K).
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Calculate how many squares fit along one dimension
        long long side_count = n / k;

        // Total squares is the product of squares along both dimensions
        long long total_squares = side_count * side_count;

        cout << total_squares << "\n";
    }

    return 0;
}
```