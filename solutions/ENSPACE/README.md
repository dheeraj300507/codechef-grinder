# [Enough Space (ENSPACE)](https://www.codechef.com/problems/ENSPACE)

- **Difficulty Rating**: 317
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a storage device with a capacity of $N$ GB. He needs to store $X$ files of size 1 GB each and $Y$ files of size 2 GB each. We need to determine if the total storage capacity $N$ is sufficient to hold all these files.

## Intuition & Mathematical Observation
The problem asks us to compare the total available space ($N$) with the total required space. 
- Each of the $X$ files takes 1 GB, contributing $X \times 1$ to the total.
- Each of the $Y$ files takes 2 GB, contributing $Y \times 2$ to the total.

The condition for being able to store all files is:
$$\text{Total Required Space} = X + 2Y \le N$$

If this inequality holds true, we output "YES"; otherwise, we output "NO". Since the constraints are small ($N, X, Y \le 100$), a simple integer comparison is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N GB of space.
 * He has X files of 1 GB each and Y files of 2 GB each.
 * Total space required = (X * 1) + (Y * 2).
 * Chef can save the files if Total space required <= N.
 * 
 * Constraints:
 * T <= 100
 * N, X, Y <= 100
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        
        // Calculate total size required
        long long total_required = x + (2 * y);
        
        // Check if total required space is less than or equal to available space
        if (total_required <= n) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```