# [Chef and Gym (CGYM)](https://www.codechef.com/problems/CGYM)

- **Difficulty Rating**: 496
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to join a gym. The cost of the gym membership is $X$ and the cost of a personal trainer is $Y$. Chef has a total budget of $Z$. We need to determine the maximum number of services (gym only, or gym + trainer) Chef can afford:
- If Chef can afford both, output `2`.
- If Chef can only afford the gym, output `1`.
- If Chef cannot afford the gym, output `0`.

## Intuition & Mathematical Observation
The problem follows a simple hierarchical decision structure:
1. **Priority 1 (Both):** Check if the sum of costs ($X + Y$) is less than or equal to the budget $Z$. If true, Chef can afford both.
2. **Priority 2 (Gym only):** If the first condition fails, check if the cost of the gym ($X$) alone is less than or equal to the budget $Z$. If true, Chef can afford only the gym.
3. **Priority 3 (None):** If neither of the above conditions is met, Chef cannot afford the gym, so the answer is $0$.

Since the constraints are small ($1 \le X, Y, Z \le 100$), standard integer types are sufficient, though `long long` is used for safety.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a budget Z.
 * Gym cost = X
 * Trainer cost = Y
 * 
 * Logic:
 * 1. If (X + Y) <= Z, Chef can afford both gym and trainer. Output: 2
 * 2. Else if X <= Z, Chef can afford only the gym. Output: 1
 * 3. Else, Chef cannot afford the gym. Output: 0
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Check if both gym and trainer are affordable
        if (x + y <= z) {
            cout << "2" << "\n";
        }
        // Check if only gym is affordable
        else if (x <= z) {
            cout << "1" << "\n";
        }
        // Cannot afford gym
        else {
            cout << "0" << "\n";
        }
    }
    
    return 0;
}
```