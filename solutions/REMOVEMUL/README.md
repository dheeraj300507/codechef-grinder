# [Remove Multiples (REMOVEMUL)](https://www.codechef.com/problems/REMOVEMUL)

- **Difficulty Rating**: 1315
- **Solved in**: 1 attempt(s)

## Problem Summary
We start with a set $S = \{1, 2, \dots, N\}$. We are given a target subset $Q \subseteq S$. We want to remove all elements that are in $S$ but not in $Q$. In one operation, we can choose an integer $k$ and remove the smallest multiple of $k$ currently present in $S$. The cost of this operation is $k$. We want to find the total cost to remove all elements in $S \setminus Q$.

## Intuition & Mathematical Observation
The core of the problem lies in the cost of removing an element $x$. 
1. If we want to remove a specific element $x$, we can choose $k = x$. Since $x$ is a multiple of itself, and assuming $x$ is the smallest multiple of $x$ currently in the set (which is true if no smaller multiple of $x$ exists or has already been removed), the cost to remove $x$ is exactly $x$.
2. To remove all elements in the set $S \setminus Q$, we can simply choose $k = x$ for every $x \in S \setminus Q$. 
3. The total cost is the sum of all elements that need to be removed:
   $$\text{Total Cost} = \sum_{x \in S \setminus Q} x$$
4. This can be calculated efficiently as:
   $$\text{Total Cost} = \left( \sum_{i=1}^{N} i \right) - \left( \sum_{q \in Q} q \right)$$
5. Using the arithmetic series formula, $\sum_{i=1}^{N} i = \frac{N(N+1)}{2}$. Thus, the result is $\frac{N(N+1)}{2} - \text{sum}(Q)$.

## Complexity Analysis
- **Time Complexity**: $O(M)$ per test case, where $M$ is the number of elements in the target subset $Q$. We iterate through the input array once to calculate the sum.
- **Space Complexity**: $O(1)$, as we only store the running sum of the elements in $Q$ and the total sum of $1 \dots N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with the set S = {1, 2, ..., N}.
 * We want to reach a subset Q. This means we need to remove all elements in {1, ..., N} \ Q.
 * The operation: Choose k, remove the smallest multiple of k currently in S. Cost = k.
 * 
 * Key insight:
 * If we want to remove an element x, we can choose k = x. The smallest multiple of x 
 * currently in S is x itself (provided x hasn't been removed yet).
 * If we remove all elements in {1, ..., N} \ Q by choosing k = x for each x in the 
 * set to be removed, the total cost is the sum of all elements in {1, ..., N} \ Q.
 * 
 * Total cost = (Sum of 1 to N) - (Sum of elements in Q).
 */

void solve() {
    long long N;
    int M;
    if (!(cin >> N >> M)) return;
    
    long long sum_Q = 0;
    for (int i = 0; i < M; ++i) {
        long long val;
        cin >> val;
        sum_Q += val;
    }
    
    // Sum of 1 to N = N * (N + 1) / 2
    long long total_sum = N * (N + 1) / 2;
    long long result = total_sum - sum_Q;
    
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```