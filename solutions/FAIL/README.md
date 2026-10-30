# [Failing Grades (FAIL)](https://www.codechef.com/problems/FAIL)

- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef takes $N$ tests. To pass, his average marks after **every** test (from the 1st test up to the $N$-th test) must be at least 40. Given the marks for each test in chronological order, determine if Chef maintains an average of at least 40 throughout the entire process.

## Intuition & Mathematical Observation
The condition states that for every test $k$ (where $1 \le k \le N$), the average must be $\ge 40$. 
If $S_k$ is the sum of marks after $k$ tests, the average is defined as $\frac{S_k}{k}$.

The condition $\frac{S_k}{k} \ge 40$ can be rewritten to avoid floating-point division by multiplying both sides by $k$:
$$S_k \ge 40 \times k$$

We iterate through the input marks, maintaining a running sum ($S_k$). At each step $k$, we check if the current sum satisfies the inequality. If at any point $S_k < 40 \times k$, the condition is violated, and we can conclude that Chef does not pass.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ marks exactly once.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the running sum and the current test mark.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs his average to be >= 40 after EACH test.
 * Let S_k be the sum of marks after k tests.
 * The average after k tests is S_k / k.
 * The condition is S_k / k >= 40 for all k from 1 to N.
 * This is equivalent to S_k >= 40 * k.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (if we process input on the fly).
 */

void solve() {
    int N;
    cin >> N;
    
    long long current_sum = 0;
    bool possible = true;
    
    for (int i = 1; i <= N; ++i) {
        int marks;
        cin >> marks;
        current_sum += marks;
        
        // Check if average >= 40
        // current_sum / i >= 40  =>  current_sum >= 40 * i
        if (current_sum < 40LL * i) {
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
    // Fast I/O
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