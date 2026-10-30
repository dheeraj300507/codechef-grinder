# [Expensive Buying (BUYING7)](https://www.codechef.com/problems/BUYING7)

- **Difficulty Rating**: 635
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a list of $N$ item prices, we need to select exactly $K$ items such that the total cost is maximized. In other words, we need to find the sum of the $K$ most expensive items available in the list.

## Intuition & Mathematical Observation
To maximize the total sum of $K$ items, we must always pick the items with the highest numerical values. 
1. **Sorting**: By sorting the array of prices in ascending order, the largest elements will naturally be positioned at the end of the array (from index $N-K$ to $N-1$).
2. **Summation**: Once sorted, we simply iterate through the last $K$ elements of the array and accumulate their sum.
3. **Data Types**: Since the sum of prices might exceed the capacity of a 32-bit integer, we use `long long` to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of items. The dominant factor is the sorting algorithm used by `std::sort`.
- **Space Complexity**: $O(N)$ to store the prices of the $N$ items in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Expensive Buying
 * Approach:
 * To find the sum of the K most expensive items, we sort the array of prices
 * in ascending order and sum the last K elements.
 * 
 * Time Complexity: O(T * N log N)
 * Space Complexity: O(N)
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<long long> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    // Sort the prices in ascending order
    sort(C.begin(), C.end());
    
    // Sum the last K elements (the K largest)
    long long total_cost = 0;
    for (int i = N - 1; i >= N - K; --i) {
        total_cost += C[i];
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```