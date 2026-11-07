# [Even Sum (EVENSUM1)](https://www.codechef.com/problems/EVENSUM1)

- **Difficulty Rating**: 607
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, determine if it is possible to remove exactly one element from the array such that the sum of the remaining elements is even.

## Intuition & Mathematical Observation
Let $S$ be the sum of all elements in the array. When we remove an element $A[i]$, the remaining sum is $S' = S - A[i]$. We want $S'$ to be even, which means $S - A[i] \equiv 0 \pmod 2$.

This leads to two simple cases based on the parity of the total sum $S$:
1. **If $S$ is even**: For $S - A[i]$ to be even, $A[i]$ must be **even** (since Even - Even = Even).
2. **If $S$ is odd**: For $S - A[i]$ to be even, $A[i]$ must be **odd** (since Odd - Odd = Even).

Essentially, we need to check if there exists at least one element $A[i]$ in the array that has the same parity as the total sum $S$. If such an element exists, we can remove it to make the remaining sum even.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array once to calculate the sum and once more to check the condition.
- **Space Complexity**: $O(N)$ to store the array elements. (Note: This could be optimized to $O(1)$ by storing only the count of odd/even numbers, but $O(N)$ is well within limits).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exists an A[i] such that (TotalSum - A[i]) is even.
 * This is equivalent to checking if (TotalSum % 2) == (A[i] % 2).
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    bool found = false;
    for (int i = 0; i < N; ++i) {
        // Check if removing A[i] results in an even sum
        if ((total_sum - A[i]) % 2 == 0) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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