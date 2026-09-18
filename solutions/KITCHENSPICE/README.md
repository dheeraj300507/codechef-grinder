# [Spice Level (KITCHENSPICE)](https://www.codechef.com/problems/KITCHENSPICE)

- **Difficulty Rating**: 390
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to categorize a given spice level $X$ into one of three categories based on its intensity:
- **MILD**: If the spice level is less than 4.
- **MEDIUM**: If the spice level is at least 4 but less than 7.
- **HOT**: If the spice level is 7 or greater.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. By observing the constraints provided:
1. $X < 4 \implies$ `MILD`
2. $4 \le X < 7 \implies$ `MEDIUM`
3. $X \ge 7 \implies$ `HOT`

We can use a simple `if-else if-else` control structure to evaluate the input $X$ for each test case and print the corresponding category.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Since we perform a constant number of comparisons for each test case, the operations scale linearly with the input size.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input for each test case, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Spice Level
 * Logic:
 * - MILD: X < 4
 * - MEDIUM: 4 <= X < 7
 * - HOT: X >= 7
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        if (x < 4) {
            cout << "MILD" << "\n";
        } else if (x >= 4 && x < 7) {
            cout << "MEDIUM" << "\n";
        } else {
            cout << "HOT" << "\n";
        }
    }
    
    return 0;
}
```