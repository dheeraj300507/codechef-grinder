# [Puppy and Sum (PPSUM)](https://www.codechef.com/problems/PPSUM)

- **Difficulty Rating**: 961
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to perform a recursive summation operation $D$ times. We are given a function $sum(N) = \frac{N(N+1)}{2}$. We start with an integer $N$ and apply the $sum$ function to the result $D$ times. Specifically, if $D=1$, the answer is $sum(N)$. If $D=2$, the answer is $sum(sum(N))$, and so on.

## Intuition & Mathematical Observation
The problem defines a nested summation process. Since the constraints on $D$ and $N$ are very small ($D, N \le 4$), we do not need to derive a closed-form formula for the $D$-th iteration. Instead, we can simulate the process directly using a loop.

1. **Base Case**: The sum of integers from $1$ to $N$ is given by the arithmetic series formula: $\frac{N(N+1)}{2}$.
2. **Iteration**: We maintain a variable `current_val` initialized to $N$. We then run a loop $D$ times, updating `current_val` to the result of the sum formula applied to the previous `current_val`.
3. **Data Types**: Given the small constraints, the result will not overflow a standard `long long` (or even an `int`), making the implementation straightforward.

## Complexity Analysis
- **Time Complexity**: $O(D)$ per test case. Since $D \le 4$, this is effectively $O(1)$ constant time.
- **Space Complexity**: $O(1)$ as we only use a few variables to store the current state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Puppy and Sum
 * The function sum(N) is defined as the sum of integers from 1 to N, which is N*(N+1)/2.
 * The function sum(D, N) applies this operation D times.
 * Given the constraints D, N <= 4, the values will be very small, 
 * so standard integer types are sufficient.
 */

long long sum_n(long long n) {
    return n * (n + 1) / 2;
}

void solve() {
    int D;
    long long N;
    cin >> D >> N;
    
    long long current_val = N;
    // Apply the sum_n function D times
    for (int i = 0; i < D; ++i) {
        current_val = sum_n(current_val);
    }
    
    cout << current_val << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```