# [Water Moving (Max) (WATERMOVE2)](https://www.codechef.com/problems/WATERMOVE2)

- **Difficulty Rating**: 934
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ cups, each containing a certain amount of water $A_i$. You are required to perform exactly $K$ operations. In one operation, you choose two cups $i$ and $j$ and move all the water from cup $i$ to cup $j$. The goal is to maximize the amount of water in a single cup after exactly $K$ operations.

## Intuition & Mathematical Observation
The problem asks us to maximize the water in one cup using $K$ moves. 

1. **Case 1: $K \ge N - 1$**
   - To merge all water into a single cup, we need $N-1$ operations. 
   - If $K \ge N-1$, we can merge all water into one cup using $N-1$ operations. Any remaining operations ($K - (N-1)$) can be performed by moving the total sum between two cups or moving 0 water from an empty cup to the full one. Thus, the maximum amount is simply the sum of all $A_i$.

2. **Case 2: $K < N - 1$**
   - We are limited to $K$ operations. Each operation allows us to add the contents of one cup to another.
   - To maximize the result, we should start with the cup that already has the most water and add the $K$ largest available cups to it.
   - We sort the array $A$ in descending order. The initial maximum cup is $A[0]$, and we add $A[1], A[2], \dots, A[K]$ to it.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case due to the sorting step. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the amounts of water in the cups.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cups with amounts A_i.
 * In one operation, we move all water from cup i to cup j.
 * We must perform exactly K operations.
 * To maximize the water in a single cup, we want to aggregate as much water
 * as possible into one cup.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    if (K >= N - 1) {
        // We can merge everything into one cup.
        // Even if K > N-1, we can keep moving the total sum between two cups
        // or move 0 from an empty cup to the full one.
        cout << total_sum << "\n";
    } else {
        // We can only perform K merges.
        // To maximize the result, we should pick the largest cup and add
        // the K largest other cups to it.
        sort(A.begin(), A.end(), greater<long long>());
        long long max_val = A[0];
        for (int i = 1; i <= K; ++i) {
            max_val += A[i];
        }
        cout << max_val << "\n";
    }
}

int main() {
    // Fast I/O
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