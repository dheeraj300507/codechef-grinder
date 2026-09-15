# [Discus Throw (DISCUS)](https://www.codechef.com/problems/DISCUS)

- **Difficulty Rating**: 622
- **Solved in**: 1 attempt(s)

## Problem Summary
In a discus throw competition, an athlete is given three attempts. The final score is determined by the maximum distance achieved among these three attempts. Given three integers $A, B,$ and $C$ representing the distances of the three throws, the goal is to output the largest value among them.

## Intuition & Mathematical Observation
The problem asks for the maximum of three numbers. In C++, the `<algorithm>` library provides a convenient `std::max` function. By using an initializer list `{a, b, c}`, we can compare all three values simultaneously and retrieve the maximum efficiently without needing multiple `if-else` statements or nested comparisons.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the comparison of three integers takes constant time.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the three input variables and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Discus Throw
 * The goal is to find the maximum of three given integers A, B, and C.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Use max() function with an initializer list to find the largest of the three distances.
        long long result = max({a, b, c});
        
        cout << result << "\n";
    }
    
    return 0;
}
```