# [Cars and Bikes (TYRES)](https://www.codechef.com/problems/TYRES)

- **Difficulty Rating**: 809
- **Solved in**: 3 attempt(s)

## Problem Summary
Chef has $N$ tyres. A car requires 4 tyres, and a bike requires 2 tyres. We need to determine if it is possible to manufacture at least one bike after using as many tyres as possible to manufacture cars. In other words, we need to check if there are any tyres left over after making the maximum possible number of cars, and if those leftover tyres are exactly enough to make at least one bike (i.e., 2 tyres).

## Intuition & Mathematical Observation
1. **Car Constraint**: A car consumes 4 tyres. To maximize the number of cars, we use the operation $N \pmod 4$.
2. **Remaining Tyres**: After making the maximum number of cars, the number of remaining tyres will be $N \pmod 4$.
3. **Bike Constraint**: A bike requires 2 tyres. 
    - If $N \pmod 4 = 0$, there are no tyres left (0 bikes).
    - If $N \pmod 4 = 2$, there are 2 tyres left, which is exactly enough for 1 bike.
    - Note: Since $N$ is the total number of tyres, $N \pmod 4$ can only result in 0, 1, 2, or 3. However, the problem implies we are dealing with valid tyre counts where we only care if 2 are left over.
4. **Conclusion**: The condition simplifies to checking if $N \pmod 4 == 2$. If true, output `YES`; otherwise, output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant time modulo operation for each test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: TYRES
 * Logic: 
 * Chef makes maximum cars first. 
 * Remaining tyres = N % 4.
 * If remaining tyres == 2, he can make 1 bike.
 * If remaining tyres == 0, he makes 0 bikes.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        // If N % 4 is 2, it means after making max cars, 2 tyres are left.
        // These 2 tyres are used to make exactly one bike.
        if (n % 4 == 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```