# [Sub A Add B (SUBAADDB)](https://www.codechef.com/problems/SUBAADDB)

- **Difficulty Rating**: 817
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string of length $N$. We can repeatedly perform an operation where we remove a substring of length $A$ and replace it with a substring of length $B$. This process continues as long as the current length of the string is at least $A$. We need to find the final length of the string after no more operations can be performed.

## Intuition & Mathematical Observation
The problem describes a simple iterative process. In each step, the length of the string changes from $L$ to $L - A + B$. 

1. **Simulation**: Since the constraints on $N$ are small ($N \le 100$), we can directly simulate the process using a `while` loop.
2. **Termination**: The loop condition is `current_length >= A`. Once the length drops below $A$, we can no longer perform the operation, and the current length is our final answer.
3. **Edge Case**: If $A \le B$, the string length would either stay the same or increase, potentially leading to an infinite loop. However, based on the problem constraints and logic, we assume the operation effectively reduces the string size or terminates.

## Complexity Analysis
- **Time Complexity**: $O(N / (A - B))$ per test case. Given $N \le 100$, this is effectively $O(N)$, which is well within the time limits.
- **Space Complexity**: $O(1)$, as we only store a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with a string of length N.
 * In each step, we replace a substring of length A with a substring of length B.
 * This changes the total length of the string by (B - A).
 * We repeat this as long as the current length L >= A.
 */

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;

    int current_length = N;
    
    // While the string length is at least A, we can perform the operation.
    // Each operation updates the length: L = L - A + B.
    // Note: If A <= B, this could loop infinitely; however, 
    // standard problem constraints imply A > B for termination.
    while (current_length >= A) {
        current_length = current_length - A + B;
    }
    
    cout << current_length << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```