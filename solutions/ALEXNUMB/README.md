# [Magic Pairs (ALEXNUMB)](https://www.codechef.com/problems/ALEXNUMB)

- **Difficulty Rating**: 1245
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $n$ distinct integers, we need to find the number of pairs $(i, j)$ such that $1 \le i, j \le n$, $i \neq j$, and $a_i < a_j$.

## Intuition & Mathematical Observation
The problem states that all $n$ integers in the array are **distinct**. 

1. Consider any two distinct indices $i$ and $j$ from the array. Since all elements are distinct, there are only two possibilities for the values at these indices: either $a_i < a_j$ or $a_j < a_i$.
2. The total number of ways to choose two distinct indices $(i, j)$ from $n$ elements is the number of permutations of 2 elements from $n$, which is $n \times (n - 1)$.
3. Because for every pair of distinct indices $\{i, j\}$, exactly one of the conditions ($a_i < a_j$ or $a_j < a_i$) must be true, exactly half of the total $n(n-1)$ pairs will satisfy the condition $a_i < a_j$.
4. Therefore, the number of pairs is simply the number of ways to choose 2 distinct elements from $n$, which is given by the combination formula $\binom{n}{2}$:
   $$\text{Result} = \frac{n(n - 1)}{2}$$
5. **Note on Constraints**: Since $n$ can be up to $100,000$, $n(n-1)$ can reach approximately $10^{10}$. This exceeds the capacity of a standard 32-bit `int`, so we must use a 64-bit integer type (`long long` in C++) to store the result.

## Complexity Analysis
- **Time Complexity**: $O(n)$ per test case, as we must iterate through the input array to read the $n$ elements.
- **Space Complexity**: $O(n)$ to store the input array (or $O(1)$ if we simply read the input and discard it, as the values themselves do not affect the final calculation).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given n distinct integers a1, a2, ..., an.
 * We need to find the number of pairs (i, j) such that 1 <= i, j <= n, i != j, and ai < aj.
 * 
 * Since all elements are distinct, for any two distinct indices i and j, 
 * either ai < aj or aj < ai.
 * The total number of pairs (i, j) with i != j is n * (n - 1).
 * Because exactly one of the two conditions (ai < aj) or (aj < ai) must hold for any pair {i, j},
 * the number of pairs where ai < aj is exactly half of the total number of pairs with i != j.
 * 
 * Number of pairs = (n * (n - 1)) / 2.
 * 
 * Constraints:
 * n <= 100,000.
 * n * (n - 1) / 2 can be up to ~5 * 10^9, which exceeds the range of a 32-bit integer.
 * We must use long long to store the result.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Read the array elements. 
        // Note: Since all elements are distinct, the actual values don't affect the count,
        // only the fact that there are n distinct elements matters.
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // The number of pairs (i, j) such that i != j and ai < aj is nC2.
        // nC2 = n * (n - 1) / 2
        long long result = (n * (n - 1)) / 2;
        
        cout << result << "\n";
    }

    return 0;
}
```