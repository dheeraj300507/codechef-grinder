# [Recent contest problems (RECENTCONT)](https://www.codechef.com/problems/RECENTCONT)

- **Difficulty Rating**: 793
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to process a list of $N$ contest codes. We need to count how many times the code `"START38"` appears and how many times the code `"LTIME108"` appears in the given input list. We are guaranteed that the input will only contain these two specific contest codes.

## Intuition & Mathematical Observation
Since we only need to track the frequency of two distinct strings, we can solve this using a simple linear scan:
1. Initialize two integer counters, `start38_count` and `ltime108_count`, to zero.
2. Iterate through the $N$ input strings.
3. For each string, compare it against the two target strings.
4. Increment the corresponding counter when a match is found.
5. Print the final values of both counters.

This approach is optimal because we only need to look at each input string exactly once.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of contest codes. We perform a single pass through the input list, and string comparisons are constant time since the string lengths are fixed and small.
- **Space Complexity**: $O(1)$ auxiliary space. We only store two integer counters regardless of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Recent contest problems
 * Approach: Iterate through the list of contest codes and maintain two counters.
 * Time Complexity: O(N) per test case, where N is the number of problems.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        int start38_count = 0;
        int ltime108_count = 0;
        
        for (int i = 0; i < n; ++i) {
            string code;
            cin >> code;
            
            if (code == "START38") {
                start38_count++;
            } else if (code == "LTIME108") {
                ltime108_count++;
            }
        }
        
        cout << start38_count << " " << ltime108_count << "\n";
    }
    
    return 0;
}
```