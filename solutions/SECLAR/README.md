# [Find Second Largest (SECLAR)](https://www.codechef.com/problems/SECLAR)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three distinct integers $A$, $B$, and $C$, the objective is to identify and output the second largest value among them.

## Intuition & Mathematical Observation
Since the input size is fixed at exactly three integers, we can simplify the problem by storing the values in a collection. By sorting these three values in non-decreasing order, the second largest value will always occupy the middle position (index 1 in a 0-indexed array/vector). This approach is robust, readable, and handles all permutations of input values efficiently.

## Complexity Analysis
- **Time Complexity**: $O(1)$. Sorting a fixed number of elements (3) takes constant time.
- **Space Complexity**: $O(1)$. We only store three integers regardless of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Find Second Largest
 * Approach: Store the three integers in a vector, sort them, 
 * and pick the middle element (index 1).
 * Time Complexity: O(1) as there are always exactly 3 elements.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading the three integers A, B, and C
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    // Store in a vector and sort
    vector<long long> v = {a, b, c};
    sort(v.begin(), v.end());

    // The second largest element in a sorted list of 3 is at index 1
    cout << v[1] << "\n";

    return 0;
}
```