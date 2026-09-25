# [Valentines Contest (VAL114)](https://www.codechef.com/problems/VAL114)

- **Difficulty Rating**: 318
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given contest number $N$ corresponds to the Valentine's Day contest. Specifically, we are told that Starters 120 is today and Starters 121 is expected to fall on Valentine's Day. Given an integer $N$, we must output "Likely" if $N = 121$, and "Unlikely" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. Since the condition for the contest being on Valentine's Day is explicitly defined as $N = 121$, we simply need to compare the input $N$ against the constant $121$. 

- If $N == 121$, the condition is satisfied.
- For any other value in the given range ($120, 122, 123$), the condition is not satisfied.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a single integer comparison.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that Starters 120 is today, and Starters 121 is likely 
 * to be on Valentine's Day. Given N, we need to check if N == 121.
 * 
 * Constraints: 120 <= N <= 123.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        if (N == 121) {
            cout << "Likely" << "\n";
        } else {
            cout << "Unlikely" << "\n";
        }
    }

    return 0;
}
```