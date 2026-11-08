# [Subset GCD (GCDPERM)](https://www.codechef.com/problems/GCDPERM)

- **Difficulty Rating**: 1362
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $K$, we need to select a subset of $K$ distinct integers from the set $\{1, 2, \dots, N\}$ such that the Greatest Common Divisor (GCD) of all elements in the subset is maximized. We are required to output the elements of this subset.

## Intuition & Mathematical Observation
Let the GCD of the chosen subset be $g$. By definition, every element in the subset must be a multiple of $g$. The multiples of $g$ available in the range $[1, N]$ are $\{g, 2g, 3g, \dots, m \cdot g\}$, where $m \cdot g \le N$. 

The total count of such multiples is $\lfloor N/g \rfloor$. For a subset of size $K$ to exist with a GCD of at least $g$, we must have at least $K$ multiples of $g$ available in the range $[1, N]$. Therefore, the condition is:
$$\lfloor N/g \rfloor \ge K$$

To maximize $g$, we rearrange the inequality:
$$N/g \ge K \implies g \le N/K$$

The largest integer $g$ satisfying this is $g = \lfloor N/K \rfloor$. Once we have determined this optimal $g$, we can simply pick the first $K$ multiples of $g$: $\{1 \cdot g, 2 \cdot g, \dots, K \cdot g\}$. Since $K \cdot g = K \cdot \lfloor N/K \rfloor \le N$, all these elements are guaranteed to be within the range $[1, N]$.

## Complexity Analysis
- **Time Complexity**: $O(K)$ per test case, as we iterate $K$ times to print the multiples. Given $T$ test cases, the total time complexity is $O(T \times K)$.
- **Space Complexity**: $O(1)$, as we do not store the subset in an array and print the values directly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to find a subset of size K from {1, 2, ..., N} such that the GCD of the subset is maximized.
 * Let the GCD be 'g'. If a subset has GCD 'g', then every element in the subset must be a multiple of 'g'.
 * The multiples of 'g' in the range [1, N] are {g, 2g, 3g, ..., m*g} where m*g <= N.
 * The number of such multiples is floor(N/g).
 * For a subset of size K to have a GCD of at least 'g', we must have at least K multiples of 'g' 
 * available in the set {1, ..., N}.
 * Thus, floor(N/g) >= K.
 * To maximize 'g', we want the largest 'g' such that floor(N/g) >= K.
 * This is equivalent to g <= N/K.
 * The maximum such integer 'g' is floor(N/K).
 * 
 * Once we have the optimal 'g', we simply pick the first K multiples of 'g':
 * {g, 2g, 3g, ..., Kg}.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    // The maximum possible GCD is floor(N/K).
    // Let g = N / K.
    // The multiples of g are g, 2g, 3g, ..., Kg.
    // Since Kg <= (N/K)*K <= N, these are all <= N.
    int g = N / K;

    for (int i = 1; i <= K; ++i) {
        cout << (long long)i * g << (i == K ? "" : " ");
    }
    cout << "\n";
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