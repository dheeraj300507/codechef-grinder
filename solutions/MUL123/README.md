# [Make Multiple (MUL123)](https://www.codechef.com/problems/MUL123)

- **Difficulty Rating**: 959
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we want to reach a multiple of 3 using the minimum number of operations. The allowed operations are:
1. Increment $N$ by 1 ($N = N + 1$).
2. Replace $N$ with the next multiple of 5 ($N = \lceil \frac{N+1}{5} \rceil \times 5$).

We need to find the shortest sequence of operations to make $N$ divisible by 3.

## Intuition & Mathematical Observation
Since we are looking for the **shortest path** (minimum number of operations) in a state space where each state has a limited number of transitions, **Breadth-First Search (BFS)** is the ideal algorithm.

1. **State Space**: The value of $N$ starts at most at 100. Even with multiple operations, the value will not grow excessively large, making a BFS approach highly efficient.
2. **Transitions**:
   - Operation 1: Simply $N + 1$.
   - Operation 2: To find the next multiple of 5, we can use the formula `((N / 5) + 1) * 5`.
3. **Termination**: The search terminates as soon as we reach a value $V$ such that $V \pmod 3 == 0$.
4. **Visited Array**: To avoid redundant calculations and infinite loops, we maintain a `visited` array to keep track of numbers we have already processed.

## Complexity Analysis
- **Time Complexity**: $O(V)$, where $V$ is the maximum value reached during the search. Since the state space is constrained (well under 1000), the BFS explores a very small number of nodes, making it effectively $O(1)$ per test case.
- **Space Complexity**: $O(V)$ to store the `visited` array and the BFS queue. Given $V=1000$, this is constant space $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with N. We have two operations:
 * 1. N = N + 1
 * 2. N = next_multiple_of_5(N)
 * 
 * Since N is small (up to 100), we can use Breadth-First Search (BFS) 
 * to find the shortest path to a multiple of 3.
 */

int solve() {
    int N;
    cin >> N;

    // If already a multiple of 3, 0 operations needed
    if (N % 3 == 0) return 0;

    // BFS setup
    queue<pair<int, int>> q;
    q.push({N, 0});
    
    // Visited array to prevent infinite loops
    vector<bool> visited(1000, false);
    visited[N] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int val = curr.first;
        int dist = curr.second;

        // Try operation 1: N + 1
        int next1 = val + 1;
        if (next1 % 3 == 0) return dist + 1;
        if (next1 < 1000 && !visited[next1]) {
            visited[next1] = true;
            q.push({next1, dist + 1});
        }

        // Try operation 2: next multiple of 5
        int next2 = ((val / 5) + 1) * 5;
        if (next2 % 3 == 0) return dist + 1;
        if (next2 < 1000 && !visited[next2]) {
            visited[next2] = true;
            q.push({next2, dist + 1});
        }
    }
    return -1;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}
```