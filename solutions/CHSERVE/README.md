# [Chef and Serves (CHSERVE)](https://www.codechef.com/problems/CHSERVE)

- **Difficulty Rating**: 1101
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of table tennis, Chef and Cook take turns serving. The serve changes every $K$ points. Specifically, Chef starts serving for the first $K$ points (points $0$ to $K-1$), then Cook serves for the next $K$ points (points $K$ to $2K-1$), then Chef serves again, and so on. Given the current scores of Chef ($P1$) and Cook ($P2$), determine whose turn it is to serve.

## Intuition & Mathematical Observation
The total number of points played in the game is $S = P1 + P2$. Since the serve changes every $K$ points, we can determine how many "serve cycles" have passed by calculating:
$$\text{serve\_cycles} = \lfloor \frac{P1 + P2}{K} \rfloor$$

- If `serve_cycles` is **even** ($0, 2, 4, \dots$), it is Chef's turn to serve.
- If `serve_cycles` is **odd** ($1, 3, 5, \dots$), it is Cook's turn to serve.

Using integer division in C++ automatically handles the floor operation, making the logic straightforward. We use `long long` to prevent potential overflow, although the constraints ($10^9$) fit within standard 32-bit integers, it is best practice for competitive programming.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total number of points scored is S = P1 + P2.
 * The serve changes every K points.
 * 
 * - Points 0 to K-1: Chef serves (0 // K = 0)
 * - Points K to 2K-1: Cook serves (1 // K = 0)
 * - Points 2K to 3K-1: Chef serves (2 // K = 0)
 * 
 * The number of times the serve has changed is (P1 + P2) / K.
 * If this value is even, it is Chef's turn.
 * If this value is odd, it is Cook's turn.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;

        long long total_points = p1 + p2;
        long long serve_cycles = total_points / k;

        if (serve_cycles % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }

    return 0;
}
```