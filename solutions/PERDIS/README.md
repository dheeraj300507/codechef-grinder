# [Permutation Disturbance (PERDIS)](https://www.codechef.com/problems/PERDIS)

- **Difficulty Rating**: 1270
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a permutation $P$ of length $N$, we want to ensure that no element is at its "natural" position (i.e., $P[i] \neq i+1$ for all $0 \le i < N$). We are allowed to swap any two adjacent elements. The goal is to find the minimum number of swaps required to eliminate all "fixed points" (indices where $P[i] = i+1$).

## Intuition & Mathematical Observation
A fixed point occurs when $P[i] = i+1$. To resolve this, we must move the element $P[i]$ out of index $i$. 

1. **Greedy Strategy**: Since we want to minimize the number of operations, we should aim to resolve as many fixed points as possible with each swap.
2. **Pairing**: If we encounter a fixed point at index $i$ and the next element at $i+1$ is also a fixed point ($P[i+1] = i+2$), we can swap these two elements. This single swap resolves both fixed points simultaneously.
3. **Isolated Fixed Points**: If we encounter a fixed point at index $i$ but the next element is not a fixed point, we must still perform a swap to move $P[i]$. Swapping it with the adjacent element will resolve the fixed point at $i$ regardless of the state of $i+1$.
4. **Efficiency**: By iterating linearly and prioritizing the "pair" swap, we ensure that we never use more operations than necessary. Each swap resolves either one or two fixed points, and since we process from left to right, we never create new fixed points that would require additional moves.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the permutation. We perform a single pass through the array.
- **Space Complexity**: $O(N)$ to store the permutation array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to reach a state where P[i] != i+1 for all i (using 0-based indexing).
 * If P[i] == i+1, we have a "fixed point".
 * We can swap adjacent elements. Swapping P[i] and P[i+1] can fix at most two 
 * fixed points if they are adjacent.
 * 
 * Strategy:
 * Iterate through the array. If we find a fixed point at index i (P[i] == i+1),
 * we must perform an operation to move it. To minimize operations, we should 
 * greedily pair adjacent fixed points.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int operations = 0;
    for (int i = 0; i < n; ++i) {
        // Check if current position is a fixed point
        if (p[i] == i + 1) {
            // If there is a next element and it is also a fixed point,
            // we can fix both with one swap.
            if (i + 1 < n && p[i + 1] == i + 2) {
                operations++;
                i++; // Skip the next element as it's now fixed
            } else {
                // Otherwise, just swap with the next element (or previous if at end)
                // to fix this one.
                operations++;
            }
        }
    }
    cout << operations << "\n";
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