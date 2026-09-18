# [Maximise the Tastiness (MAXTASTE)](https://www.codechef.com/problems/MAXTASTE)

- **Difficulty Rating**: 627
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has four ingredients with tastiness values $a, b, c,$ and $d$. He must choose exactly one ingredient from the first pair $\{a, b\}$ and exactly one ingredient from the second pair $\{c, d\}$. The goal is to maximize the total tastiness, which is the sum of the two chosen ingredients.

## Intuition & Mathematical Observation
To maximize the sum of two numbers where each number is chosen from a specific set, we should independently choose the largest possible value from each set. 

1. From the first pair $\{a, b\}$, the maximum value is $\max(a, b)$.
2. From the second pair $\{c, d\}$, the maximum value is $\max(c, d)$.
3. The maximum total tastiness is simply the sum of these two maximums: $\max(a, b) + \max(c, d)$.

Since the constraints are small ($1 \le a, b, c, d \le 100$), this approach is efficient and avoids any potential overflow issues with standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform two comparisons and one addition. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef chooses one from {a, b} and one from {c, d}.
 * The total tastiness is the sum of the two chosen ingredients.
 * To maximize the sum, we pick the maximum of {a, b} and the maximum of {c, d}.
 * Max Tastiness = max(a, b) + max(c, d).
 * 
 * Constraints: 1 <= a, b, c, d <= 100.
 * The sum will not exceed 200, so 'int' is sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Calculate the maximum possible tastiness
        int max_first = max(a, b);
        int max_second = max(c, d);
        int result = max_first + max_second;

        cout << result << "\n";
    }

    return 0;
}
```