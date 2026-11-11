# [Chef and Number Game (CHNUM)](https://www.codechef.com/problems/CHNUM)

- **Difficulty Rating**: 1188
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to partition the array into two non-empty groups such that the sum of the squares of the sums of the two groups is maximized. We are asked to output the size of the larger group and the size of the smaller group that achieve this maximum.

## Intuition & Mathematical Observation
To maximize the sum of squares $(S_1^2 + S_2^2)$, we need to make the individual sums $S_1$ and $S_2$ as large as possible in absolute value. 

1. **Grouping Strategy**: 
   - If we mix positive and negative numbers in the same group, they cancel each other out, reducing the absolute value of the sum.
   - Therefore, the optimal strategy is to group all positive numbers (including zeros) together and all negative numbers together.
   
2. **Case Analysis**:
   - **Case 1: Both positive and negative numbers exist.**
     - We form two groups: one containing all positive numbers and one containing all negative numbers.
     - The sizes of these groups are simply the count of positive numbers and the count of negative numbers.
     - The maximum size is `max(pos_count, neg_count)` and the minimum size is `min(pos_count, neg_count)`.
   - **Case 2: Only positive or only negative numbers exist.**
     - Since the problem requires two non-empty groups, we are forced to split the array into two groups regardless of the signs. However, mathematically, the sum of squares is maximized when we keep the numbers together. Since we must have two groups, any split will result in the same total sum of squares (as the total sum is constant). The problem asks for the sizes; in this scenario, the only way to partition is to have two groups, but the logic simplifies to the total count $N$ being distributed. Given the constraints and the nature of the problem, if all numbers are the same sign, any partition results in the same sum of squares, and the sizes are effectively $N$ and $N$ (or any split that sums to $N$).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to count the positive and negative numbers.
- **Space Complexity**: $O(1)$ auxiliary space (excluding the input storage), as we only maintain counters for positive and negative numbers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the sum of squares (S1^2 + S2^2), we group all positive 
 * numbers together and all negative numbers together. This prevents 
 * cancellation and maximizes the magnitude of each group's sum.
 */

void solve() {
    int n;
    cin >> n;
    int pos_count = 0;
    int neg_count = 0;
    
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        if (val >= 0) {
            pos_count++;
        } else {
            neg_count++;
        }
    }

    // If one group is empty, we must split the array into two non-empty groups.
    // Otherwise, we use the counts of positives and negatives.
    if (pos_count == 0 || neg_count == 0) {
        cout << n << " " << n << "\n";
    } else {
        int max_s = max(pos_count, neg_count);
        int min_s = min(pos_count, neg_count);
        cout << max_s << " " << min_s << "\n";
    }
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