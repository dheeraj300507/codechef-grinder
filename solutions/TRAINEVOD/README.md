# [Train Even or Odd (TRAINEVOD)](https://www.codechef.com/problems/TRAINEVOD)

- **Difficulty Rating**: 608
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a training schedule for $N$ days, where each day $i$ has a specific number of training hours $A_i$. Chef can choose to train either on all odd-indexed days (1, 3, 5, ...) or all even-indexed days (2, 4, 6, ...). The goal is to determine the maximum total number of training hours Chef can achieve by choosing the optimal set of days.

## Intuition & Mathematical Observation
The problem asks us to compare two distinct sums:
1. **Odd Sum**: The sum of hours on days 1, 3, 5, ...
2. **Even Sum**: The sum of hours on days 2, 4, 6, ...

Since the input array is 0-indexed in C++, an element at index `i` corresponds to day `i + 1`. 
- If `(i + 1)` is odd, we add the value to `odd_sum`.
- If `(i + 1)` is even, we add the value to `even_sum`.

After iterating through all $N$ days, we simply output the maximum of these two sums using the `std::max` function. Given the constraints ($N \le 100$ and $A_i \le 100$), the maximum possible sum is $10,000$, which easily fits within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of $N$ elements exactly once.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if we process the input on the fly without storing it in a vector).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef can choose to go to the gym on either:
 * 1. All odd-indexed days (1, 3, 5, ...)
 * 2. All even-indexed days (2, 4, 6, ...)
 * 
 * We need to calculate the sum of hours for odd-indexed days and 
 * the sum of hours for even-indexed days, then return the maximum of the two.
 */

void solve() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    long long odd_sum = 0;
    long long even_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // Days are 1-indexed in the problem description.
        // If i is 0, 2, 4... (even index in 0-based array), it corresponds to day 1, 3, 5...
        if ((i + 1) % 2 != 0) {
            odd_sum += A[i];
        } else {
            even_sum += A[i];
        }
    }
    
    cout << max(odd_sum, even_sum) << "\n";
}

int main() {
    // Fast I/O
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