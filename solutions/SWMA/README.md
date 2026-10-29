# [Swapping Marks Digits (SWMA)](https://www.codechef.com/problems/SWMA)

- **Difficulty Rating**: 964
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each have a two-digit score (guaranteed to contain no zeros). Alice is allowed to swap the digits of her score, and Bob is allowed to swap the digits of his score. We need to determine if it is possible for Alice's final score to be strictly greater than Bob's final score after any combination of these swaps.

## Intuition & Mathematical Observation
Since each player has only two digits, there are only two possible states for each person: their original score and their reversed score. 

Let $A$ be Alice's score and $B$ be Bob's score. Let $A_{rev}$ and $B_{rev}$ be the scores obtained by swapping the digits of $A$ and $B$, respectively. The possible pairs of final scores $(A', B')$ are:
1. $(A, B)$
2. $(A_{rev}, B)$
3. $(A, B_{rev})$
4. $(A_{rev}, B_{rev})$

We simply need to check if $A' > B'$ holds true for **any** of these four combinations. If at least one condition is met, the answer is "Yes"; otherwise, it is "No".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are performing a constant number of arithmetic operations and comparisons regardless of the input values, the execution time is constant.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the scores and their reversed versions, requiring no extra data structures that scale with input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has score A (two digits, no zero).
 * Bob has score B (two digits, no zero).
 * Alice can reverse her score (A_rev) and/or Bob's score (B_rev).
 * There are 4 possible scenarios for the final scores (A', B'):
 * 1. (A, B)
 * 2. (A_rev, B)
 * 3. (A, B_rev)
 * 4. (A_rev, B_rev)
 * 
 * We need to check if in any of these scenarios, A' > B'.
 */

int reverse_num(int n) {
    int tens = n / 10;
    int ones = n % 10;
    return ones * 10 + tens;
}

void solve() {
    int A, B;
    cin >> A >> B;
    
    int A_rev = reverse_num(A);
    int B_rev = reverse_num(B);
    
    // Check all 4 combinations
    if (A > B || A_rev > B || A > B_rev || A_rev > B_rev) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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