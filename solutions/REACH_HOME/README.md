# [Reach Home (REACH_HOME)](https://www.codechef.com/problems/REACH_HOME)

- **Difficulty Rating**: 395
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $X$ litres of fuel in his motorcycle. The motorcycle consumes fuel at a rate such that it travels 5 km for every 1 litre of fuel. Given the distance $Y$ to Chef's home, determine if Chef can reach home with the available fuel.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. 
1. Since the motorcycle travels 5 km per litre, the total distance Chef can cover with $X$ litres is $X \times 5$ km.
2. To reach home, the total distance covered must be greater than or equal to the distance $Y$ to his home.
3. Therefore, the condition to check is: $X \times 5 \ge Y$.
4. If the condition holds true, output "YES"; otherwise, output "NO".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, requiring no extra data structures that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X litres of fuel.
 * The motorcycle travels 5 km per 1 litre of fuel.
 * Maximum distance Chef can travel = X * 5 km.
 * Chef can reach home if (X * 5) >= Y.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X, Y <= 1000
 * X * 5 will be at most 5000, which fits in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate maximum distance possible with current fuel
        long long max_distance = x * 5;
        
        // Check if the distance to home is reachable
        if (max_distance >= y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```