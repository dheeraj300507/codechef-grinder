# [Chef and Mean (CHFM)](https://www.codechef.com/problems/CHFM)

- **Difficulty Rating**: 1229
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ coins with values $A_1, A_2, \dots, A_N$, we need to determine if removing exactly one coin results in a new mean equal to the original mean of the $N$ coins. If such a coin exists, we must output the 1-based index of the first coin that satisfies this condition. If multiple coins satisfy the condition, the problem implies any valid index is acceptable (though the logic shows only one value is possible). If no such coin exists, output "Impossible".

## Intuition & Mathematical Observation
Let $S$ be the sum of all $N$ coins. The original mean is $M = \frac{S}{N}$.
If we remove a coin with value $A_i$, the new sum becomes $S - A_i$ and the new count becomes $N - 1$. We want the new mean to equal the original mean:

$$\frac{S - A_i}{N - 1} = \frac{S}{N}$$

By cross-multiplying:
$$N(S - A_i) = S(N - 1)$$
$$NS - N \cdot A_i = NS - S$$
$$-N \cdot A_i = -S$$
$$A_i = \frac{S}{N}$$

**Key Findings:**
1. The value of the coin to be removed must be exactly equal to the original mean of the array.
2. For the mean to be an integer, $S$ must be perfectly divisible by $N$ ($S \% N == 0$). If it is not, it is impossible for any integer coin value to equal the mean.
3. We simply calculate the target value $M = S/N$ and iterate through the array to find the first index $i$ where $A_i = M$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. We iterate through the array once to calculate the sum and once more to find the target value.
- **Space Complexity**: $O(N)$ to store the array elements. (Note: This could be optimized to $O(1)$ if we store the target and perform the search during the initial input reading, but $O(N)$ is well within limits for $N=10^5$).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition (S - A_i) / (N - 1) = S / N simplifies to A_i = S / N.
 * We calculate the total sum, check if it's divisible by N, and then
 * search for the first occurrence of the value (S/N).
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    // Check if the mean is an integer
    if (sum % N != 0) {
        cout << "Impossible" << "\n";
        return;
    }

    long long target = sum / N;
    // Find the first index i such that A[i] == target
    for (int i = 0; i < N; ++i) {
        if (A[i] == target) {
            cout << (i + 1) << "\n";
            return;
        }
    }

    cout << "Impossible" << "\n";
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