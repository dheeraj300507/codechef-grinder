# [Smallest Numbers of Notes (FLOW005)](https://www.codechef.com/problems/FLOW005)

- **Difficulty Rating**: 839
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an amount $N$, we need to find the minimum number of currency notes required to make that amount. The available denominations are 1, 2, 5, 10, 50, and 100.

## Intuition & Mathematical Observation
This is a classic **Greedy Algorithm** problem. 

In a currency system where each denomination is a multiple of the smaller ones (or follows a structure where the greedy choice is optimal), we can always achieve the minimum count by picking the largest possible denomination first. 

1. We start with the largest denomination (100).
2. We calculate how many notes of 100 fit into $N$ using integer division (`N / 100`).
3. We update $N$ to the remainder (`N % 100`).
4. We repeat this process for the remaining denominations in descending order (50, 10, 5, 2, 1).
5. Because the denominations are structured such that taking the largest possible note never prevents us from reaching the optimal solution, this greedy approach is guaranteed to yield the minimum number of notes.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the number of denominations is fixed (6), the loop runs a constant number of times regardless of the input value $N$.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the count and the current remainder.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Smallest Numbers of Notes (FLOW005)
 * Strategy: Greedy approach.
 * Since the denominations are {1, 2, 5, 10, 50, 100}, and each larger denomination
 * is a multiple of smaller ones (or can be formed optimally), we can always
 * pick the largest possible denomination first to minimize the total count.
 */

void solve() {
    int n;
    cin >> n;
    
    int denominations[] = {100, 50, 10, 5, 2, 1};
    int count = 0;
    
    for (int i = 0; i < 6; ++i) {
        if (n >= denominations[i]) {
            // Add the number of notes of this denomination
            count += n / denominations[i];
            // Update n to the remaining amount
            n %= denominations[i];
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O setup for performance
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