# [Car or Bike (TRAVELFAST)](https://www.codechef.com/problems/TRAVELFAST)

- **Difficulty Rating**: 571
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to reach his destination. He can either take a bike or a car. You are given the time taken by the bike ($X$) and the time taken by the car ($Y$). You need to determine which vehicle is faster. If the bike is faster, output "BIKE". If the car is faster, output "CAR". If both take the same amount of time, output "SAME".

## Intuition & Mathematical Observation
The problem is a straightforward comparison task:
1. If $X < Y$, the bike takes less time, so it is faster.
2. If $Y < X$, the car takes less time, so it is faster.
3. If $X = Y$, both vehicles take the same amount of time.

Since the constraints are very small ($1 \le X, Y \le 10$), a simple `if-else` conditional structure is sufficient to handle the logic for each test case.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant number of operations for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not use any auxiliary data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers X (time for BIKE) and Y (time for CAR).
 * We need to compare X and Y:
 * - If X < Y, BIKE is faster.
 * - If Y < X, CAR is faster.
 * - If X == Y, they take the same time.
 * 
 * Constraints: 1 <= X, Y <= 10.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        if (x < y) {
            cout << "BIKE" << "\n";
        } else if (y < x) {
            cout << "CAR" << "\n";
        } else {
            cout << "SAME" << "\n";
        }
    }
    
    return 0;
}
```