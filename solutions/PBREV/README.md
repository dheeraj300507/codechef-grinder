# [Problem Reviews (PBREV)](https://www.codechef.com/problems/PBREV)

- **Difficulty Rating**: 643
- **Solved in**: 1 attempt(s)

## Problem Summary
A problem is considered "good" if and only if every judge provides a score strictly greater than 4. Given $N$ scores from $N$ judges, we need to determine if the problem is "good" or not. If all scores are $> 4$, output `YES`; otherwise, output `NO`.

## Intuition & Mathematical Observation
The condition for a problem to be "good" is defined by the logical conjunction:
$$\forall S_i \in \text{Scores}, S_i > 4$$

This implies that if we encounter even a single score $S_i$ such that $S_i \le 4$, the condition is immediately violated. 
- We can iterate through the input scores one by one.
- We maintain a boolean flag `is_good` initialized to `true`.
- If we find any score $\le 4$, we set `is_good` to `false`.
- Since we only need to know if *any* score fails the condition, we can process the input in a single pass.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of judges. We iterate through the list of scores exactly once. The total time complexity across all test cases is $O(\sum N)$.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store a few variables (`n`, `score`, `is_good`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A problem is 'good' if every judge gives a score strictly greater than 4.
 * This means for all i, S_i > 4.
 * If any S_i <= 4, the problem is not 'good'.
 * 
 * Time Complexity: O(N) per test case, O(sum of N) total.
 * Space Complexity: O(1) auxiliary space.
 */

void solve() {
    int n;
    cin >> n;
    
    bool is_good = true;
    for (int i = 0; i < n; ++i) {
        int score;
        cin >> score;
        // If any score is 4 or less, the condition is violated.
        if (score <= 4) {
            is_good = false;
        }
    }
    
    if (is_good) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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