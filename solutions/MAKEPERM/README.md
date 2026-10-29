# [Make Permutation (MAKEPERM)](https://www.codechef.com/problems/MAKEPERM)

- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ non-negative integers, determine if it is possible to construct an array $B$ (where each $B_i \ge 0$) such that the array $C$, defined by $C_i = A_i + B_i$, is a permutation of the numbers from $1$ to $N$. In other words, we need to check if we can increase each element $A_i$ such that the resulting set of numbers is exactly $\{1, 2, \dots, N\}$.

## Intuition & Mathematical Observation
The condition $C_i = A_i + B_i$ with $B_i \ge 0$ implies that $C_i \ge A_i$. To form a permutation of $1$ to $N$, we must assign each $A_i$ to a unique target value $v \in \{1, 2, \dots, N\}$ such that $A_i \le v$.

1. **Sorting**: If we sort the array $A$ in non-decreasing order ($A_1 \le A_2 \le \dots \le A_N$), it becomes optimal to match the smallest $A_i$ with the smallest available target values.
2. **Greedy Strategy**: After sorting, the $i$-th element (using 0-based indexing) is $A[i]$. The smallest possible value this element can be mapped to is $i+1$. 
3. **Condition**: If at any point $A[i] > i+1$, it is impossible to map $A[i]$ to any value in the set $\{1, \dots, N\}$ because all values smaller than $A[i]$ have already been "used up" by the previous elements, and any value $v \ge A[i]$ would require $v > i+1$, which is not possible if we want to fill the permutation slots efficiently.
4. **Conclusion**: The array can form a permutation if and only if, after sorting, $A[i] \le i+1$ for all $0 \le i < N$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We need to find if there exists an array B 
 * of non-negative integers such that C_i = A_i + B_i forms a permutation of 1 to N.
 * 
 * Since B_i >= 0, it implies C_i >= A_i.
 * Sorting A allows us to greedily check if each A[i] can be mapped to a unique
 * value in {1, ..., N}. The condition A[i] <= i+1 must hold for all i.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array to align with the target permutation {1, 2, ..., N}
    sort(A.begin(), A.end());
    
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        // After sorting, A[i] is the (i+1)-th smallest element.
        // It must be able to reach at least the value (i+1) in the permutation.
        // Since B_i >= 0, A[i] + B_i >= A[i].
        // So we need A[i] <= i + 1.
        if (A[i] > (i + 1)) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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