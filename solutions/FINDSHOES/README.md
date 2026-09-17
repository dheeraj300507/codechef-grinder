# [Finding Shoes (FINDSHOES)](https://www.codechef.com/problems/FINDSHOES)

- **Difficulty Rating**: 646
- **Solved in**: 3 attempt(s)

## Problem Summary
Chef needs to acquire $N$ pairs of shoes. Each pair consists of one left shoe and one right shoe. Chef already possesses $M$ left shoes. We need to calculate the minimum number of additional shoes Chef must buy to ensure he has $N$ complete pairs (i.e., $N$ left shoes and $N$ right shoes).

## Intuition & Mathematical Observation
To have $N$ pairs, Chef requires exactly $N$ left shoes and $N$ right shoes.

1.  **Right Shoes:** Since Chef starts with 0 right shoes, he must always purchase $N$ right shoes.
2.  **Left Shoes:**
    *   If $M \ge N$: Chef already has enough left shoes. He does not need to buy any additional left shoes.
    *   If $M < N$: Chef is short by $(N - M)$ left shoes. He must purchase these to reach the required count of $N$.

**Mathematical Formula:**
*   If $M \ge N$: Total shoes to buy = $N$
*   If $M < N$: Total shoes to buy = $(N - M) + N = 2N - M$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs N pairs of shoes. Each pair consists of 1 left and 1 right shoe.
 * Total shoes needed: N left shoes and N right shoes.
 * 
 * If M >= N:
 * Chef has enough left shoes. He only needs to buy N right shoes.
 * Total to buy = N.
 * 
 * If M < N:
 * Chef needs (N - M) more left shoes and N right shoes.
 * Total to buy = (N - M) + N = 2*N - M.
 */

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    if (m >= n) {
        // Chef has enough left shoes, just needs N right shoes
        cout << n << "\n";
    } else {
        // Chef needs (n - m) more left shoes and n right shoes
        cout << (n - m) + n << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}
```