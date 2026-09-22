# [Can Chef (CANCHEF)](https://www.codechef.com/problems/CANCHEF)

- **Difficulty Rating**: 471
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef needs to travel from his home to a destination and back. The distance between his home and the destination is $Y$ km. His car has a fuel efficiency of 15 km per liter, and he currently has $X$ liters of petrol. We need to determine if Chef has enough petrol to complete the round trip.

## Intuition & Mathematical Observation
1. **Total Distance**: Since the trip is a round trip (home to destination and back), the total distance to be covered is $2 \times Y$ km.
2. **Fuel Capacity**: With $X$ liters of petrol and an efficiency of 15 km/liter, the maximum distance Chef can travel is $15 \times X$ km.
3. **Condition**: Chef can complete the trip if and only if the maximum distance he can travel is greater than or equal to the total distance required:
   $$15 \times X \ge 2 \times Y$$
4. **Constraints**: With $X, Y \le 1000$, the maximum value for $15 \times X$ is $15,000$ and $2 \times Y$ is $2,000$. Both values fit well within a standard 32-bit integer, so no special overflow handling is required.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and perform the calculation.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - Car efficiency: 15 km / 1 liter
 * - Total distance to travel: 2 * Y (round trip)
 * - Petrol available: X liters
 * - Maximum distance possible: 15 * X
 * - Condition: 15 * X >= 2 * Y
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;
    
    // Total distance required is 2 * Y
    // Total distance possible is X * 15
    if (X * 15 >= 2 * Y) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations for faster execution
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