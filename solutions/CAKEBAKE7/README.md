# [Cake Baking (CAKEBAKE7)](https://www.codechef.com/problems/CAKEBAKE7)

- **Difficulty Rating**: 339
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given $N$ customers and $M$ cakes. Every customer must receive at least one cake. Any cake given to a customer beyond the first one makes that customer "happy." The goal is to determine the maximum number of customers that can be made happy given the total number of cakes available.

## Intuition & Mathematical Observation
1. **Constraint**: Since every customer must receive at least one cake, we first distribute $N$ cakes to the $N$ customers.
2. **Remaining Cakes**: After the initial distribution, we are left with $M - N$ cakes.
3. **Happiness Condition**: To make a customer happy, we must give them at least one additional cake. Since each additional cake makes exactly one customer happy, we can make at most $M - N$ customers happy.
4. **Upper Bound**: We cannot make more than $N$ customers happy because there are only $N$ customers in total.
5. **Conclusion**: The maximum number of happy customers is the smaller of the two values: the number of extra cakes available ($M - N$) and the total number of customers ($N$). Thus, the formula is:
   $$\text{Max Happy} = \min(N, M - N)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * N customers, M cakes.
 * Every customer needs at least 1 cake.
 * Remaining cakes = M - N.
 * Each additional cake given to a customer makes them happy.
 * We can make at most M - N customers happy.
 * Also, we cannot make more than N customers happy.
 * Max happy = min(N, M - N).
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    // Reading until EOF as the problem input structure 
    // involves multiple test cases without a specified count.
    while (cin >> N >> M) {
        // Calculate the maximum number of happy customers
        long long ans = min(N, M - N);
        cout << ans << "\n";
    }
    return 0;
}
```