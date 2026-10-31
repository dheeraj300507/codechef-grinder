# [Temple Land (TEMPLELA)](https://www.codechef.com/problems/TEMPLELA)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given sequence of strip heights represents a valid "Temple." A valid temple must satisfy the following criteria:
1. The length of the strip ($N$) must be odd.
2. The first and last elements must be 1.
3. The sequence must start at 1, increase by 1 until it reaches the center element, and then decrease by 1 until it reaches 1 at the end.

## Intuition & Mathematical Observation
A valid temple sequence is essentially a symmetric "pyramid" structure. 
- **Symmetry**: Since the sequence must increase and then decrease, the peak (center) must be at index $N/2$ (using 0-based indexing). The value at the peak must be $(N+1)/2$.
- **Constraints**: 
    - If $N$ is even, it is impossible to have a single peak, so we immediately reject it.
    - If the first element is not 1, it violates the base requirement.
    - By iterating through the array, we can verify that each subsequent element is exactly 1 greater than the previous (for the first half) or 1 less than the previous (for the second half). If any element deviates from this pattern, the sequence is invalid.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of strips. We iterate through the array once to validate the sequence.
- **Space Complexity**: $O(N)$ to store the input array of heights.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. The strip length Ni must be odd to have a unique center.
 * 2. The first element must be 1.
 * 3. The sequence must increase by 1 until the center, then decrease by 1.
 * 4. This implies the sequence must be 1, 2, 3, ..., (Ni+1)/2, ..., 3, 2, 1.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Condition 1: Length must be odd to have a unique center
    if (n % 2 == 0) {
        cout << "no" << "\n";
        return;
    }

    // Condition 2: First and last must be 1
    if (h[0] != 1 || h[n - 1] != 1) {
        cout << "no" << "\n";
        return;
    }

    int center_idx = n / 2;
    
    // Check increasing part (0 to center)
    for (int i = 0; i < center_idx; ++i) {
        if (h[i + 1] != h[i] + 1) {
            cout << "no" << "\n";
            return;
        }
    }

    // Check decreasing part (center to end)
    for (int i = center_idx; i < n - 1; ++i) {
        if (h[i + 1] != h[i] - 1) {
            cout << "no" << "\n";
            return;
        }
    }

    cout << "yes" << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    if (!(cin >> s)) return 0;
    while (s--) {
        solve();
    }
    return 0;
}
```