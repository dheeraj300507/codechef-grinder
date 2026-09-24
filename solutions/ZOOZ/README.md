# [Zero Ones Equal One Zeros (ZOOZ)](https://www.codechef.com/problems/ZOOZ)

- **Difficulty Rating**: 1009
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a binary string of length $N$ such that the number of "01" subsequences is exactly equal to the number of "10" subsequences.

## Intuition & Mathematical Observation
To ensure the number of "01" subsequences equals the number of "10" subsequences, we can leverage symmetry. 

Consider a string that starts with a `1` and ends with a `1`, with all characters in between being `0`s.
For example, if $N=4$, the string is `1001`.
- **"01" subsequences**: The `0` at index 1 forms a pair with the `1` at index 3. The `0` at index 2 also forms a pair with the `1` at index 3. Total = 2.
- **"10" subsequences**: The `1` at index 0 forms a pair with the `0` at index 1. The `1` at index 0 also forms a pair with the `0` at index 2. Total = 2.

By placing `1`s at both ends, we create a balanced structure where every `0` in the middle contributes equally to the count of "01" and "10" subsequences relative to the outer `1`s. This construction `1` + `(N-2)` zeros + `1` satisfies the condition for any $N \ge 3$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate to build a string of length $N$.
- **Space Complexity**: $O(N)$ to store the resulting string before printing.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a binary string of length N such that the number of "01" subsequences 
 * equals the number of "10" subsequences.
 * 
 * A simple construction: 1 followed by (N-2) zeros followed by 1.
 * Example N=4: 1001
 * 01 subsequences: (index 1,3), (index 2,3) -> 2
 * 10 subsequences: (index 0,1), (index 0,2) -> 2
 * This works for any N >= 3.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Construct the string: '1' + (n-2) '0's + '1'
        // This ensures the number of 01 and 10 subsequences are equal.
        string result = "1";
        for (int i = 0; i < n - 2; ++i) {
            result += '0';
        }
        result += '1';
        
        cout << result << "\n";
    }
    
    return 0;
}
```