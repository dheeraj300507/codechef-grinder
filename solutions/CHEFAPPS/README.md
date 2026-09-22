# [Chef and his Apps (CHEFAPPS)](https://www.codechef.com/problems/CHEFAPPS)

- **Difficulty Rating**: 702
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a phone with a total storage capacity of $S$. Currently, two apps are installed occupying $X$ and $Y$ storage respectively. Chef wants to install a new app that requires $Z$ storage. We need to determine the minimum number of existing apps (0, 1, or 2) that must be uninstalled to free up enough space for the new app.

## Intuition & Mathematical Observation
The problem can be solved by calculating the current free storage and checking if it satisfies the requirement $Z$.

1.  **Calculate Free Space**: The current free space is $S - (X + Y)$.
2.  **Case 0 (No deletion)**: If `free_space >= Z`, we don't need to delete any apps.
3.  **Case 1 (Delete one app)**: If the free space is insufficient, we check if deleting one of the existing apps provides enough space. We can delete either app $X$ or app $Y$. If `(free_space + X >= Z)` or `(free_space + Y >= Z)`, then deleting one app is sufficient.
4.  **Case 2 (Delete both apps)**: If neither of the above conditions is met, we must delete both apps to free up $X + Y$ space. Since the problem guarantees that the new app can fit if both are deleted (as $X+Y+free\_space = S \ge Z$), we simply output 2.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total storage = S
 * Occupied storage = X + Y
 * Free storage = S - (X + Y)
 * Required storage = Z
 */

void solve() {
    long long S, X, Y, Z;
    if (!(cin >> S >> X >> Y >> Z)) return;

    long long free_storage = S - (X + Y);

    // Case 0: Already enough space
    if (free_storage >= Z) {
        cout << 0 << "\n";
    } 
    // Case 1: Enough space after deleting one app (either X or Y)
    else if (free_storage + X >= Z || free_storage + Y >= Z) {
        cout << 1 << "\n";
    } 
    // Case 2: Must delete both apps
    else {
        cout << 2 << "\n";
    }
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