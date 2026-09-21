# [Candies (CNDY)](https://www.codechef.com/problems/CNDY)

- **Difficulty Rating**: 1018
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array of $2N$ integers. The goal is to determine if it is possible to partition these $2N$ integers into two distinct sets, each of size $N$, such that every element within each set is unique.

## Intuition & Mathematical Observation
The core constraint is that each set must contain only distinct elements. 

1. **The Frequency Constraint**: If any specific number appears 3 or more times in the input array, it is impossible to distribute them into two sets without at least one set containing the same number more than once.
2. **The Sufficiency**: If every number appears at most twice, we can always form two valid sets. For every number that appears twice, we place one instance in the first set and one in the second. For numbers that appear only once, we can distribute them into the remaining slots of either set until both sets reach size $N$.
3. **Conclusion**: The problem reduces to checking if the frequency of every element in the input array is less than or equal to 2.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the implementation. Using a `std::map` as shown in the code results in $O(N \log N)$ due to tree-based insertions. Using an unordered map or a frequency array (if the range of values is small) would yield $O(N)$.
- **Space Complexity**: $O(N)$ to store the frequency counts of the elements in the map.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given 2N integers. We need to split them into two sets of size N,
 * where each set contains only distinct elements.
 * 
 * This is possible if and only if no element appears more than twice in the 
 * original array of 2N elements.
 */

void solve() {
    int N;
    cin >> N;
    int total_elements = 2 * N;
    map<int, int> counts;
    bool possible = true;
    
    for (int i = 0; i < total_elements; ++i) {
        int a;
        cin >> a;
        counts[a]++;
        // If any element appears more than twice, it's impossible
        if (counts[a] > 2) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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