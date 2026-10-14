# [Cab Rides (CABRIDE)](https://www.codechef.com/problems/CABRIDE)

- **Difficulty Rating**: 945
- **Solved in**: 1 attempt(s)

## Problem Summary
A cab can accommodate a maximum of 4 people. The cost to book a cab for $X$ people is defined as $\max(200, 100 \times X)$. Given $N$ people, we need to find the minimum cost to transport all of them.

## Intuition & Mathematical Observation
To minimize the total cost, we analyze the cost per cab based on the number of passengers ($X$):
- If $X=1$: Cost = $\max(200, 100) = 200$
- If $X=2$: Cost = $\max(200, 200) = 200$
- If $X=3$: Cost = $\max(200, 300) = 300$
- If $X=4$: Cost = $\max(200, 400) = 400$

By observing the pattern, we see that for any group size $X \ge 2$, the cost is exactly $100 \times X$. For $X=1$, the cost is $200$. 

Since we want to minimize the total cost for $N$ people, we should avoid having any cab carry only 1 person if possible, as that results in a cost of 200 (effectively 200 per person). By grouping people into sets of 2, 3, or 4, we maintain a cost of 100 per person. 

The total cost for $N$ people is simply $N \times 100$, provided we don't have a "remainder" of 1 that forces a 200-cost cab. However, since we can always distribute $N$ people into groups of 2, 3, or 4 (e.g., $N=5$ can be $3+2$, $N=6$ can be $3+3$), the cost effectively scales linearly at 100 per person, with a minimum floor of 200 for the first cab. Thus, the formula is $\max(200, N \times 100)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves a simple arithmetic operation. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A cab can hold at most 4 people.
 * Cost for X people in one cab = max(200, 100 * X).
 * 
 * Strategy:
 * To minimize cost, we group people into sets of 2, 3, or 4 to maintain 
 * a cost of 100 per person. The only constraint is the base cost of 200.
 * The formula max(200, N * 100) covers all cases efficiently.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate minimum cost using the derived formula
        long long ans = max(200LL, n * 100LL);
        cout << ans << "\n";
    }
    return 0;
}
```