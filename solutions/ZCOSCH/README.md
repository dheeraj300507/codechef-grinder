# [How much Scholarship (ZCOSCH)](https://www.codechef.com/problems/ZCOSCH)

- **Difficulty Rating**: 1012
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to determine the scholarship percentage awarded to a student based on their rank $R$ in a contest. The rules are defined as follows:
- If the rank is between 1 and 50 (inclusive), the student receives a 100% scholarship.
- If the rank is between 51 and 100 (inclusive), the student receives a 50% scholarship.
- If the rank is greater than 100, the student receives a 0% scholarship.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the rank $R$ can be as large as $10^9$, we must ensure our input variable can handle this range. 

The logic follows three distinct intervals:
1. **Interval [1, 50]**: Output `100`.
2. **Interval [51, 100]**: Output `50`.
3. **Interval [101, $\infty$)**: Output `0`.

Using `if-else if-else` statements allows us to categorize the input $R$ efficiently. While a standard 32-bit `int` can hold up to $\approx 2 \times 10^9$, using `long long` is a best practice in competitive programming to prevent potential overflow issues if constraints were to change.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of comparisons regardless of the size of $R$.
- **Space Complexity**: $O(1)$, as we only use a single variable to store the rank.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks to determine the scholarship percentage based on rank R.
 * - If 1 <= R <= 50, scholarship is 100%.
 * - If 51 <= R <= 100, scholarship is 50%.
 * - If R > 100, scholarship is 0%.
 * 
 * Constraints:
 * 1 <= R <= 10^9.
 * Since R can be up to 10^9, a standard 32-bit integer (int) is sufficient, 
 * but using long long is safer practice for competitive programming.
 * Time complexity: O(1) per test case.
 * Space complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long R;
    if (!(cin >> R)) return 0;

    if (R >= 1 && R <= 50) {
        cout << 100 << "\n";
    } else if (R >= 51 && R <= 100) {
        cout << 50 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
```