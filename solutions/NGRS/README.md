# [50-50 Rule (NGRS)](https://www.codechef.com/problems/NGRS)

- **Difficulty Rating**: 524
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine a student's grade based on two criteria: attendance ($X$) and marks ($Y$). The grading rules are hierarchical:
1. If the attendance ($X$) is less than 50, the student receives grade **'Z'**.
2. If the attendance is 50 or greater, but the marks ($Y$) are less than 50, the student receives grade **'F'**.
3. If both attendance and marks are 50 or greater, the student receives grade **'A'**.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the rules have a specific priority, we can use an `if-else if-else` structure:

1. **Priority 1**: Check $X < 50$. If true, the output is 'Z' regardless of $Y$.
2. **Priority 2**: If the first condition fails (meaning $X \ge 50$), check $Y < 50$. If true, the output is 'F'.
3. **Default**: If both previous conditions fail (meaning $X \ge 50$ and $Y \ge 50$), the output is 'A'.

This approach ensures that we evaluate the conditions in the exact order specified by the problem statement.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and do not require any auxiliary data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grading logic is defined as follows:
 * 1. If attendance (X) < 50, grade is 'Z'.
 * 2. Else if marks (Y) < 50, grade is 'F'.
 * 3. Otherwise, grade is 'A'.
 * 
 * Constraints: 1 <= X, Y <= 100.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        if (x < 50) {
            cout << "Z" << "\n";
        } else if (y < 50) {
            cout << "F" << "\n";
        } else {
            cout << "A" << "\n";
        }
    }
    
    return 0;
}
```