# [Chess Match (BLITZ3_2)](https://www.codechef.com/problems/BLITZ3_2)

- **Difficulty Rating**: 998
- **Solved in**: 1 attempt(s)

## Problem Summary
In a blitz chess match, each player starts with 180 seconds. For every move made, $b$ seconds are added to the player's clock. Given the total number of moves $n$ made in the game and the remaining time $a$ and $b$ for the two players respectively, calculate the total duration of the game in seconds.

## Intuition & Mathematical Observation
1. **Initial State**: Each player starts with 180 seconds. Therefore, the total initial time available for both players combined is $180 + 180 = 360$ seconds.
2. **Time Increments**: In an "a + b" format, every move adds $b$ seconds to the clock. Since there are $n$ moves made in total throughout the game, the total time added to the clocks of both players combined is $n \times 2$ seconds (as per the problem statement where $b=2$).
3. **Total Time Available**: The total time available throughout the entire game is the sum of the initial time and the time added:
   $$\text{Total Time} = 360 + 2n$$
4. **Calculating Duration**: The duration of the game is the difference between the total time available and the time remaining on the clocks after the game ends:
   $$\text{Duration} = (\text{Total Time Available}) - (\text{Time Remaining for Player 1} + \text{Time Remaining for Player 2})$$
   $$\text{Duration} = (360 + 2n) - (a + b)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each player starts with 180 seconds (3 minutes).
 * In an "a + b" match, each move adds 'b' seconds to the clock.
 * Here, a = 180 and b = 2.
 * 
 * Total time initially available to both players = 180 + 180 = 360 seconds.
 * Total time added to both players after N turns:
 * Total moves = N.
 * Total time added = N * 2 seconds.
 * 
 * Total time available throughout the game = 360 + 2*N.
 * Total time remaining at the end = A + B.
 * 
 * The duration of the game is the total time consumed:
 * Duration = (Total time available) - (Total time remaining)
 * Duration = (360 + 2*N) - (A + B)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        // Total time available = 2 * 180 (initial) + 2 * N (increments)
        long long total_time_available = 360 + 2 * n;
        long long total_time_remaining = a + b;

        long long duration = total_time_available - total_time_remaining;

        cout << duration << "\n";
    }

    return 0;
}
```