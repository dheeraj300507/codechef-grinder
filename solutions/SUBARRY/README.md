# Interesting Subarray (SUBARRY)

- **Difficulty Rating**: 1375
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we define the "interesting value" of a subarray as the product of its minimum and maximum elements. We need to find the minimum and maximum possible interesting values across all possible subarrays of $A$.

## Intuition & Mathematical Observation
The key observation is that for any subarray, its minimum and maximum values are constrained by the global minimum and maximum values of the entire array. 

1.  **Maximum Value**: 
    The maximum possible product is achieved by either the square of the largest positive number or the square of the smallest (most negative) number. Since any single element $[A_i]$ is a valid subarray with value $A_i^2$, the maximum value is simply $\max(\text{min\_val}^2, \text{max\_val}^2)$.

2.  **Minimum Value**:
    *   If the array contains both positive and negative numbers, the product of the global minimum and global maximum will likely be a large negative number, which is a strong candidate for the minimum.
    *   If all numbers are positive, the minimum is simply the square of the smallest element.
    *   If all numbers are negative, the minimum is the square of the largest element (the one closest to zero).
    *   By considering the products of the global extremes ($\text{min\_val} \times \text{max\_val}$, $\text{min\_val}^2$, and $\text{max\_val}^2$), we cover all edge cases (such as the presence of zeros or mixed signs) to find the global minimum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we only need to iterate through the array once to find the global minimum and maximum values.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if we process elements on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "interesting value" of a subarray is min(subarray) * max(subarray).
 * We find the global min and max of the array. The answer is derived from 
 * the products of these global extremes.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long min_val = a[0];
    long long max_val = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    // The maximum possible value is the square of the largest absolute value.
    long long ans_max = max(min_val * min_val, max_val * max_val);

    // The minimum possible value is the minimum of the product of global extremes
    // and the squares of the extremes themselves.
    long long ans_min = min({min_val * max_val, min_val * min_val, max_val * max_val});

    cout << ans_min << " " << ans_max << "\n";
}

int main() {
    // Optimize I/O operations
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