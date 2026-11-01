# [Wolf Down (WOLFDOWN)](https://www.codechef.com/problems/WOLFDOWN)

- **Difficulty Rating**: 1022
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string representing a forest of length $N$, where '1' represents a wolf and '0' represents a bird. In each second, every wolf at position $x$ that has a bird at position $x+1$ will eat that bird and move to position $x+1$. This process happens simultaneously for all wolves. We need to determine how many birds remain uneaten after the process stabilizes.

## Intuition & Mathematical Observation
The problem describes a discrete simulation where wolves move to the right by consuming adjacent birds. 

1. **Simultaneous Movement**: Since the movement happens simultaneously, we must calculate all potential moves based on the current state before updating the positions.
2. **State Representation**: We can represent the forest as an array where `1` is a wolf, `0` is a bird, and `-1` represents an empty space left behind by a wolf.
3. **Termination**: A wolf can only move if there is a bird immediately to its right. Since the forest has a finite length $N$, the simulation will naturally terminate when no wolf has a bird to its right.
4. **Simulation**: Given the constraints ($N \le 100$), a direct simulation is highly efficient. We iterate through the forest, identify all valid moves, apply them, and repeat until no further moves are possible.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$. In each of the $N$ possible time steps, we iterate through the array of size $N$ to identify and apply moves. Given $N \le 100$, $N^2 = 10,000$, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the current state of the forest and the status of the birds.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A wolf at position x eats a bird at x+1 and moves to x+1.
 * Since N is small (up to 100), we can simulate the process.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // current_state[i] = 1 if wolf, 0 if bird, -1 if empty (eaten)
    vector<int> state(N);
    for (int i = 0; i < N; ++i) {
        state[i] = S[i] - '0';
    }

    // Track which birds are eaten
    vector<bool> eaten(N, false);

    // Simulation: Max N seconds is sufficient as wolves only move right.
    for (int t = 0; t < N; ++t) {
        vector<int> next_state = state;
        bool moved = false;
        
        // Identify moves
        vector<int> wolf_moves(N, -1);
        for (int i = 0; i < N - 1; ++i) {
            if (state[i] == 1 && state[i + 1] == 0) {
                wolf_moves[i] = i + 1;
                moved = true;
            }
        }

        if (!moved) break;

        // Apply moves
        for (int i = 0; i < N - 1; ++i) {
            if (wolf_moves[i] != -1) {
                eaten[wolf_moves[i]] = true;
                next_state[i] = -1; // Wolf left this spot
                next_state[wolf_moves[i]] = 1; // Wolf arrived here
            }
        }
        state = next_state;
    }

    int safe_birds = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0' && !eaten[i]) {
            safe_birds++;
        }
    }
    cout << safe_birds << "\n";
}

int main() {
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