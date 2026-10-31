# [Chef and Serves (CHSERVE)](https://www.codechef.com/problems/CHSERVE)

- **Difficulty Rating**: 1101
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of table tennis, Chef and Cook take turns serving. The serve changes every $K$ points. Specifically, the first $K$ points are served by Chef, the next $K$ points by Cook, the next $K$ by Chef, and so on. Given the current scores of Chef ($P_1$) and Cook ($P_2$) and the value of $K$, determine whose turn it is to serve.

## Intuition & Mathematical Observation
The total number of points played in the game is $S = P_1 + P_2$. Since the serve changes every $K$ points, we can determine how many "service cycles" have been completed by calculating:
$$\text{cycles} = \lfloor \frac{S}{K} \rfloor$$

By observing the pattern:
- If $\text{cycles}$ is **even** ($0, 2, 4, \dots$), it is Chef's turn.
- If $\text{cycles}$ is **odd** ($1, 3, 5, \dots$), it is Cook's turn.

This logic holds because every $K$ points, the server switches. The first $K$ points (0 to $K-1$) result in a quotient of 0 (even), the next $K$ points ($K$ to $2K-1$) result in a quotient of 1 (odd), and so on.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
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
 * Pattern:
 * - Points 0 to K-1: Chef serves (Quotient 0 -> Even)
 * - Points K to 2K-1: Cook serves (Quotient 1 -> Odd)
 * - Points 2K to 3K-1: Chef serves (Quotient 2 -> Even)
 * 
 * Rule:
 * Calculate total points S = P1 + P2.
 * Calculate cycles = S / K.
 * If cycles is even, it is Chef's turn.
 * If cycles is odd, it is Cook's turn.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;

        long long total_points = p1 + p2;
        long long cycles = total_points / k;

        // Check parity of the completed cycles
        if (cycles % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }

    return 0;
}
```