# [Valentine Gifts (VAL142)](https://www.codechef.com/problems/VAL142)

- **Difficulty Rating**: 729
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether it is possible to choose 7 positive integers $g_1, g_2, \dots, g_7$ such that each subsequent gift is at least twice the value of the previous one ($g_i \ge 2 \cdot g_{i-1}$), given that the total sum of these gifts must not exceed a given integer $X$.

## Intuition & Mathematical Observation
To determine if it is possible to satisfy the condition, we must find the **minimum possible sum** of 7 such integers. If the minimum sum is less than or equal to $X$, the answer is "YES"; otherwise, it is "NO".

To minimize the sum, we choose the smallest possible values for each gift:
- $g_1 = 1$
- $g_2 = 2 \times g_1 = 2$
- $g_3 = 2 \times g_2 = 4$
- $g_4 = 2 \times g_3 = 8$
- $g_5 = 2 \times g_4 = 16$
- $g_6 = 2 \times g_5 = 32$
- $g_7 = 2 \times g_6 = 64$

Calculating the sum:
$1 + 2 + 4 + 8 + 16 + 32 + 64 = 127$

Since this is a geometric progression where the sum is $a(r^n - 1) / (r - 1)$ with $a=1, r=2, n=7$, the sum is $1(2^7 - 1) / (2 - 1) = 127$. Any other set of integers satisfying the constraints will result in a sum $\ge 127$. Therefore, the condition is satisfied if and only if $X \ge 127$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exist 7 positive integers g1, g2, ..., g7 such that:
 * g1 >= 1
 * g2 >= 2 * g1
 * g3 >= 2 * g2
 * ...
 * g7 >= 2 * g6
 * And the sum g1 + g2 + ... + g7 <= X.
 * 
 * The minimum sum required is 127. If X >= 127, it is possible.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // The minimum sum required for 7 days is 127.
        if (x >= 127) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```