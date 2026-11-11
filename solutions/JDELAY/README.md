# [Judging Delay (JDELAY)](https://www.codechef.com/problems/JDELAY)

- **Difficulty Rating**: 964
- **Solved in**: 1 attempt(s)

## Problem Summary
In this problem, we are given $N$ submissions. For each submission, we are provided with two integers: $S_i$ (the time the submission was sent) and $J_i$ (the time the submission was judged). A submission is considered "delayed" if the difference between the judging time and the submission time is strictly greater than 5 minutes (i.e., $J_i - S_i > 5$). The goal is to count the total number of submissions that meet this criteria.

## Intuition & Mathematical Observation
The problem asks us to evaluate a simple condition for each submission independently. 
- For every submission $i$, we calculate the delay: $D_i = J_i - S_i$.
- We then check if $D_i > 5$.
- Since the constraints are small ($N \le 100$), we can iterate through each submission, perform the subtraction, check the condition, and maintain a counter. No complex data structures or sorting are required.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. We iterate through the list of $N$ submissions exactly once, performing constant-time arithmetic and comparison operations. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$. We only use a few integer variables (`N`, `S`, `J`, `count`) to store the current state, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Judging Delay
 * Approach:
 * For each submission, the delay is calculated as (J_i - S_i).
 * We need to count how many submissions have (J_i - S_i) > 5.
 * Constraints are small (N <= 100, T <= 100), so an O(N) approach per test case is optimal.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int S, J;
        cin >> S >> J;
        // Check if the delay is strictly greater than 5 minutes
        if ((J - S) > 5) {
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}
```