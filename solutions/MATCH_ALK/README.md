# [Man of the Match (MATCH_ALK)](https://www.codechef.com/problems/MATCH_ALK)

- **Difficulty Rating**: 825
- **Solved in**: 1 attempt(s)

## Problem Summary
In a cricket match involving 22 players, we are given the runs scored and wickets taken by each player. The "Man of the Match" is determined by a specific scoring system: each run is worth 1 point, and each wicket is worth 20 points. The goal is to identify the index (1-based) of the player who achieves the highest total score.

## Intuition & Mathematical Observation
The problem asks us to evaluate a simple linear function for each player:
$$\text{Total Points} = (\text{Runs}) + (\text{Wickets} \times 20)$$

Since we need to find the player with the maximum points, we can iterate through the input for all 22 players, calculate their points on the fly, and maintain a variable to store the maximum points encountered so far along with the corresponding player's index. 

- We initialize `max_points` to -1 to ensure that even a player with 0 points will update the tracker.
- We process the input sequentially, making it unnecessary to store the data in an array, which keeps our space usage minimal.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N=22$ is the number of players. Since $N$ is a constant, the complexity is effectively $O(T)$, which easily passes within the time limits.
- **Space Complexity**: $O(1)$, as we only store a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Man of the Match
 * Logic:
 * For each player, calculate points = (runs) + (wickets * 20).
 * Keep track of the maximum points found so far and the index of the player.
 * Since there are 22 players per test case and T test cases, 
 * the complexity will be O(T * 22), which is well within the time limit.
 */

void solve() {
    int max_points = -1;
    int man_of_the_match_index = -1;

    for (int i = 1; i <= 22; ++i) {
        int runs, wickets;
        cin >> runs >> wickets;
        
        int current_points = runs + (wickets * 20);
        
        if (current_points > max_points) {
            max_points = current_points;
            man_of_the_match_index = i;
        }
    }
    
    cout << man_of_the_match_index << "\n";
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