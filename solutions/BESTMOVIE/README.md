# [Best Movie (BESTMOVIE)](https://www.codechef.com/problems/BESTMOVIE)

- **Difficulty Rating**: 660
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a list of $N$ movies, each with an IMDB rating $A_i$ and a cost $B_i$, we need to find the minimum cost among all movies that have an IMDB rating of at least 7 ($A_i \ge 7$). If no such movie exists, we should output -1.

## Intuition & Mathematical Observation
The problem asks for a conditional minimum. Since we are processing a list of items and looking for the smallest value that satisfies a specific condition, a linear scan is the most efficient approach:

1. **Initialization**: We maintain a variable `min_cost` initialized to a value larger than any possible input (e.g., 2000, since the maximum cost is 1000). We also use a boolean flag `found` to track if we have encountered at least one movie meeting the criteria.
2. **Iteration**: For every movie $(A_i, B_i)$, we check if $A_i \ge 7$.
3. **Update**: If the condition is met, we update `min_cost` using `min(min_cost, B_i)` and set `found` to `true`.
4. **Result**: After checking all movies, if `found` is true, we print `min_cost`; otherwise, we print -1.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of movies. We iterate through the list of movies exactly once.
- **Space Complexity**: $O(1)$, as we only store a few variables (`min_cost`, `found`, `a`, `b`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: BESTMOVIE
 * Approach:
 * We need to find the minimum cost (B_i) among all movies where the IMDB score (A_i) is >= 7.
 * We initialize a variable 'min_cost' to a value larger than any possible cost (e.g., 2000).
 * We iterate through all N movies, and if A_i >= 7, we update min_cost = min(min_cost, B_i).
 * If after checking all movies min_cost remains unchanged, we output -1.
 */

void solve() {
    int N;
    cin >> N;
    
    int min_cost = 2000; // Since max B_i is 1000, 2000 is a safe infinity
    bool found = false;
    
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        if (a >= 7) {
            if (b < min_cost) {
                min_cost = b;
            }
            found = true;
        }
    }
    
    if (found) {
        cout << min_cost << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
```