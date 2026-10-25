# [Chef and Eid (EID)](https://www.codechef.com/problems/EID)

- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ coins with various values, the goal is to select two distinct coins such that the absolute difference between their values is minimized. We need to output this minimum difference.

## Intuition & Mathematical Observation
To minimize the absolute difference $|v_i - v_j|$ between any two elements in an array, the most efficient approach is to sort the array first. 

**Why sorting works:**
1. Once the array is sorted such that $v_1 \le v_2 \le \dots \le v_N$, the minimum difference must exist between two **adjacent** elements.
2. If we consider any two non-adjacent elements $v_i$ and $v_j$ (where $j > i+1$), the difference $v_j - v_i$ can be expressed as the sum of adjacent differences: $(v_j - v_{j-1}) + (v_{j-1} - v_{j-2}) + \dots + (v_{i+1} - v_i)$.
3. Since all coin values are non-negative, each term in that sum is $\ge 0$. Therefore, $v_j - v_i \ge v_{k+1} - v_k$ for any $k$ between $i$ and $j-1$.
4. Thus, we only need to calculate $v_{i+1} - v_i$ for all $0 \le i < N-1$ and track the minimum value found.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the coin values in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N coins with values v_1, v_2, ..., v_N.
 * We need to select two distinct coins such that the absolute difference 
 * between their values is minimized.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    
    // Sort the coin values to bring the closest values next to each other
    sort(v.begin(), v.end());
    
    // Initialize min_diff with a large value
    // Since max v_i is 10^6, the difference will not exceed 10^6
    long long min_diff = 2000000; 
    
    // Find the minimum difference between adjacent elements
    for (int i = 0; i < N - 1; ++i) {
        long long diff = v[i + 1] - v[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
        // Optimization: if diff is 0, it's the smallest possible absolute difference
        if (min_diff == 0) break;
    }
    
    cout << min_diff << "\n";
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