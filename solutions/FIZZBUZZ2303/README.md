# [Chef Fantasy 11 (FIZZBUZZ2303)](https://www.codechef.com/problems/FIZZBUZZ2303)

- **Difficulty Rating**: 739
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a squad of $N$ players. He needs to select exactly one captain and one vice-captain from these players. Since the roles of captain and vice-captain are distinct, the order of selection matters. We need to determine the total number of ways to make this selection.

## Intuition & Mathematical Observation
This is a classic combinatorics problem involving permutations. 

1. **Choosing the Captain**: There are $N$ players available, so there are $N$ possible choices for the captain.
2. **Choosing the Vice-Captain**: Once the captain is chosen, they cannot be chosen as the vice-captain. Therefore, there are $N - 1$ remaining players to choose from.
3. **Total Combinations**: By the Fundamental Counting Principle, the total number of ways to choose both is the product of the individual choices:
   $$\text{Total Ways} = N \times (N - 1)$$

Given the constraints ($2 \le N \le 11$), the maximum possible result is $11 \times 10 = 110$, which easily fits within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves a simple multiplication. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N players to choose from.
 * He needs to select 1 captain and 1 vice-captain from these N players.
 * The order matters (choosing player A as captain and B as vice-captain is 
 * different from choosing B as captain and A as vice-captain).
 * 
 * Number of ways to choose the captain = N
 * Number of ways to choose the vice-captain from the remaining = N - 1
 * Total ways = N * (N - 1)
 * 
 * Constraints: 2 <= N <= 11.
 * The maximum value is 11 * 10 = 110, which fits easily in an integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate permutations of 2 items from N: P(N, 2) = N * (N - 1)
        long long result = n * (n - 1);
        
        cout << result << "\n";
    }

    return 0;
}
```