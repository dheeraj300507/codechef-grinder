# [Mutated Minions (CHN15A)](https://www.codechef.com/problems/CHN15A)

- **Difficulty Rating**: 777
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given $N$ minions, each with an initial characteristic value $V_i$. A mutation process adds a constant value $K$ to each minion's characteristic value. A minion is considered a "Wolverine" if its new characteristic value $(V_i + K)$ is perfectly divisible by 7. The goal is to count the total number of Wolverine minions after the mutation.

## Intuition & Mathematical Observation
The problem is a straightforward simulation. For each minion, we perform the following steps:
1. Read the initial value $V_i$.
2. Calculate the mutated value: $V_{new} = V_i + K$.
3. Check the divisibility condition: $V_{new} \pmod 7 == 0$.
4. Maintain a counter that increments whenever the condition is met.

Since the constraints are small ($N, T \le 100$), we do not need to store the values in an array; we can process each value as it is read, keeping the space complexity minimal.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of minions per test case. Given the constraints, the total number of operations is approximately $10^4$, which easily passes within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current minion's value and the running count, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Mutated Minions (CHN15A)
 * Approach:
 * For each minion with characteristic value V, the new value becomes V + K.
 * We count how many minions satisfy (V + K) % 7 == 0.
 */

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    int wolverine_count = 0;
    for (int i = 0; i < n; ++i) {
        long long v;
        cin >> v;
        
        // Check if the transmogrified value is divisible by 7
        if ((v + k) % 7 == 0) {
            wolverine_count++;
        }
    }

    cout << wolverine_count << "\n";
}

int main() {
    // Optimize standard I/O operations for faster execution
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