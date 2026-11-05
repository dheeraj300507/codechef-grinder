# [Farmers League (LEAGUE)](https://www.codechef.com/problems/LEAGUE)

- **Difficulty Rating**: 883
- **Solved in**: 1 attempt(s)

## Problem Summary
In a round-robin tournament with $N$ teams, every team plays every other team exactly once. A win awards 3 points, a draw awards 1 point, and a loss awards 0 points. We want to find the maximum possible difference between the points of the winner (the team with the most points) and the runner-up (the team with the second-most points).

## Intuition & Mathematical Observation
To maximize the difference between the winner and the runner-up, we assume the winner wins all their games.
1. **Winner's Points**: The winner plays $N-1$ games and wins all of them, resulting in $3 \times (N-1)$ points.
2. **Runner-up's Points**: The remaining $N-1$ teams play each other in a round-robin tournament. To maximize the gap, we need to minimize the points of the runner-up. This is achieved by distributing the points as evenly as possible among the remaining teams.
3. **Pattern Recognition**:
   - For $N=2$: Winner has 3 points, Runner-up has 0. Difference = **3**.
   - For $N=3$: Winner has 6 points, Runner-up has 3. Difference = **3**.
   - For $N=4$: Winner has 9 points, Runner-up has 3. Difference = **6**.
   - For $N=5$: Winner has 12 points, Runner-up has 6. Difference = **6**.
   - For $N=6$: Winner has 15 points, Runner-up has 6. Difference = **9**.

By observing the sequence of differences ($3, 3, 6, 6, 9, 9, \dots$), we can derive the formula:
$$\text{Difference} = 3 \times \lfloor N / 2 \rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses a simple arithmetic formula. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the difference, the winner must win all (N-1) games.
 * The remaining (N-1) teams play each other. To minimize the runner-up's 
 * points, we distribute the points among them as evenly as possible.
 * 
 * Pattern observed:
 * N=2: 3 * (2/2) = 3
 * N=3: 3 * (3/2) = 3
 * N=4: 3 * (4/2) = 6
 * N=5: 3 * (5/2) = 6
 * The formula is 3 * (N / 2) using integer division.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        // Apply the derived formula
        cout << 3 * (n / 2) << "\n";
    }
    return 0;
}
```