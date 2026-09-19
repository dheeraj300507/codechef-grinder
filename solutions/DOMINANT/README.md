# [Dominant Army (DOMINANT)](https://www.codechef.com/problems/DOMINANT)

- **Difficulty Rating**: 488
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the sizes of three armies: $N_A$, $N_B$, and $N_C$. An army is considered "dominant" if its size is strictly greater than the sum of the sizes of the other two armies. We need to determine if any of the three armies is dominant.

## Intuition & Mathematical Observation
The problem defines dominance for a specific army as:
*   **Army A is dominant if:** $N_A > N_B + N_C$
*   **Army B is dominant if:** $N_B > N_A + N_C$
*   **Army C is dominant if:** $N_C > N_A + N_B$

Since we only need to check if *any* of these conditions are true, we can evaluate each condition independently using boolean logic. If at least one condition evaluates to `true`, the output should be `YES`; otherwise, it should be `NO`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input sizes and boolean flags.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Dominant Army
 * Logic: An army is dominant if its size is strictly greater than the sum of the other two.
 * We check this condition for all three kingdoms (A, B, and C).
 * If any of them satisfy the condition, output YES, otherwise NO.
 */

void solve() {
    long long na, nb, nc;
    if (!(cin >> na >> nb >> nc)) return;

    // Check if A is dominant
    bool a_dominant = (na > (nb + nc));
    // Check if B is dominant
    bool b_dominant = (nb > (na + nc));
    // Check if C is dominant
    bool c_dominant = (nc > (na + nb));

    if (a_dominant || b_dominant || c_dominant) {
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