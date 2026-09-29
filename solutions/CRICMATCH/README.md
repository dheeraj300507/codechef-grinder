# [Cricket Match (CRICMATCH)](https://www.codechef.com/problems/CRICMATCH)

- **Difficulty Rating**: 505
- **Solved in**: 1 attempt(s)

## Problem Summary
In a cricket match, each over consists of 6 balls. The maximum number of runs that can be scored on a single ball is 6. Given the total number of runs $N$ required to win and the number of overs $M$ remaining, determine if it is possible for the team to score at least $N$ runs.

## Intuition & Mathematical Observation
To determine if the team can win, we need to calculate the maximum possible runs they can score in the remaining $M$ overs.

1.  **Balls per over**: Each over has 6 balls.
2.  **Max runs per ball**: The maximum runs per ball is 6.
3.  **Max runs per over**: Therefore, the maximum runs possible in one over is $6 \times 6 = 36$.
4.  **Total capacity**: In $M$ overs, the maximum runs the team can score is $M \times 36$.

The team can win if the required runs $N$ are less than or equal to the maximum possible runs:
$$N \le M \times 36$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each over consists of 6 balls.
 * The maximum runs that can be scored in a single ball is 6.
 * Therefore, the maximum runs that can be scored in 1 over is 6 * 6 = 36.
 * In M overs, the maximum runs that can be scored is M * 36.
 * 
 * Chef's team can win if the required runs N is less than or equal to 
 * the maximum possible runs they can score in M overs.
 * Condition: N <= M * 36
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // Calculate maximum possible runs
        long long max_runs = m * 6 * 6;
        
        // Check if required runs are achievable
        if (n <= max_runs) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```