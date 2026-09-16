# [Netflix (NETFLIX)](https://www.codechef.com/problems/NETFLIX)

- **Difficulty Rating**: 493
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice, Bob, and Charlie want to buy a Netflix subscription that costs $X$ rupees. Each person has a specific amount of money ($A, B,$ and $C$ respectively). We need to determine if any two of them can combine their money to pay for the subscription (i.e., if the sum of any two people's money is greater than or equal to $X$).

## Intuition & Mathematical Observation
The problem asks us to check if at least one pair among the three individuals can afford the subscription. Since there are only three possible pairs, we can explicitly check each combination:
1. Alice and Bob: $A + B \ge X$
2. Alice and Charlie: $A + C \ge X$
3. Bob and Charlie: $B + C \ge X$

If any of these conditions evaluate to true, the output should be `YES`. If none of them satisfy the condition, the output should be `NO`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of arithmetic operations and comparisons regardless of the input values.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three amounts A, B, and C, and a target cost X.
 * We need to check if any pair of the three can sum up to at least X.
 * The possible pairs are:
 * 1. Alice + Bob (A + B)
 * 2. Alice + Charlie (A + C)
 * 3. Bob + Charlie (B + C)
 * 
 * If any of these sums are >= X, the answer is YES, otherwise NO.
 */

void solve() {
    int A, B, C, X;
    if (!(cin >> A >> B >> C >> X)) return;

    // Check all three possible combinations
    if ((A + B >= X) || (A + C >= X) || (B + C >= X)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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