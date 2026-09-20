# [Too many Floors (FLOORS)](https://www.codechef.com/problems/FLOORS)

- **Difficulty Rating**: 717
- **Solved in**: 1 attempt(s)

## Problem Summary
In a building, each floor contains exactly 10 rooms. Specifically:
- Floor 1 contains rooms 1–10.
- Floor 2 contains rooms 11–20.
- Floor $i$ contains rooms $10(i-1) + 1$ to $10i$.

Given two room numbers $X$ and $Y$, calculate the absolute difference between the floor numbers where these rooms are located.

## Intuition & Mathematical Observation
To determine the floor number for any given room $N$, we can use integer division. Since there are 10 rooms per floor:
- Rooms 1–10 result in 0 when using `(N-1) / 10`.
- Rooms 11–20 result in 1 when using `(N-1) / 10`.
- By adding 1 to this result, we map the room numbers to their respective 1-based floor indices:
  $$\text{Floor}(N) = \lfloor \frac{N - 1}{10} \rfloor + 1$$

Once we have the floor numbers for both $X$ and $Y$ (let's call them `floor_x` and `floor_y`), the number of floors to travel is simply the absolute difference:
$$\text{Result} = | \text{floor\_x} - \text{floor\_y} |$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations for each input, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the room and floor numbers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each floor has 10 rooms.
 * Floor 1: 1-10
 * Floor 2: 11-20
 * ...
 * Floor i: 10*(i-1) + 1 to 10*i
 * 
 * To find the floor number for a room X:
 * Floor(X) = (X - 1) / 10 + 1
 * 
 * The number of floors to travel is the absolute difference between the floor numbers.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y;
        cin >> x >> y;

        // Calculate floor numbers
        // Using integer division: (x-1)/10 gives 0 for 1-10, 1 for 11-20, etc.
        // Adding 1 shifts it to 1-based floor indexing.
        int floor_x = (x - 1) / 10 + 1;
        int floor_y = (y - 1) / 10 + 1;

        // The number of floors to travel is the absolute difference
        int result = abs(floor_x - floor_y);

        cout << result << "\n";
    }

    return 0;
}
```