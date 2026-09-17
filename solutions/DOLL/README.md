# [Red Light, Green Light (DOLL)](https://www.codechef.com/problems/DOLL)

- **Difficulty Rating**: 984
- **Solved in**: 1 attempt(s)

## Problem Summary
In the game "Red Light, Green Light," players must stop moving when the robot turns around. The robot has a height threshold $K$. Any player with a height strictly greater than $K$ is detected by the robot and must be eliminated. Given the heights of $N$ players, we need to determine the total number of players who will be eliminated.

## Intuition & Mathematical Observation
The problem asks us to identify how many players violate the height constraint. 
- A player is safe if their height $H_i \le K$.
- A player is eliminated if their height $H_i > K$.

Since we only need to count the number of players who satisfy the condition $H_i > K$, we can iterate through the list of heights provided for each test case, compare each height to $K$, and maintain a counter. No complex data structures or sorting are required, making this a straightforward linear scan.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of players. We iterate through the input array exactly once. The total time complexity across all test cases is $O(\sum N)$.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the current player's height and the running count, rather than storing the entire array in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Gi-Hun and Ali have height K.
 * A player is in the line of sight if their height H_i > K.
 * If H_i > K, the player blocks the view and must be shot.
 * If H_i <= K, the player does not block the view.
 * We need to count how many players have H_i > K.
 * 
 * Time Complexity: O(N) per test case, O(sum of N) total.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            long long h;
            cin >> h;
            // If the player's height is strictly greater than K, 
            // they block the line of sight.
            if (h > k) {
                count++;
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}
```