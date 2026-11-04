# [Valid Expression (EVALMAS)](https://www.codechef.com/problems/EVALMAS)

- **Difficulty Rating**: 1354
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ operators and $N+1$ ones, we need to construct an expression using these ones and operators such that the final evaluated result is exactly $X$. The operators available are `+`, `-`, and `*`. Multiplication has higher precedence than addition and subtraction. If no such expression exists, output -1.

## Intuition & Mathematical Observation
1. **Precedence Rules**: Since all operands are `1`, any chain of multiplications (e.g., `1 * 1 * 1`) will always evaluate to `1`.
2. **Range Constraints**: 
   - The maximum value we can achieve is by using all `+` operators: $1 + 1 + 1 ... + 1 = N + 1$.
   - The minimum value we can achieve is by using all `-` operators: $1 - 1 - 1 ... - 1 = 1 - N$.
   - If $X$ is outside the range $[1-N, N+1]$, it is impossible to reach $X$, so we output `-1`.
3. **Strategy**:
   - We start with a base value of `1`.
   - We have $N$ operator slots. We can use `+` to increment the current value, `-` to decrement it, and `*` to keep the current value unchanged (since $1 \times 1 = 1$).
   - We iterate through the $N$ slots:
     - If the current value is less than $X$, we use a `+` to increase it.
     - If the current value is greater than $X$, we use a `-` to decrease it.
     - Once the current value equals $X$, we fill the remaining slots with `*` (which keeps the value at $X$ because $X \times 1 = X$).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ operator slots exactly once to construct the string.
- **Space Complexity**: $O(N)$ to store the resulting string of operators.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N+1 ones and N operators.
 * Since all numbers are 1, any multiplication 1*1 results in 1.
 * We can use '+' to increase the total, '-' to decrease it, 
 * and '*' to maintain the current value.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;

    // Check if X is within the reachable range [1-N, N+1]
    if (X > N + 1 || X < 1 - N) {
        cout << -1 << "\n";
        return;
    }

    string s(N, '*');
    long long val = 1;
    
    // Greedily adjust the value to reach X
    for (int i = 0; i < N; ++i) {
        if (val < X) {
            s[i] = '+';
            val++;
        } else if (val > X) {
            s[i] = '-';
            val--;
        } else {
            // Once val == X, remaining operators can be '*'
            s[i] = '*';
        }
    }
    
    // Final check to ensure we reached X
    if (val == X) {
        cout << s << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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