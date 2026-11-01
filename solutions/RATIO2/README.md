# [Ratio By 2 (RATIO2)](https://www.codechef.com/problems/RATIO2)

- **Difficulty Rating**: 1035
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two positive integers $X$ and $Y$, we want to reach a state where either $X \ge 2Y$ or $Y \ge 2X$. In one operation, we can increment or decrement either $X$ or $Y$ by 1. We need to find the minimum number of operations required to satisfy the condition.

## Intuition & Mathematical Observation
Since the initial values of $X$ and $Y$ are very small (up to 10), the target state will be reached within a very small number of operations. This allows us to treat the problem as a **Shortest Path Problem** on a 2D grid.

1. **State Representation**: Each state is defined by the pair $(X, Y)$.
2. **Transitions**: From any state $(X, Y)$, we can move to $(X+1, Y)$, $(X-1, Y)$, $(X, Y+1)$, or $(X, Y-1)$.
3. **Search Strategy**: Breadth-First Search (BFS) is ideal here because it explores states layer by layer, guaranteeing that the first time we reach a state satisfying the condition ($X \ge 2Y$ or $Y \ge 2X$), we have found the minimum number of operations.
4. **Bounds**: Given the small input constraints, limiting the search space to a range of $[1, 30]$ for both $X$ and $Y$ is more than sufficient to find the optimal path without exceeding memory or time limits.

## Complexity Analysis
- **Time Complexity**: $O(N \times M)$, where $N$ and $M$ are the bounds of our search space (in this case, $30 \times 30 = 900$ states). Since we perform a constant number of operations (4 directions) per state, the complexity is effectively constant per test case.
- **Space Complexity**: $O(N \times M)$ to store the `dist` map (or a 2D array) to keep track of visited states and their distances.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We use BFS to find the shortest path from (X, Y) to any state where 
 * the ratio condition (X >= 2Y or Y >= 2X) is met.
 */

int solve() {
    int X, Y;
    cin >> X >> Y;

    // If already satisfied
    if (X >= 2 * Y || Y >= 2 * X) return 0;

    // BFS to find the minimum operations
    queue<pair<int, int>> q;
    map<pair<int, int>, int> dist;

    q.push({X, Y});
    dist[{X, Y}] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int cx = curr.first;
        int cy = curr.second;
        int d = dist[{cx, cy}];

        // Check if current state satisfies the condition
        if (cx >= 2 * cy || cy >= 2 * cx) return d;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // Constraints: X, Y must be positive integers.
            // We bound the search to 30 to stay within a safe, reachable range.
            if (nx >= 1 && ny >= 1 && nx <= 30 && ny <= 30) {
                if (dist.find({nx, ny}) == dist.end()) {
                    dist[{nx, ny}] = d + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main() {
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