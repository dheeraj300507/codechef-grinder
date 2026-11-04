# [To Divide or Not To Divide (DIVAB)](https://www.codechef.com/problems/DIVAB)

- **Difficulty Rating**: 1224
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $A$, $B$, and $N$, we need to find the smallest integer $X$ such that:
1. $X \ge N$
2. $X$ is divisible by $A$ ($X \pmod A = 0$)
3. $X$ is not divisible by $B$ ($X \pmod B \neq 0$)

If no such $X$ exists, output $-1$.

## Intuition & Mathematical Observation

1. **Existence Condition**: If $A$ is a multiple of $B$ ($A \pmod B = 0$), then any multiple of $A$ will also be a multiple of $B$. Since we require $X$ to be a multiple of $A$ but *not* $B$, it is impossible to satisfy the condition. In this case, the answer is $-1$.

2. **Finding the Candidate**: We first find the smallest multiple of $A$ that is greater than or equal to $N$. This can be calculated using integer division:
   $$X = \left\lceil \frac{N}{A} \right\rceil \times A = \left( \frac{N + A - 1}{A} \right) \times A$$

3. **Checking the Condition**:
   - If $X \pmod B \neq 0$, then $X$ is our answer.
   - If $X \pmod B = 0$, we check the next multiple of $A$, which is $X + A$. 
   - Since we already established that $A$ is not a multiple of $B$ (otherwise we would have returned $-1$), adding $A$ to a multiple of $B$ will result in a number that is not divisible by $B$. Specifically:
     $$(X + A) \pmod B = (X \pmod B + A \pmod B) \pmod B = (0 + A \pmod B) \pmod B = A \pmod B$$
     Since $A \pmod B \neq 0$, the condition $X \pmod B \neq 0$ is guaranteed to be satisfied by $X + A$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need the smallest integer X such that:
 * 1. X >= N
 * 2. X % A == 0
 * 3. X % B != 0
 */

void solve() {
    long long A, B, N;
    cin >> A >> B >> N;

    // If A is a multiple of B, any multiple of A is also a multiple of B.
    // Therefore, no number can be divisible by A and NOT divisible by B.
    if (A % B == 0) {
        cout << -1 << "\n";
        return;
    }

    // Find the smallest multiple of A that is >= N
    long long X = ((N + A - 1) / A) * A;

    // If X is not divisible by B, it's our answer.
    if (X % B != 0) {
        cout << X << "\n";
    } else {
        // Otherwise, the next multiple of A (X + A) will work
        // because A is not divisible by B.
        cout << X + A << "\n";
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