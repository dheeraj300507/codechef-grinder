# [Running Comparison (RUNCOMPARE)](https://www.codechef.com/problems/RUNCOMPARE)

- **Difficulty Rating**: 899
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob run for $N$ days. On each day $i$, Alice runs $A_i$ distance and Bob runs $B_i$ distance. A day is considered "happy" if both Alice and Bob are satisfied with their performance relative to each other. Specifically:
- Alice is happy if $B_i \le 2 \cdot A_i$.
- Bob is happy if $A_i \le 2 \cdot B_i$.
The goal is to count the total number of days where both Alice and Bob are happy.

## Intuition & Mathematical Observation
The problem asks us to evaluate a condition for each day independently. For a given day $i$, both individuals are happy if and only if the following two inequalities are satisfied simultaneously:
1. $B_i \le 2 \cdot A_i$
2. $A_i \le 2 \cdot B_i$

Since the constraints are small ($N \le 100$ and $T \le 1000$), a simple linear scan through the arrays is sufficient. We iterate from $0$ to $N-1$, check the conditions for each index, and increment a counter whenever both conditions hold true.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. Given $T$ test cases, the total time complexity is $O(T \times N)$. With $N=100$ and $T=1000$, the total operations are roughly $10^5$, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the distances for Alice and Bob. This can be optimized to $O(1)$ if we process the inputs on the fly, but $O(N)$ is well within memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice is happy if Bob <= 2 * Alice.
 * Bob is happy if Alice <= 2 * Bob.
 * Both are happy if (Bob <= 2 * Alice) AND (Alice <= 2 * Bob).
 * 
 * Constraints:
 * N <= 100, T <= 1000.
 * A_i, B_i <= 10^5.
 * Since 2 * 10^5 fits in a standard 32-bit integer, 'int' is sufficient, 
 * but 'long long' is used for safety against potential overflow in intermediate calculations.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int happy_days = 0;
    for (int i = 0; i < N; ++i) {
        // Alice is happy if B[i] <= 2 * A[i]
        // Bob is happy if A[i] <= 2 * B[i]
        bool alice_happy = (B[i] <= 2 * A[i]);
        bool bob_happy = (A[i] <= 2 * B[i]);

        if (alice_happy && bob_happy) {
            happy_days++;
        }
    }
    cout << happy_days << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```