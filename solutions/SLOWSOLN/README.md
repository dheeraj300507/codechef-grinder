# [Slow Solution (SLOWSOLN)](https://www.codechef.com/problems/SLOWSOLN)

- **Difficulty Rating**: 1003
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a maximum number of test cases ($T$), a maximum value for each test case ($N$), and a total sum of values ($sumN$). We need to partition $sumN$ into at most $T$ integers, where each integer $N_i \le N$, such that the sum of their squares ($\sum N_i^2$) is maximized.

## Intuition & Mathematical Observation
The function $f(x) = x^2$ is a **convex function**. In optimization, to maximize the sum of convex functions, we want to make the individual variables as large as possible rather than distributing the sum evenly.

1. **Greedy Approach**: To maximize the sum of squares, we should prioritize assigning the largest possible value ($N$) to each test case.
2. **Constraint Handling**:
   - We have $T$ slots available.
   - We fill as many slots as possible with the value $N$.
   - If the number of full slots ($sumN / N$) is less than $T$, we fill those slots with $N$ and put the remaining value ($sumN \pmod N$) into one additional slot.
   - If the number of full slots is greater than or equal to $T$, we are limited by the number of test cases. We simply fill all $T$ slots with $N$. Any remaining sum beyond $T \times N$ is ignored because we cannot exceed $T$ test cases.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. The total time complexity is $O(t)$, where $t$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize the sum of squares of N_i, given:
 * 1. 1 <= T <= maxT
 * 2. 1 <= N_i <= maxN
 * 3. Sum(N_i) <= sumN
 * 
 * To maximize the sum of squares, we want the values of N_i to be as large as possible.
 * Since the function f(x) = x^2 is convex, we should make as many N_i as possible 
 * equal to maxN.
 */

void solve() {
    long long maxT, maxN, sumN;
    cin >> maxT >> maxN >> sumN;

    long long num_full = sumN / maxN;
    long long remainder = sumN % maxN;

    long long total_iterations = 0;

    if (num_full >= maxT) {
        // We are limited by the number of test cases.
        // We use maxT test cases of size maxN.
        total_iterations = maxT * (maxN * maxN);
    } else {
        // We can use num_full test cases of size maxN, 
        // and one test case of size remainder.
        total_iterations = num_full * (maxN * maxN) + (remainder * remainder);
    }

    cout << total_iterations << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```