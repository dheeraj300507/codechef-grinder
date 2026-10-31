# [Minimum XOR (MINMXOR)](https://www.codechef.com/problems/MINMXOR)

- **Difficulty Rating**: 1154
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to find the minimum possible XOR sum of the array after either removing exactly one element or removing no elements at all.

## Intuition & Mathematical Observation
Let $S$ be the XOR sum of all elements in the array: $S = A_1 \oplus A_2 \oplus \dots \oplus A_N$.

1. **Case 1: Removing no elements.** The XOR sum remains $S$.
2. **Case 2: Removing one element $A_i$.** The new XOR sum becomes $S \oplus A_i$. This is because the XOR operation is its own inverse ($x \oplus x = 0$), so removing $A_i$ from the total XOR sum is equivalent to XORing the total sum by $A_i$.

To find the minimum XOR sum, we simply calculate $S$ first, then iterate through the array to compute $S \oplus A_i$ for every $i$, keeping track of the minimum value encountered among $S$ and all possible $S \oplus A_i$ values.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array twice: once to calculate the total XOR sum and once to check the result of removing each element.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we store the elements in a way that allows a second pass or re-read, but $O(N)$ is well within limits for the given constraints.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the XOR sum of all elements A_1, A_2, ..., A_N.
 * If we remove no element, the XOR sum is S.
 * If we remove an element A_i, the new XOR sum is S ^ A_i.
 * We want to find min(S, min_{i=1 to N} (S ^ A_i)).
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total_xor = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_xor ^= a[i];
    }

    // Option 1: Don't remove any element
    int min_xor = total_xor;

    // Option 2: Remove exactly one element A_i
    // The new XOR sum will be total_xor ^ A_i
    for (int i = 0; i < n; ++i) {
        int current_xor = total_xor ^ a[i];
        if (current_xor < min_xor) {
            min_xor = current_xor;
        }
    }

    cout << min_xor << "\n";
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