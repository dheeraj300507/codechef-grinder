# [Rush to Exam (RUSHTOEXAM)](https://www.codechef.com/problems/RUSHTOEXAM)

- **Difficulty Rating**: 253
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ hours available to study for an exam. In each hour, Chef can read $A$ pages. The exam requires Chef to have read at least $M$ pages to be prepared. Determine if Chef can read enough pages within the given time to meet the requirement.

## Intuition & Mathematical Observation
The problem asks us to compare the total number of pages Chef can read against the target $M$. 
1. Chef studies for $N$ hours.
2. Chef reads $A$ pages per hour.
3. Therefore, the total number of pages read is the product of the hours and the rate: $\text{Total Pages} = N \times A$.
4. We simply need to check if $\text{Total Pages} \ge M$. If the condition holds, output "Yes"; otherwise, output "No".

Given the constraints ($N \le 24, M \le 100, A \le 10$), the maximum possible value for $N \times A$ is 240, which easily fits within a standard integer data type.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations and a single comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Each hour, Chef reads A pages.
 * Total pages Chef can read = N * A.
 * We need to check if (N * A) >= M.
 * 
 * Constraints:
 * N <= 24, M <= 100, A <= 10.
 * The product N * A will be at most 24 * 10 = 240.
 * This fits comfortably within a standard 32-bit integer.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description states the input contains 3 integers: N, M, and A.
    long long N, M, A;
    if (!(cin >> N >> M >> A)) return 0;

    // Calculate total capacity
    long long total_capacity = N * A;

    // Check if capacity is sufficient
    if (total_capacity >= M) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
```