# [A Good Set (GOODSET)](https://www.codechef.com/problems/GOODSET)

- **Difficulty Rating**: 1231
- **Solved in**: 1 attempt(s)

## Problem Summary
We are required to construct a set of $n$ distinct integers ($1 \le n \le 100$) such that no three distinct elements $a, b, c$ in the set satisfy the condition $a + b = c$. The elements must be chosen from the range $[1, 500]$.

## Intuition & Mathematical Observation
To ensure that no two elements sum up to a third element in the set, we need to make the elements "large enough" relative to each other. 

If we select $n$ integers from the upper end of the allowed range (e.g., starting from 500 and counting downwards), we can guarantee the condition. Let our set be $S = \{500, 499, 498, \dots, 500 - n + 1\}$. 

- The smallest element in this set is $500 - n + 1$.
- For $n = 100$, the smallest element is $500 - 100 + 1 = 401$.
- The smallest possible sum of two distinct elements in this set would be the sum of the two smallest elements: $401 + 402 = 803$.
- Since the maximum value in our set is 500, and the smallest possible sum of any two distinct elements is 803 (which is significantly greater than 500), it is impossible for the sum of any two elements to equal a third element present in the set.

This greedy approach effectively avoids the $a + b = c$ condition for all $n \le 100$.

## Complexity Analysis
- **Time Complexity**: $O(n)$ per test case, as we iterate $n$ times to print the numbers. With $T$ test cases, the total time complexity is $O(T \times n)$.
- **Space Complexity**: $O(1)$, as we do not store the elements in an array and print them directly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a set of n integers (1 <= n <= 100) such that no three 
 * distinct elements a, b, c satisfy a + b = c. The elements must be in the range [1, 500].
 * 
 * Strategy:
 * By picking numbers from the upper end of the range [1, 500], specifically 
 * {500, 499, ..., 500 - n + 1}, the smallest sum of two distinct elements 
 * will always exceed the largest element in the set, satisfying the condition.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // Output n integers starting from 500 downwards.
        for (int i = 0; i < n; ++i) {
            cout << (500 - i) << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}
```