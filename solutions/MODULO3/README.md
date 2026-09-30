# [Divisible by 3 (MODULO3)](https://www.codechef.com/problems/MODULO3)

- **Difficulty Rating**: 978
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we are allowed to perform an operation where we replace one of the numbers with the absolute difference of the two numbers ($|A - B|$). We want to find the minimum number of operations required to make either $A$ or $B$ divisible by 3.

## Intuition & Mathematical Observation
Since we only care about divisibility by 3, we can work with the remainders of $A$ and $B$ modulo 3. Let $a = A \pmod 3$ and $b = B \pmod 3$. The possible values for $a$ and $b$ are $\{0, 1, 2\}$.

1.  **Case 0 (Already Divisible):** If $a = 0$ or $b = 0$, the condition is already satisfied. **Operations: 0**.
2.  **Case 1 (Same Remainders):** If $a = b$ (where $a, b \neq 0$), then $|A - B| \pmod 3$ will be $|a - a| \pmod 3 = 0$. By replacing either $A$ or $B$ with $|A - B|$, we make that number divisible by 3. **Operations: 1**.
3.  **Case 2 (Different Non-zero Remainders):** If $\{a, b\} = \{1, 2\}$, then $|A - B| \pmod 3$ will be $|1 - 2| \pmod 3 = 1$ (or $|2 - 1| \pmod 3 = 1$). 
    *   After 1 operation, the pair becomes $(1, 1)$ or $(2, 2)$.
    *   As established in Case 1, it takes 1 additional operation to reach 0.
    *   **Total Operations: 2**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and comparisons. The total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two numbers A and B. We want to reach a state where A % 3 == 0 or B % 3 == 0.
 * Let a = A % 3 and b = B % 3.
 * Possible values for a and b are {0, 1, 2}.
 * 
 * Summary:
 * - If a == 0 or b == 0: 0 operations.
 * - If a == b: 1 operation.
 * - If {a, b} == {1, 2}: 2 operations.
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    int a = A % 3;
    int b = B % 3;

    if (a == 0 || b == 0) {
        cout << 0 << "\n";
    } else if (a == b) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
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