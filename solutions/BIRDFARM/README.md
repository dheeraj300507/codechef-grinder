# [Chef and Bird farm (BIRDFARM)](https://www.codechef.com/problems/BIRDFARM)

- **Difficulty Rating**: 591
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a farm with $Z$ total bird legs. Each chicken has $X$ legs and each duck has $Y$ legs. We need to determine if the farm can consist of only chickens, only ducks, both, or neither, based on whether $Z$ is perfectly divisible by $X$ and/or $Y$.

## Intuition & Mathematical Observation
The problem asks us to check for divisibility:
1. If $Z$ is divisible by both $X$ and $Y$ ($Z \% X == 0$ and $Z \% Y == 0$), then the farm could contain either type of bird. Output: `ANY`.
2. If $Z$ is only divisible by $X$, the farm can only contain chickens. Output: `CHICKEN`.
3. If $Z$ is only divisible by $Y$, the farm can only contain ducks. Output: `DUCK`.
4. If $Z$ is not divisible by either, it is impossible to have a farm with only one type of bird given the total leg count. Output: `NONE`.

By using simple conditional (`if-else`) statements, we can evaluate these four states sequentially.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic and logical operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values and boolean flags.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X (legs per chicken), Y (legs per duck), and Z (total legs).
 * A farm can have chickens if Z is divisible by X (Z % X == 0).
 * A farm can have ducks if Z is divisible by Y (Z % Y == 0).
 * 
 * Logic:
 * - If both are divisible: ANY
 * - If only chicken is divisible: CHICKEN
 * - If only duck is divisible: DUCK
 * - If neither is divisible: NONE
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        bool can_chicken = (z % x == 0);
        bool can_duck = (z % y == 0);

        if (can_chicken && can_duck) {
            cout << "ANY" << "\n";
        } else if (can_chicken) {
            cout << "CHICKEN" << "\n";
        } else if (can_duck) {
            cout << "DUCK" << "\n";
        } else {
            cout << "NONE" << "\n";
        }
    }

    return 0;
}
```