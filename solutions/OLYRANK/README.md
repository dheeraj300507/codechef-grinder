# [Olympics Ranking (OLYRANK)](https://www.codechef.com/problems/OLYRANK)

- **Difficulty Rating**: 893
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine which of two countries ranks higher in the Olympics based on the total number of medals won. You are given the count of Gold, Silver, and Bronze medals for two countries. The country with the strictly greater sum of medals (Gold + Silver + Bronze) is considered to have a higher rank. The problem guarantees that the total number of medals for the two countries will not be equal.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. Since the ranking is determined solely by the sum of all medals, we simply need to:
1. Calculate the sum of medals for Country 1: $Total_1 = G_1 + S_1 + B_1$.
2. Calculate the sum of medals for Country 2: $Total_2 = G_2 + S_2 + B_2$.
3. Compare $Total_1$ and $Total_2$. If $Total_1 > Total_2$, output `1`; otherwise, output `2`.

Because the constraints are small (medals $\le 30$), the sums will easily fit within standard integer types, making this an $O(1)$ calculation per test case.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the medal counts and their sums, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Olympics Ranking
 * The problem asks us to compare the total number of medals (Gold + Silver + Bronze)
 * for two countries and determine which one has a higher total.
 * 
 * Constraints:
 * T <= 1000
 * Medals <= 30
 * Total medals per country <= 90
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long g1, s1, b1, g2, s2, b2;
        cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;

        long long total1 = g1 + s1 + b1;
        long long total2 = g2 + s2 + b2;

        // The problem guarantees no tie, so we only need to check > or <
        if (total1 > total2) {
            cout << "1" << "\n";
        } else {
            cout << "2" << "\n";
        }
    }

    return 0;
}
```