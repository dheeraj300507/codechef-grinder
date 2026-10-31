# [Coloured Balloons (BALLOONS)](https://www.codechef.com/problems/BALLOONS)

- **Difficulty Rating**: 584
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ different colors of balloons. For each color $i$ (where $1 \le i \le N$), we are provided with the quantity $A_i$ of balloons available. The cost of a single balloon of color $i$ is exactly $i$ rupees. The objective is to calculate the total cost required to purchase all the balloons provided.

## Intuition & Mathematical Observation
The problem asks for the sum of the costs of all balloons. Since each balloon of color $i$ costs $i$ rupees, the total cost for all balloons of color $i$ is simply $A_i \times i$. 

To find the total cost for all $N$ colors, we simply need to compute the summation:
$$\text{Total Cost} = \sum_{i=1}^{N} (A_i \times i)$$

Given the constraints ($N \le 100$ and $A_i \le 100$), the maximum possible cost is $100 \times (100 \times 100) = 1,000,000$. This value fits well within a standard 32-bit integer, though `long long` is used in the implementation as a best practice to avoid potential overflow in similar, larger-scale problems.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ colors exactly once to calculate the total cost. With $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$, as we only store the current balloon count and the running total, requiring constant extra space regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N colours of balloons.
 * The i-th colour balloon costs i rupees.
 * We are given A_i, the number of balloons of colour i.
 * Total cost = sum_{i=1 to N} (A_i * i).
 * 
 * Constraints:
 * T <= 100, N <= 100, A_i <= 100.
 * Max possible cost = 100 * (100 * 100) = 1,000,000.
 * This fits comfortably within a standard 32-bit integer, 
 * but using long long is good practice to prevent overflow in similar problems.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long total_cost = 0;
    for (int i = 1; i <= N; ++i) {
        long long A_i;
        cin >> A_i;
        total_cost += (A_i * i);
    }
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```