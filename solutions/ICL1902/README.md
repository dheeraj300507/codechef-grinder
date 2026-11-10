# [FlatLand (ICL1902)](https://www.codechef.com/problems/ICL1902)

- **Difficulty Rating**: 1117
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$ representing the number of circles, we need to partition these circles into the minimum number of squares. In each step, we are allowed to take the largest possible square of size $S \times S$ such that $S^2 \le N$, remove those circles from the total, and repeat the process until no circles remain. The goal is to find the total number of squares formed.

## Intuition & Mathematical Observation
The problem asks for a greedy approach: at any given state $N$, we want to subtract the largest possible perfect square $S^2$ (where $S = \lfloor\sqrt{N}\rfloor$). 

**Why Greedy works:**
Since we want to minimize the number of squares used to represent $N$, and we are constrained by the rule of always picking the largest possible square at each step, the greedy strategy is optimal for this specific problem constraint. Because $N \le 1000$, the number of steps will be very small (in fact, by Lagrange's four-square theorem, any natural number can be represented as the sum of four integer squares, so the loop will terminate very quickly).

1. Calculate $S = \lfloor\sqrt{N}\rfloor$.
2. Subtract $S^2$ from $N$.
3. Increment the counter.
4. Repeat until $N = 0$.

## Complexity Analysis
- **Time Complexity**: $O(T \times \sqrt{N})$, where $T$ is the number of test cases. Since the value of $N$ decreases rapidly (at least by half or more in most steps), the number of iterations per test case is very small, making this highly efficient.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N circles. We need to form the largest possible square of side S (S^2 <= N).
 * After forming the square, we are left with N - S^2 circles.
 * We repeat this process until no circles are left.
 * Since N <= 1000, a simple greedy approach will work perfectly.
 */

void solve() {
    int N;
    cin >> N;
    
    int count = 0;
    while (N > 0) {
        // Find the largest integer S such that S*S <= N
        int s = sqrt(N);
        
        // Subtract the circles used for this square
        N -= (s * s);
        
        // Increment the number of squares formed
        count++;
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
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