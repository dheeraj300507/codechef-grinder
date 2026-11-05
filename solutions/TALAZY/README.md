# [Lazy Jem (TALAZY)](https://www.codechef.com/problems/TALAZY)

- **Difficulty Rating**: 1120
- **Solved in**: 1 attempt(s)

## Problem Summary
Jem has $N$ problems to solve. He solves them in batches. In each step, he solves half of the remaining problems (if $N$ is odd, he solves $(N+1)/2$). Each problem in the current batch takes $M$ minutes to solve. After completing a batch, if there are still problems remaining, he takes a break of $B$ minutes, and the time taken per problem for the next batch doubles ($M = M \times 2$). We need to calculate the total time taken to solve all $N$ problems.

## Intuition & Mathematical Observation
1. **Simulation**: Since the number of problems $N$ is halved in every iteration, the number of batches is logarithmic ($O(\log N)$). This allows us to simulate the process directly without needing a complex formula.
2. **Data Types**: The constraints for $N, B,$ and $M$ are up to $10^8$. The total time can easily exceed the capacity of a 32-bit integer, so we must use `long long` in C++ to prevent overflow.
3. **Logic Flow**:
   - Calculate `problems_to_solve` based on whether $N$ is even or odd.
   - Add `problems_to_solve * current_M` to the total time.
   - Subtract the solved problems from $N$.
   - If $N > 0$, add the break time $B$ and double the time per problem $M$.
   - Repeat until $N = 0$.

## Complexity Analysis
- **Time Complexity**: $O(\log N)$ per test case, as the number of problems is divided by approximately 2 in each iteration.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Jem has N problems.
 * In each step:
 * 1. He calculates the number of problems to solve before the next break:
 *    If N is even, solve N/2 problems.
 *    If N is odd, solve (N+1)/2 problems.
 * 2. Time taken for this batch = (problems_to_solve) * M.
 * 3. Update N = N - problems_to_solve.
 * 4. If N > 0, add break time B to total time.
 * 5. Update M = M * 2.
 * 
 * Constraints:
 * N, B, M up to 10^8.
 * Total time can exceed 2^31 - 1, so use long long.
 */

void solve() {
    long long N, B, M;
    cin >> N >> B >> M;

    long long total_time = 0;
    long long current_M = M;

    while (N > 0) {
        long long problems_to_solve;
        if (N % 2 == 0) {
            problems_to_solve = N / 2;
        } else {
            problems_to_solve = (N + 1) / 2;
        }

        total_time += (problems_to_solve * current_M);
        N -= problems_to_solve;

        if (N > 0) {
            total_time += B;
            current_M *= 2;
        }
    }

    cout << total_time << "\n";
}

int main() {
    // Fast I/O
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