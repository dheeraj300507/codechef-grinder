# [Marbles (SPCP3)](https://www.codechef.com/problems/SPCP3)

- **Difficulty Rating**: 1385
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $A$ marbles and his friend has $B$ marbles. We want to redistribute the total number of marbles $S = A + B$ such that Chef has $A'$ marbles and his friend has $B'$ marbles, where $A' \ge 1$, $B' \ge 1$, and $A'$ is perfectly divisible by $B'$ (i.e., $A' = k \cdot B'$ for some integer $k \ge 1$). The goal is to minimize the number of marbles transferred, which is equivalent to minimizing $|B - B'|$.

## Intuition & Mathematical Observation
1. **Total Marbles**: The total sum $S = A + B$ remains constant throughout the redistribution.
2. **Divisibility Constraint**: Since $A' + B' = S$ and $A' = k \cdot B'$, we can substitute to get:
   $k \cdot B' + B' = S \implies B'(k + 1) = S$.
   This implies that $B'$ must be a divisor of $S$.
3. **Constraints on $B'$**: Since $A' \ge 1$, it follows that $B' = S - A' \le S - 1$. Also, the problem states $B' \ge 1$. Thus, $B'$ must be a divisor of $S$ in the range $[1, S-1]$.
4. **Minimization**: We need to find a divisor $B'$ of $S$ that minimizes the absolute difference $|B - B'|$. Since $S$ can be up to $2 \cdot 10^5$ (or higher depending on constraints), iterating through all divisors or checking all numbers up to $S$ is efficient enough.

## Complexity Analysis
- **Time Complexity**: $O(\sqrt{S})$ if we find divisors by iterating up to $\sqrt{S}$, or $O(S)$ if we iterate through all numbers up to $S$. Given the constraints, $O(S)$ is well within the time limit for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the minimum difference.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total marbles S = A + B.
 * After redistribution, let Chef have A' and his friend have B'.
 * A' + B' = S, where A' >= 1, B' >= 1.
 * We need A' % B' == 0.
 * This means A' = k * B' for some integer k >= 1.
 * Substituting: k * B' + B' = S => B'(k + 1) = S.
 * So, B' must be a divisor of S, and B' < S (since A' >= 1).
 * 
 * We want to minimize the number of marbles transferred.
 * The number of marbles transferred is |A - A'| = |A - (S - B')| = |A - S + B'| = |B' - B|.
 * 
 * We iterate through all possible values of B' (from 1 to S-1) such that S % B' == 0.
 * For each valid B', calculate the cost |B' - B| and find the minimum.
 */

void solve() {
    long long A, B;
    cin >> A >> B;
    long long S = A + B;
    long long min_transfers = -1;

    // B' is the number of marbles the friend has after redistribution.
    // B' must be a divisor of S, and 1 <= B' <= S-1.
    for (long long B_prime = 1; B_prime < S; ++B_prime) {
        if (S % B_prime == 0) {
            long long transfers = abs(B_prime - B);
            if (min_transfers == -1 || transfers < min_transfers) {
                min_transfers = transfers;
            }
        }
    }
    cout << min_transfers << "\n";
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