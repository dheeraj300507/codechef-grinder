# [Chef and Remissness (REMISS)](https://www.codechef.com/problems/REMISS)

- **Difficulty Rating**: 928
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the minimum and maximum possible total number of entries into a room based on the reports of two guards. Guard 1 reports seeing $A$ entries, and Guard 2 reports seeing $B$ entries. We are told that at least one guard is always awake, meaning every entry is recorded by at least one of the two guards.

## Intuition & Mathematical Observation
To find the possible range of total entries:

1.  **Minimum Entries**: Since at least one guard is always awake, the total number of entries cannot be less than the number of entries seen by the guard who was awake the most. Therefore, the minimum number of entries is $\max(A, B)$.
2.  **Maximum Entries**: The maximum number of entries occurs if the two guards never saw the same person enter. In this scenario, every entry recorded by Guard 1 is distinct from every entry recorded by Guard 2. Thus, the maximum number of entries is the sum $A + B$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Guard 1 counts A entries.
 * Guard 2 counts B entries.
 * Since at least one guard is always awake, the total number of entries 
 * must be at least the maximum of the two counts (because the guard who 
 * was awake saw at least that many).
 * The maximum possible number of entries is the sum of the two counts 
 * (assuming they never overlapped in their counting, i.e., they were 
 * awake at different times).
 * 
 * Minimum entries = max(A, B)
 * Maximum entries = A + B
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        // Calculate minimum and maximum
        long long min_entries = max(a, b);
        long long max_entries = a + b;
        
        cout << min_entries << " " << max_entries << "\n";
    }
    
    return 0;
}
```