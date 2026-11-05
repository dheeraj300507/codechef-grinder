# [Covid Spread (COVSPRD)](https://www.codechef.com/problems/COVSPRD)

- **Difficulty Rating**: 1346
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the number of infected people in a population of size $N$ after $D$ days. The infection follows two distinct growth phases:
1. **Days 1 to 10**: The number of infected people doubles every day.
2. **Days 11 onwards**: The number of infected people triples every day.
The total number of infected people can never exceed the total population $N$.

## Intuition & Mathematical Observation
- **Phase 1 (Days 1–10)**: The number of infected people follows the sequence $2^D$. We must ensure that at each step, the current count does not exceed $N$.
- **Phase 2 (Days 11–D)**: Starting from the count at Day 10 ($2^{10} = 1024$), the number of infected people triples each day. Again, we must cap the value at $N$ if it exceeds the population.
- **Constraints**: Since $N$ can be up to $10^8$, we use `long long` to handle calculations safely, although the result will always fit within standard integer limits. The loop-based approach is efficient because $D$ is capped by the growth rate; even with large $D$, the value will hit $N$ very quickly (logarithmic growth), making the loop run at most $\approx 30$ times.

## Complexity Analysis
- **Time Complexity**: $O(\min(D, \log N))$, as the number of infected people reaches $N$ very quickly. In the worst case, the loop runs a small constant number of times regardless of how large $D$ is.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the current state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Day 0: 1 person infected.
 * - Days 1 to 10: Number of infected doubles each day (2^D).
 * - Days 11 onwards: Number of infected triples each day (2^10 * 3^(D-10)).
 * - The number of infected people cannot exceed the population N.
 */

void solve() {
    long long N, D;
    cin >> N >> D;

    long long infected = 1;

    if (D <= 10) {
        // For D <= 10, infected = 2^D
        for (int i = 1; i <= D; ++i) {
            infected *= 2;
            if (infected > N) {
                infected = N;
                break;
            }
        }
    } else {
        // For D > 10, first calculate for day 10
        infected = 1024; // 2^10
        if (infected > N) {
            infected = N;
        } else {
            // Then calculate for days 11 to D, tripling each day
            for (int i = 11; i <= D; ++i) {
                infected *= 3;
                if (infected > N) {
                    infected = N;
                    break;
                }
            }
        }
    }

    cout << infected << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```