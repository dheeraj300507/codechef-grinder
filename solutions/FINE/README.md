# [Overspeeding Fine (FINE)](https://www.codechef.com/problems/FINE)

- **Difficulty Rating**: 335
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the fine amount based on the speed of a vehicle ($X$):
- If the speed is 70 km/h or less, the fine is 0.
- If the speed is greater than 70 km/h but not exceeding 100 km/h, the fine is 500.
- If the speed is greater than 100 km/h, the fine is 2000.

## Intuition & Mathematical Observation
This is a straightforward conditional logic problem. We can use `if-else` statements to map the input speed $X$ to the corresponding fine value:
1. **Condition 1**: $X \le 70 \implies \text{Fine} = 0$
2. **Condition 2**: $70 < X \le 100 \implies \text{Fine} = 500$
3. **Condition 3**: $X > 100 \implies \text{Fine} = 2000$

Since the conditions are mutually exclusive and cover all possible positive integers for $X$, a simple ladder of `if-else if-else` statements is sufficient to solve the problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input speed.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Overspeeding Fine
 * Logic:
 * - If X <= 70: Fine = 0
 * - If 70 < X <= 100: Fine = 500
 * - If X > 100: Fine = 2000
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
        int x;
        cin >> x;
        
        if (x <= 70) {
            cout << 0 << "\n";
        } else if (x <= 100) {
            cout << 500 << "\n";
        } else {
            cout << 2000 << "\n";
        }
    }
    
    return 0;
}
```