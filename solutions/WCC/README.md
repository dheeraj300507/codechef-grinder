# [World Chess Championship (WCC)](https://www.codechef.com/problems/WCC)

- **Difficulty Rating**: 935
- **Solved in**: 1 attempt(s)

## Problem Summary
The World Chess Championship consists of 14 games. Each game results in either a win for Carlsen ('C'), a win for Chef ('N'), or a draw ('D'). The scoring system is as follows:
- A win awards 2 points.
- A draw awards 1 point to both players.
- A loss awards 0 points.

Given the total prize pool $X$, Carlsen receives:
- $60 \times X$ if his total points are greater than Chef's.
- $55 \times X$ if the points are equal.
- $40 \times X$ if his total points are less than Chef's.

The goal is to calculate the total prize money Carlsen receives based on the sequence of 14 game results.

## Intuition & Mathematical Observation
The problem is a straightforward simulation. Since the total number of games is fixed at 14, we can iterate through the input string once to calculate the total points for both players:
1. Initialize `carlsen_points` and `chef_points` to 0.
2. For each character in the string:
   - If 'C', add 2 to `carlsen_points`.
   - If 'N', add 2 to `chef_points`.
   - If 'D', add 1 to both `carlsen_points` and `chef_points`.
3. Compare the final totals and multiply $X$ by the corresponding multiplier (60, 55, or 40).

**Note on Data Types:** Since $X$ can be up to $10^6$, the maximum prize money is $60 \times 10^6 = 6 \times 10^7$. This fits within a standard 32-bit integer, but using `long long` is good practice to prevent overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of games (fixed at 14). Since $N$ is constant, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only store a few integer variables and the input string of constant length.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - 14 games total.
 * - Carlsen (C) wins: 2 points.
 * - Chef (N) wins: 0 points for Carlsen.
 * - Draw (D): 1 point for Carlsen.
 * - Carlsen's total points = (count of 'C' * 2) + (count of 'D' * 1).
 * - Chef's total points = (count of 'N' * 2) + (count of 'D' * 1).
 */

void solve() {
    long long X;
    cin >> X;
    string s;
    cin >> s;

    int carlsen_points = 0;
    int chef_points = 0;

    for (char c : s) {
        if (c == 'C') {
            carlsen_points += 2;
        } else if (c == 'N') {
            chef_points += 2;
        } else {
            carlsen_points += 1;
            chef_points += 1;
        }
    }

    if (carlsen_points > chef_points) {
        cout << 60 * X << "\n";
    } else if (carlsen_points == chef_points) {
        cout << 55 * X << "\n";
    } else {
        cout << 40 * X << "\n";
    }
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