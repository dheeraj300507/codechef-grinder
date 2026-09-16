# [Nearest Exit (NEARESTEXIT)](https://www.codechef.com/problems/NEARESTEXIT)

- **Difficulty Rating**: 585
- **Solved in**: 1 attempt(s)

## Problem Summary
A bus has 100 seats, numbered 1 to 100. There are two exits: one at seat 1 and one at seat 100. Given a passenger's seat number $X$, we need to determine which exit is closer. If the distance to seat 1 is smaller, the passenger should go "LEFT". If the distance to seat 100 is smaller, they should go "RIGHT".

## Intuition & Mathematical Observation
To find the nearest exit, we calculate the distance to both:
*   **Distance to Exit 1 (Left):** $|X - 1| = X - 1$
*   **Distance to Exit 2 (Right):** $|X - 100| = 100 - X$

The passenger chooses the exit with the smaller distance:
1.  If $X - 1 < 100 - X$, then $2X < 101$, which simplifies to $X \le 50$. In this case, the left exit is closer.
2.  If $X - 1 > 100 - X$, then $2X > 101$, which simplifies to $X > 50$. In this case, the right exit is closer.

Thus, the logic is straightforward: if the seat number is 50 or less, output `LEFT`; otherwise, output `RIGHT`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bus has 100 seats.
 * Exit 1 is at seat 1.
 * Exit 2 is at seat 100.
 * Distance to Exit 1 = |X - 1| = X - 1
 * Distance to Exit 2 = |X - 100| = 100 - X
 * 
 * The passenger chooses the exit with the smaller distance.
 * If X - 1 < 100 - X, then 2X < 101, so X <= 50.
 * If X - 1 > 100 - X, then 2X > 101, so X > 50.
 * 
 * Therefore:
 * If X <= 50, output LEFT.
 * If X > 50, output RIGHT.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Compare distances to seat 1 and seat 100
        // Distance to seat 1 is (x - 1)
        // Distance to seat 100 is (100 - x)
        if (x <= 50) {
            cout << "LEFT" << "\n";
        } else {
            cout << "RIGHT" << "\n";
        }
    }
    
    return 0;
}
```