# [Two Trains (TWOTRAINS)](https://www.codechef.com/problems/TWOTRAINS)

- **Difficulty Rating**: 1230
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ stations in a line. Train A travels from station 1 to station $N$, taking $P_i$ time to travel between station $i$ and $i+1$. Train B follows the same path but can only depart from station $i$ once it has arrived there **and** Train A has already arrived at station $i+1$. We need to find the total time taken by Train B to reach station $N$.

## Intuition & Mathematical Observation
Let $T_A$ be the time Train A reaches the current station and $T_B$ be the time Train B reaches the current station.

1. **Train A's movement**: Train A reaches station $i+1$ at time $T_A = \sum_{j=0}^{i} P_j$.
2. **Train B's movement**: Train B reaches station $i+1$ based on its previous arrival time and Train A's arrival time at the destination station.
   - Train B can only start the segment $i \to i+1$ at time $\max(T_B, T_A)$.
   - Therefore, the new arrival time for Train B at station $i+1$ is:
     $$T_B = \max(T_B, T_A) + P_i$$
3. By iterating through the array $P$ once, we can maintain the running arrival times for both trains and calculate the final result efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of travel times exactly once.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if processed on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Train A reaches station i+1 at time T_A[i] = sum(P[0...i]).
 * Train B starts from station i at time max(arrival_time_of_B_at_i, arrival_time_of_A_at_i+1).
 * B[i] = max(B[i-1], A_arrival_at_i+1) + P[i]
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> P(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> P[i];
    }

    long long current_time_A = 0;
    long long current_time_B = 0;

    for (int i = 0; i < N - 1; ++i) {
        // Train A reaches the next station
        current_time_A += P[i];
        
        // Train B can only depart from current station if A has reached the next station
        // B's arrival at the next station is max(B's current time, A's arrival at next) + travel time
        if (current_time_B < current_time_A) {
            current_time_B = current_time_A + P[i];
        } else {
            current_time_B = current_time_B + P[i];
        }
    }

    cout << current_time_B << "\n";
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