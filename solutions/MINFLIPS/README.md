# [Minimum number of Flips (MINFLIPS)](https://www.codechef.com/problems/MINFLIPS)

- **Difficulty Rating**: 781
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of size $N$ consisting only of $1$s and $-1$s, we want to make the sum of the array equal to $0$ by flipping the sign of some elements (changing $1$ to $-1$ or vice versa). We need to find the minimum number of flips required to achieve this, or return $-1$ if it is impossible.

## Intuition & Mathematical Observation
1. **Parity Constraint**: For the sum of an array of $1$s and $-1$s to be $0$, the total number of elements $N$ must be even. If $N$ is odd, it is mathematically impossible to have an equal number of $1$s and $-1$s, so we output $-1$.
2. **Target State**: If $N$ is even, we need exactly $N/2$ elements to be $1$ and $N/2$ elements to be $-1$ to ensure the sum is $0$.
3. **Calculating Flips**: Let $P$ be the count of $1$s currently in the array.
   - If $P > N/2$, we have too many $1$s. We must flip $(P - N/2)$ of them to $-1$.
   - If $P < N/2$, we have too few $1$s (meaning we have too many $-1$s). We must flip $(N/2 - P)$ of the $-1$s to $1$.
   - In both scenarios, the minimum number of operations is simply $|P - N/2|$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to count the number of $1$s.
- **Space Complexity**: $O(1)$ (excluding the input storage), as we only use a few integer variables to keep track of counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N be the number of elements.
 * Let P be the count of 1s.
 * For the sum to be 0, the total number of elements N must be even.
 * If N is odd, it is impossible to have a sum of 0, so output -1.
 * 
 * If N is even, we need the final count of 1s to be N/2 and -1s to be N/2.
 * The number of operations required is |P - N/2|.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int P = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] == 1) {
            P++;
        }
    }

    // If N is odd, sum can never be 0
    if (N % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    // Target count for 1s is N/2
    int target = N / 2;
    int diff = abs(P - target);
    
    cout << diff << "\n";
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