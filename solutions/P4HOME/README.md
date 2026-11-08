# [Chef and Close Friends (P4HOME)](https://www.codechef.com/problems/P4HOME)

- **Difficulty Rating**: 749
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is located at position $x$ on a number line. His friends are located at all integer positions in the range $[x - y, x + y]$, excluding his own position $x$. Chef can travel to any position within the range $[x - z, x + z]$. We need to determine the total number of friends Chef can visit, which corresponds to the number of integer positions that fall within both ranges, excluding $x$.

## Intuition & Mathematical Observation
1. **Range Intersection**: 
   - The friends are located in the interval $I_1 = [x - y, x + y]$.
   - Chef can reach any point in the interval $I_2 = [x - z, x + z]$.
   - The set of reachable friends is the intersection $I_1 \cap I_2$.
   - Since both intervals are centered at $x$, the intersection is simply $[x - \min(y, z), x + \min(y, z)]$.

2. **Counting Points**:
   - Let $k = \min(y, z)$. The intersection range is $[x - k, x + k]$.
   - The total number of integers in an interval $[a, b]$ is $(b - a) + 1$.
   - For $[x - k, x + k]$, the number of integers is $(x + k) - (x - k) + 1 = 2k + 1$.
   - Since the problem states we must exclude Chef's own position ($x$), we subtract 1 from the total count:
     $$\text{Number of friends} = (2k + 1) - 1 = 2k$$
   - Substituting $k$ back, the result is $2 \times \min(y, z)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple comparison and multiplication. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at x.
 * Friends are at [x - y, x + y] excluding x.
 * Chef can travel to [x - z, x + z].
 * 
 * The range of friends Chef can visit is the intersection of:
 * [x - y, x + y] AND [x - z, x + z]
 * This intersection is [x - min(y, z), x + min(y, z)].
 * 
 * Within this intersection, Chef can visit all integer points except x.
 * The number of integers in [x - k, x + k] is (x + k) - (x - k) + 1 = 2k + 1.
 * Since we must exclude x, the number of friends is (2k + 1) - 1 = 2k,
 * where k = min(y, z).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // The number of friends is 2 * min(y, z)
        // because the intersection of [x-y, x+y] and [x-z, x+z]
        // is [x - min(y, z), x + min(y, z)].
        // The number of integers in this range is 2 * min(y, z) + 1.
        // Excluding the position x itself, we have 2 * min(y, z) friends.
        
        long long k = min(y, z);
        long long ans = 2 * k;
        
        cout << ans << "\n";
    }

    return 0;
}
```