# [A or B (AORB)](https://www.codechef.com/problems/AORB)

- **Difficulty Rating**: 728
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is solving two problems, A and B. 
- Problem A gives $500$ points initially, with a penalty of $2$ points per minute spent.
- Problem B gives $1000$ points initially, with a penalty of $4$ points per minute spent.

Given the time taken to solve problem A ($X$) and problem B ($Y$), we need to determine the maximum total score Chef can achieve by choosing the optimal order to solve the problems (either A then B, or B then A).

## Intuition & Mathematical Observation
To maximize the score, we must calculate the total points for both possible sequences:

1. **Order A then B:**
   - Problem A is submitted at time $X$. Score: $500 - 2X$.
   - Problem B is submitted at time $X + Y$. Score: $1000 - 4(X + Y)$.
   - Total Score = $(500 - 2X) + (1000 - 4(X + Y))$.

2. **Order B then A:**
   - Problem B is submitted at time $Y$. Score: $1000 - 4Y$.
   - Problem A is submitted at time $X + Y$. Score: $500 - 2(X + Y)$.
   - Total Score = $(1000 - 4Y) + (500 - 2(X + Y))$.

By calculating both values and taking the `max()`, we ensure the optimal strategy is chosen.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated scores.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two problems, A and B.
 * Points for A: 500 - (time_A * 2)
 * Points for B: 1000 - (time_B * 4)
 * 
 * Order 1: A then B
 * Time A = X, Time B = X + Y
 * Total = (500 - 2*X) + (1000 - 4*(X + Y))
 * 
 * Order 2: B then A
 * Time B = Y, Time A = X + Y
 * Total = (1000 - 4*Y) + (500 - 2*(X + Y))
 * 
 * We calculate both and take the maximum.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // Order A -> B
    // A is submitted at time X
    // B is submitted at time X + Y
    long long score1 = (500 - 2 * X) + (1000 - 4 * (X + Y));

    // Order B -> A
    // B is submitted at time Y
    // A is submitted at time X + Y
    long long score2 = (1000 - 4 * Y) + (500 - 2 * (X + Y));

    cout << max(score1, score2) << "\n";
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