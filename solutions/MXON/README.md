# [Maximum Ones (MXON)](https://www.codechef.com/problems/MXON)

- **Difficulty Rating**: 943
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, we are allowed to perform an operation: choose an index $i$ ($0 \le i < N-1$) and update $S[i] = \max(S[i], S[i+1])$. Each operation costs 1 unit of $K$. We need to find the maximum number of '1's we can obtain in the string using at most $K$ operations.

## Intuition & Mathematical Observation
The operation $S[i] = \max(S[i], S[i+1])$ essentially allows a '1' to propagate to the left. If $S[i+1]$ is '1', we can change $S[i]$ to '1' at the cost of 1 operation. 

Since the constraints are very small ($N \le 10$), the total number of possible binary strings is $2^{10} = 1024$. This allows us to treat the problem as a shortest-path problem on a graph where:
1. **Nodes**: Each unique binary string configuration.
2. **Edges**: A transition from string $S$ to $S'$ by changing one '0' to '1' (if a '1' exists to its right), costing 1 unit of $K$.

We use **Breadth-First Search (BFS)** to explore all reachable states within $K$ operations. By tracking the number of '1's in every reachable state, we can easily determine the maximum count.

## Complexity Analysis
- **Time Complexity**: $O(2^N \cdot N)$, where $N$ is the length of the string. With $N \le 10$, $2^{10} = 1024$, and for each state, we iterate through $N$ positions. This is well within the time limits for the given constraints.
- **Space Complexity**: $O(2^N \cdot N)$ to store the visited states in the `set` and the `queue`.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given N <= 10, we can use BFS to explore all possible strings reachable 
 * within K operations. Each operation S[i] = max(S[i], S[i+1]) allows 
 * a '1' to move left, effectively turning a '0' into a '1' if a '1' 
 * exists at some index j > i.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // BFS to find the maximum number of ones reachable within K operations
    queue<pair<string, int>> q;
    q.push({S, 0});
    
    set<pair<string, int>> visited;
    visited.insert({S, 0});
    
    int max_ones = 0;
    for (char c : S) if (c == '1') max_ones++;
    
    while (!q.empty()) {
        pair<string, int> curr = q.front();
        q.pop();
        
        string s = curr.first;
        int k = curr.second;
        
        int current_ones = 0;
        for (char c : s) if (c == '1') current_ones++;
        max_ones = max(max_ones, current_ones);
        
        // If we have operations left, try to propagate '1's to the left
        if (k < K) {
            for (int i = 0; i < N - 1; ++i) {
                if (s[i] == '0' && s[i+1] == '1') {
                    string next_s = s;
                    next_s[i] = '1';
                    if (visited.find({next_s, k + 1}) == visited.end()) {
                        visited.insert({next_s, k + 1});
                        q.push({next_s, k + 1});
                    }
                }
            }
        }
    }
    cout << max_ones << "\n";
}

int main() {
    // Optimize I/O operations
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