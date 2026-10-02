# [Rivalry (CPRIVAL)](https://www.codechef.com/problems/CPRIVAL)

- **Difficulty Rating**: 501
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the winner of a rivalry between two individuals, "Dominater" and "Everule," based on their final ratings. We are given their initial ratings ($R_1, R_2$) and the rating changes ($D_1, D_2$) they received after a contest. The final rating is calculated as the sum of the initial rating and the rating change. We must output the name of the person who has the higher final rating.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic comparison. 
1. Calculate the final rating for Dominater: $F_1 = R_1 + D_1$.
2. Calculate the final rating for Everule: $F_2 = R_2 + D_2$.
3. Compare $F_1$ and $F_2$:
   - If $F_1 > F_2$, Dominater wins.
   - Otherwise, Everule wins.

Since the constraints are small (ratings are typically within standard integer ranges), simple addition and a conditional `if-else` statement are sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of arithmetic operations and comparisons regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the four input variables and the two calculated results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Rivalry
 * The task is to compare the final ratings of two individuals after a contest.
 * Final Rating = Initial Rating + Rating Change.
 * We use long long to prevent any potential overflow, although int is sufficient
 * given the constraints (max 3000 + 200 = 3200).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long R1, R2;
    long long D1, D2;

    // Read initial ratings
    if (!(cin >> R1 >> R2)) return 0;
    // Read rating changes
    if (!(cin >> D1 >> D2)) return 0;

    // Calculate final ratings
    long long final_dominater = R1 + D1;
    long long final_everule = R2 + D2;

    // Compare and output the winner
    if (final_dominater > final_everule) {
        cout << "Dominater" << "\n";
    } else {
        cout << "Everule" << "\n";
    }

    return 0;
}
```