# [Alternating Array (ALTARR)](https://www.codechef.com/problems/ALTARR)

- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to make the array "alternating." An array is alternating if the parity (odd/even status) of adjacent elements is always different. We need to find the minimum number of elements that must be changed (by replacing them with any other integer of the desired parity) to satisfy this condition.

## Intuition & Mathematical Observation
An alternating array can only follow one of two possible parity patterns:
1. **Pattern 1**: Starts with an Odd number (Odd, Even, Odd, Even, ...).
2. **Pattern 2**: Starts with an Even number (Even, Odd, Even, Odd, ...).

For any given array, we can calculate the cost (number of changes) to transform it into Pattern 1 and the cost to transform it into Pattern 2:
- For **Pattern 1**, the expected parity at index $i$ is $1$ if $i$ is even and $0$ if $i$ is odd.
- For **Pattern 2**, the expected parity at index $i$ is $0$ if $i$ is even and $1$ if $i$ is odd.

By iterating through the array once, we count how many elements deviate from these two patterns. The final answer is simply the minimum of these two counts, as we only need to achieve one of the two valid configurations.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the array. We perform a single pass through the array to calculate the costs for both patterns.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we process the input elements on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of A[i] is different from A[i+1] for all i.
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Starts with Odd (Odd, Even, Odd, Even, ...)
 * Pattern 2: Starts with Even (Even, Odd, Even, Odd, ...)
 * 
 * We calculate the number of changes required to match Pattern 1 and Pattern 2,
 * then take the minimum of the two.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // count1: changes needed if we force the pattern: Odd, Even, Odd, Even...
    // count2: changes needed if we force the pattern: Even, Odd, Even, Odd...
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < N; ++i) {
        int parity = A[i] % 2; // 1 for Odd, 0 for Even
        
        // Pattern 1: index 0 should be Odd (1), index 1 should be Even (0)...
        // Expected parity at index i is (i % 2 == 0) ? 1 : 0
        int expected1 = (i % 2 == 0) ? 1 : 0;
        if (parity != expected1) {
            count1++;
        }

        // Pattern 2: index 0 should be Even (0), index 1 should be Odd (1)...
        // Expected parity at index i is (i % 2 == 0) ? 0 : 1
        int expected2 = (i % 2 == 0) ? 0 : 1;
        if (parity != expected2) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
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