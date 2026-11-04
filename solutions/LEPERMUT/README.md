# [Little Elephant and Permutations (LEPERMUT)](https://www.codechef.com/problems/LEPERMUT)

- **Difficulty Rating**: 1261
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a permutation $A$ of size $N$, we need to determine if the number of **inversions** is equal to the number of **local inversions**.
- An **inversion** is a pair of indices $(i, j)$ such that $i < j$ and $A[i] > A[j]$.
- A **local inversion** is a pair of adjacent indices $(i, i+1)$ such that $A[i] > A[i+1]$.

## Intuition & Mathematical Observation
1. **Relationship**: Every local inversion is, by definition, an inversion because it satisfies the condition $i < j$ (specifically $j = i+1$) and $A[i] > A[j]$.
2. **Condition**: Since all local inversions are a subset of total inversions, the condition "total inversions equals local inversions" implies that there are **no non-local inversions**. That is, for any pair $(i, j)$ where $j > i + 1$, we must have $A[i] < A[j]$.
3. **Constraints**: With $N \le 100$, an $O(N^2)$ algorithm to count total inversions is perfectly acceptable, as $100^2 = 10,000$ operations per test case, which is well within the typical $10^8$ operations per second limit.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case. We use a nested loop to count total inversions, which takes $O(N^2)$, and a single loop to count local inversions, which takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the permutation array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An inversion is a pair (i, j) such that i < j and A[i] > A[j].
 * A local inversion is a pair (i, i+1) such that A[i] > A[i+1].
 * 
 * Every local inversion is by definition an inversion.
 * Therefore, the number of local inversions is always less than or equal to 
 * the total number of inversions.
 * The permutation is "good" if and only if the number of inversions equals 
 * the number of local inversions.
 * 
 * Constraints: N <= 100.
 * An O(N^2) approach to count total inversions and an O(N) approach to count 
 * local inversions will easily pass within the 1s time limit.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int total_inversions = 0;
    int local_inversions = 0;

    // Count total inversions: O(N^2)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                total_inversions++;
            }
        }
    }

    // Count local inversions: O(N)
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            local_inversions++;
        }
    }

    if (total_inversions == local_inversions) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
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