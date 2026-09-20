# [Email Reminders (EMAILREM)](https://www.codechef.com/problems/EMAILREM)

- **Difficulty Rating**: 379
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the number of participants who should receive an email reminder. We are given the total number of participants ($N$) and the number of participants who have opted out of receiving emails ($U$). The goal is to find the difference between the total participants and those who opted out.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic subtraction. Since $N$ represents the total population and $U$ represents the subset that is excluded, the number of people remaining to receive the email is simply:
$$\text{Result} = N - U$$

Given the constraints ($1 \le U < N \le 10^5$), the result will always be a positive integer, and the calculation is trivial to perform in constant time.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as it involves a single subtraction operation.
- **Space Complexity**: $O(1)$, as we only store two integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N total participants and U participants who opted out.
 * The number of participants to send emails to is simply N - U.
 * 
 * Constraints:
 * 1 <= U < N <= 10^5
 * The result will fit in a standard integer, but using long long is safe practice.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading N (total participants) and U (opted out participants)
    long long N, U;
    if (cin >> N >> U) {
        // Output the difference
        cout << (N - U) << "\n";
    }

    return 0;
}
```