# [Coronavirus Spread (COVID19)](https://www.codechef.com/problems/COVID19)

- **Difficulty Rating**: 1219
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ people standing at distinct positions $X_1, X_2, \dots, X_N$ on a line. A virus spreads between two people if the distance between them is $\le 2$. This infection is transitive: if person A infects person B, and person B infects person C, then person C also becomes infected. We need to find the minimum and maximum number of people that could be infected if the virus starts with exactly one person.

## Intuition & Mathematical Observation
1. **Sorted Input**: Since the positions are given in increasing order, the people form a sequence. The condition "distance $\le 2$" only applies to adjacent people in the sorted list.
2. **Connected Components**: The problem essentially asks us to find the sizes of all "connected components" of people where each adjacent pair has a distance $\le 2$. 
3. **Simulation**: For every person $i$, we can determine the size of their specific infection group by:
   - Expanding to the right as long as $X_{j+1} - X_j \le 2$.
   - Expanding to the left as long as $X_j - X_{j-1} \le 2$.
4. **Optimization**: While the provided solution simulates the spread for every person individually, we can observe that the infection groups are simply contiguous segments of the array where the difference between consecutive elements is $\le 2$. We could calculate these segment sizes in a single pass, but the $O(N^2)$ approach is perfectly acceptable given the constraints ($N \le 10$).

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case. Given that $N$ is very small (up to 10), this is highly efficient. Even for larger $N$, this could be optimized to $O(N)$ by identifying contiguous segments.
- **Space Complexity**: $O(N)$ to store the positions of the people.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N people at positions X_1, X_2, ..., X_N.
 * The virus spreads if the distance between two people is <= 2.
 * This is a transitive property: if A infects B, and B infects C, then A infects C.
 * For each person i, we can simulate the spread by checking adjacent distances.
 * If X_{j+1} - X_j <= 2, the infection spreads from j to j+1.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    int min_infected = N;
    int max_infected = 1;

    // Try starting the infection from each person i
    for (int i = 0; i < N; ++i) {
        int current_infected = 1;
        
        // Look to the right
        for (int j = i; j < N - 1; ++j) {
            if (X[j + 1] - X[j] <= 2) {
                current_infected++;
            } else {
                break;
            }
        }
        
        // Look to the left
        for (int j = i; j > 0; --j) {
            if (X[j] - X[j - 1] <= 2) {
                current_infected++;
            } else {
                break;
            }
        }
        
        if (current_infected < min_infected) {
            min_infected = current_infected;
        }
        if (current_infected > max_infected) {
            max_infected = current_infected;
        }
    }

    cout << min_infected << " " << max_infected << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```