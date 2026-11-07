# [Max Nutrition (NUTRITION)](https://www.codechef.com/problems/NUTRITION)

- **Difficulty Rating**: 1123
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ fruits, where each fruit $i$ has a specific type $A_i$ and a nutrition value $B_i$. You are allowed to eat at most one fruit of each type. The goal is to select a subset of fruits such that you eat at most one of each type and the total nutrition value is maximized.

## Intuition & Mathematical Observation
To maximize the total nutrition, we need to make an optimal choice for each fruit type independently:
1. **Group by Type**: For every unique fruit type present in the input, we want to pick the fruit that provides the highest nutrition value.
2. **Filter Negative Values**: If the maximum nutrition value for a specific fruit type is negative, it is better to not eat any fruit of that type at all (since eating nothing contributes 0, which is greater than a negative value).
3. **Aggregation**: The final answer is the sum of the maximum nutrition values for all types, considering only those types where the maximum value is greater than zero.

We can efficiently track the maximum value for each type using an array of size $N+1$ (since fruit types are indexed up to $N$), initialized to a value lower than any possible nutrition value.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of fruits. We iterate through the list of fruits once to find the maximums and then iterate through the array of types once to calculate the sum.
- **Space Complexity**: $O(N)$ to store the `max_nutrition` array for the fruit types.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N fruits, each with a type A_i and a nutrition value B_i.
 * We can eat at most one fruit of each type.
 * To maximize the total nutrition, for each unique fruit type present,
 * we should pick the fruit with the maximum nutrition value, provided that
 * the value is positive. If the maximum value for a type is negative,
 * we choose not to eat any fruit of that type (contributing 0).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> B(N);
    for (int i = 0; i < N; ++i) cin >> B[i];

    // max_nutrition[type] stores the highest nutrition value for that type.
    // Initialize with a value smaller than any possible B_i.
    vector<int> max_nutrition(N + 1, -1000);

    for (int i = 0; i < N; ++i) {
        if (B[i] > max_nutrition[A[i]]) {
            max_nutrition[A[i]] = B[i];
        }
    }

    long long total_nutrition = 0;
    for (int i = 1; i <= N; ++i) {
        // Only add if the max nutrition for this type is positive.
        if (max_nutrition[i] > 0) {
            total_nutrition += max_nutrition[i];
        }
    }

    cout << total_nutrition << "\n";
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