# [X Jumps (XJUMP)](https://www.codechef.com/problems/XJUMP)

- **Difficulty Rating**: 686
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is standing at stair 0 and wants to reach stair $X$. He can make jumps of size $Y$ or size $1$. The goal is to find the minimum number of jumps required to reach exactly stair $X$.

## Intuition & Mathematical Observation
To minimize the total number of jumps, we should prioritize using the largest possible jump size ($Y$) as much as possible. 

1. **Maximizing Large Jumps**: We can use the jump of size $Y$ at most $\lfloor X / Y \rfloor$ times. Let this be $a = X / Y$.
2. **Handling the Remainder**: After taking $a$ jumps of size $Y$, the remaining distance to cover is $X \pmod Y$. Since we can only use jumps of size $1$ to cover the remainder, we will need exactly $X \pmod Y$ jumps of size $1$.
3. **Total Jumps**: The total number of jumps is the sum of the large jumps and the small jumps:
   $$\text{Total Jumps} = \lfloor X / Y \rfloor + (X \pmod Y)$$

This greedy approach works because every jump of size $Y$ reduces the remaining distance by $Y$, which is more efficient than reducing it by $1$ at a time.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic operations (division and modulo). For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to reach stair X using moves of size Y or 1.
 * To minimize the number of moves, we should use the largest possible move (Y)
 * as many times as possible.
 * 
 * Total moves = (X / Y) + (X % Y).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Calculate the number of moves of size Y
        long long moves_y = x / y;
        
        // Calculate the remaining distance to be covered by moves of size 1
        long long moves_1 = x % y;

        // The total minimum moves is the sum of both
        long long total_moves = moves_y + moves_1;

        cout << total_moves << "\n";
    }

    return 0;
}
```