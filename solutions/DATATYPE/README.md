# [Fit in Data Type (DATATYPE)](https://www.codechef.com/problems/DATATYPE)

- **Difficulty Rating**: 1133
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to simulate the behavior of a data type that can only store integers in the range $[0, N]$. When a value $X$ is assigned to this data type, if $X$ is greater than $N$, it "wraps around" in a cyclic manner. We need to determine the final value stored in the data type after assigning $X$.

## Intuition & Mathematical Observation
The data type supports $N+1$ distinct values: $\{0, 1, 2, \dots, N\}$. 

When a value $X$ is assigned:
1. If $X \le N$, the value remains $X$.
2. If $X > N$, the value wraps around. This behavior is identical to the mathematical modulo operation. Since there are $N+1$ possible states, the value effectively resets every time it exceeds $N$.

Therefore, the final value stored is simply:
$$\text{Result} = X \pmod{N + 1}$$

For example, if $N=15$, the range is $0$ to $15$ (16 values). If $X=16$, $16 \pmod{16} = 0$. If $X=17$, $17 \pmod{16} = 1$. This matches the cyclic behavior of fixed-width integer types in programming.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The data type stores values in the range [0, N].
 * This means there are N + 1 possible values (0, 1, 2, ..., N).
 * When a value X is provided, if X > N, it wraps around.
 * The wrap-around behavior is equivalent to the modulo operation.
 * Specifically, the value stored is X % (N + 1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        // The range is 0 to N, so there are N + 1 distinct values.
        // The cyclic behavior is defined by modulo (N + 1).
        long long result = x % (n + 1);
        
        cout << result << "\n";
    }
    
    return 0;
}
```