# [Temple Land (TEMPLELA)](https://www.codechef.com/problems/TEMPLELA)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given sequence of strip heights represents a valid "Temple." A valid temple must satisfy the following criteria:
1. The length of the strip ($N$) must be odd.
2. The first and last elements must be 1.
3. The sequence must increase by exactly 1 at each step until it reaches the center element, and then decrease by exactly 1 until the end.

## Intuition & Mathematical Observation
To validate the sequence, we can break the requirements down into logical checks:
*   **Parity Check**: If $N$ is even, it is impossible to have a single peak element, so we immediately return "no".
*   **Boundary Check**: The sequence must start and end with 1. If `h[0] != 1` or `h[n-1] != 1`, it is invalid.
*   **Incremental Logic**: 
    *   From the start to the center, each subsequent element must be exactly 1 greater than the previous element (`h[i+1] == h[i] + 1`).
    *   From the center to the end, each subsequent element must be exactly 1 less than the previous element (`h[i+1] == h[i] - 1`).
*   **Center Point**: By ensuring the sequence starts at 1, increases by 1 until the middle, and decreases by 1 until the end, the peak value will naturally be $(N+1)/2$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the strip. We iterate through the array once to verify the conditions.
- **Space Complexity**: $O(N)$ to store the input strip in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. The length Ni must be odd for a unique center to exist.
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

    // Condition 2: Must start and end with 1
    if (h[0] != 1 || h[n - 1] != 1) {
        cout << "no" << "\n";
        return;
    }

    int center_idx = n / 2;
    
    // Check increasing part
    for (int i = 0; i < center_idx; ++i) {
        if (h[i + 1] != h[i] + 1) {
            cout << "no" << "\n";
            return;
        }
    }

    // Check decreasing part
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