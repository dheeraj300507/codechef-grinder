# [Spell Splice (CMIX)](https://www.codechef.com/problems/CMIX)

- **Difficulty Rating**: 910
- **Solved in**: 3 attempt(s)

## Problem Summary
Given $N$ spells, each characterized by an attack value ($A_i$) and a vitality value ($V_i$), we need to select two distinct spells $i$ and $j$ ($i < j$) such that the combined strength, calculated as $(A_i \times V_j + V_i \times A_j)$, is maximized.

## Intuition & Mathematical Observation
The problem asks us to find the maximum value of a specific expression across all possible pairs of spells. 

1. **Constraints**: With $N \le 100$, the total number of pairs is $\frac{N(N-1)}{2}$, which is approximately 5,000. Given $T \le 100$ test cases, the total number of operations is roughly $5 \times 10^5$. This is well within the typical limit of $10^8$ operations per second.
2. **Brute Force**: Since the constraints are small, a simple nested loop that iterates through all possible pairs $(i, j)$ where $i < j$ is sufficient to find the global maximum.
3. **Implementation Details**: We store the spells in a `struct` or a pair of vectors. We initialize our `max_strength` variable to a value lower than any possible result (e.g., -1) and update it whenever a higher value is calculated. Using `long long` is recommended to prevent potential integer overflow, although given the constraints, standard integers might suffice depending on the input range.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the number of spells. For each test case, we perform a double loop over $N$ elements.
- **Space Complexity**: $O(N)$ to store the attack and vitality values for the $N$ spells.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to maximize (A_i * V_j + V_i * A_j) for 1 <= i < j <= N.
 * Constraints: N <= 100, T <= 100.
 * Complexity: O(T * N^2) is ~5 * 10^5 operations, which is well within 1s.
 */

struct Spell {
    long long v, a;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<Spell> spells(n);
    for (int i = 0; i < n; ++i) {
        cin >> spells[i].v >> spells[i].a;
    }

    // Initialize max_strength with a very small value.
    long long max_strength = -1;

    // Iterate through all pairs (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Formula: A_i * V_j + V_i * A_j
            long long current_strength = (spells[i].a * spells[j].v) + (spells[i].v * spells[j].a);
            if (current_strength > max_strength) {
                max_strength = current_strength;
            }
        }
    }

    cout << max_strength << "\n";
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