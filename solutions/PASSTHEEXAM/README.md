# [Pass the Exam (PASSTHEEXAM)](https://www.codechef.com/problems/PASSTHEEXAM)

- **Difficulty Rating**: 424
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef takes an exam consisting of three sections with scores $A$, $B$, and $C$. To pass the exam, Chef must satisfy two conditions simultaneously:
1. The total score ($A + B + C$) must be at least 100.
2. The score in each individual section must be at least 10 (i.e., $A \ge 10$, $B \ge 10$, and $C \ge 10$).

If both conditions are met, output "PASS"; otherwise, output "FAIL".

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. We are given three integers representing the scores. We can use a simple `if-else` statement to verify the criteria:
- **Condition 1**: `(a + b + c) >= 100`
- **Condition 2**: `(a >= 10) && (b >= 10) && (c >= 10)`

If both evaluate to `true`, the student passes. Since the constraints on the scores are small, standard integer types are sufficient, though `long long` is used here for safety.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic and comparison operations.
- **Space Complexity**: $O(1)$, as we only store a fixed number of variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Pass the Exam
 * Logic:
 * Chef passes if:
 * 1. Total score (A + B + C) >= 100
 * 2. Each section score >= 10 (A >= 10, B >= 10, C >= 10)
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Check conditions:
        // 1. Total score >= 100
        // 2. Each section >= 10
        if ((a + b + c >= 100) && (a >= 10) && (b >= 10) && (c >= 10)) {
            cout << "PASS" << "\n";
        } else {
            cout << "FAIL" << "\n";
        }
    }
    
    return 0;
}
```