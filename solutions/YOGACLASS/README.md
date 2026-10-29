# [Yoga Class (YOGACLASS)](https://www.codechef.com/problems/YOGACLASS)

- **Difficulty Rating**: 879
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ hours available for yoga. He can choose between two types of sessions:
1. **Type 1**: Lasts 1 hour and earns $X$ coins.
2. **Type 2**: Lasts 2 hours and earns $Y$ coins.

The goal is to maximize the total earnings by choosing any combination of these sessions such that the total time spent does not exceed $N$ hours.

## Intuition & Mathematical Observation
To maximize earnings, we need to decide how many 2-hour sessions ($k$) to perform. Since each 2-hour session takes up 2 hours of the total $N$ hours, the number of 2-hour sessions $k$ can range from $0$ to $\lfloor N/2 \rfloor$.

For any chosen $k$:
- The number of 2-hour sessions is $k$.
- The remaining time is $N - 2k$, which will be filled by 1-hour sessions.
- Total earnings = $(k \times Y) + ((N - 2k) \times X)$.

Since the constraints on $N$ are small ($N \le 1000$), we can iterate through every possible value of $k$ from $0$ to $N/2$ and calculate the total earnings for each, keeping track of the maximum value found.

*Note: While this can also be solved in $O(1)$ by comparing $2X$ and $Y$ (greedy approach), the $O(N)$ iteration is perfectly efficient for the given constraints.*

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate from $0$ to $N/2$. With $T$ test cases, the total complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the maximum earnings.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Type 1: 1 hour, earns X.
 * Type 2: 2 hours, earns Y.
 * We want to maximize earnings.
 * 
 * Since Type 2 sessions are 2 hours long, we can take at most N/2 sessions of Type 2.
 * Let k be the number of Type 2 sessions (0 <= k <= N/2).
 * The remaining (N - 2k) hours will be filled with Type 1 sessions.
 * Total earnings = k * Y + (N - 2k) * X.
 * 
 * We can iterate through all possible values of k from 0 to N/2 and find the maximum.
 * Given N <= 1000, an O(N) approach per test case is well within the time limit.
 */

void solve() {
    int N, X, Y;
    cin >> N >> X >> Y;

    long long max_earnings = 0;

    // k is the number of Type 2 sessions
    for (int k = 0; k <= N / 2; ++k) {
        long long current_earnings = (long long)k * Y + (long long)(N - 2 * k) * X;
        if (current_earnings > max_earnings) {
            max_earnings = current_earnings;
        }
    }

    cout << max_earnings << "\n";
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