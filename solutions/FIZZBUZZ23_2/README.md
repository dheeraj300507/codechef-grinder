# [Survival Time (FIZZBUZZ23_2)](https://www.codechef.com/problems/FIZZBUZZ23_2)

- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
A family of 5 members needs to survive for a certain number of days. Each member consumes $X$ buns per day. You are given $N$ (total buns available) and $D$ (extra days the family can survive without any buns). Calculate the total number of days the family can survive.

## Intuition & Mathematical Observation
1. **Daily Consumption**: Since there are 5 members and each consumes $X$ buns, the total consumption per day is $5 \times X$.
2. **Buns Duration**: The number of days the buns will last is determined by dividing the total buns $N$ by the daily consumption ($5 \times X$). Using integer division (`N / (5 * X)`) gives us the exact number of full days the family can survive on the available buns.
3. **Total Survival**: The family survives for the duration the buns last, plus the additional $D$ days they can survive without food. Therefore, the formula is:
   $$\text{Total Days} = \left\lfloor \frac{N}{5 \times X} \right\rfloor + D$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Daily consumption = 5 * X.
 * Number of days the buns last = N / (5 * X) (integer division).
 * Total survival days = (Days buns last) + D.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, d;
        cin >> n >> x >> d;

        // Total buns consumed by the family per day
        long long daily_consumption = 5 * x;

        // Days the buns last
        long long days_with_buns = n / daily_consumption;

        // Total survival time
        long long total_days = days_with_buns + d;

        cout << total_days << "\n";
    }

    return 0;
}
```