# [Fence Colouring (FENCECOL)](https://www.codechef.com/problems/FENCECOL)

- **Difficulty Rating**: 1131
- **Solved in**: 1 attempt(s)

## Problem Summary
We have $N$ fences, all initially colored with color $1$. We are given a target configuration of colors $A_1, A_2, \dots, A_N$. We have two types of operations:
1. **Global Operation**: Change the color of all $N$ fences to a specific color $X$. (Cost: 1)
2. **Individual Operation**: Change the color of a specific fence $i$ to a specific color $X$. (Cost: 1)

The goal is to reach the target configuration $A$ with the minimum total cost.

## Intuition & Mathematical Observation
To reach the target state, we have two primary strategies:

1. **No Global Operation**: Since all fences start at color $1$, we only need to perform an individual operation for every fence $i$ where $A_i \neq 1$.
   - **Cost**: The number of fences where $A_i \neq 1$. This is equivalent to $N - (\text{count of } 1\text{s in } A)$.

2. **Global Operation with color $X$**: We perform one global operation to set all fences to color $X$. After this, any fence $i$ that should have color $A_i \neq X$ must be corrected using an individual operation.
   - **Cost**: $1 + (\text{number of fences where } A_i \neq X)$.
   - This is equivalent to $1 + (N - \text{count of } X\text{s in } A)$.

We calculate the cost for the "No Global Operation" scenario and compare it against the costs for every unique color $X$ present in the target array $A$ using the "Global Operation" strategy. The minimum of these values is our answer.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the map implementation. Since we iterate through the array once to count frequencies and then iterate through the unique colors, the complexity is dominated by the input processing, which is $O(N)$.
- **Space Complexity**: $O(N)$ to store the frequencies of each color in a map or frequency array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with all fences colored 1.
 * We want the final state to be A_1, A_2, ..., A_N.
 * 
 * Strategy:
 * 1. Option 0: No global operation. Cost = count(A_i != 1).
 * 2. Option X: Global operation with color X. Cost = 1 + count(A_i != X).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> counts;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        counts[A[i]]++;
    }

    // Option 0: No global operation
    // Cost is the number of fences that are not already 1.
    int cost0 = N - counts[1];
    
    // Option X: Global operation with color X
    // Cost is 1 + (N - count of fences that are already X)
    int min_cost = cost0;
    
    for (auto const& [color, count] : counts) {
        if (color == 1) continue;
        int current_cost = 1 + (N - count);
        if (current_cost < min_cost) {
            min_cost = current_cost;
        }
    }
    
    cout << min_cost << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```