# [Water Mixing (WTRMIXING)](https://www.codechef.com/problems/WTRMIXING)

- **Difficulty Rating**: 694
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an initial temperature $A$ and a target temperature $B$. We have $X$ liters of hot water (each liter increases the temperature by 1) and $Y$ liters of cold water (each liter decreases the temperature by 1). We need to determine if it is possible to reach exactly temperature $B$ using the available water.

## Intuition & Mathematical Observation
The problem boils down to calculating the difference between the current temperature and the target temperature:

1.  **Case 1: $A < B$**
    *   We need to increase the temperature by $diff = B - A$.
    *   This is only possible if we have enough hot water, i.e., $X \ge diff$.
2.  **Case 2: $A > B$**
    *   We need to decrease the temperature by $diff = A - B$.
    *   This is only possible if we have enough cold water, i.e., $Y \ge diff$.
3.  **Case 3: $A = B$**
    *   The temperature is already correct, so the answer is always "YES".

Since we only need to reach the target temperature exactly, we do not need to worry about using both hot and cold water simultaneously, as that would be counter-productive.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial temperature: A
 * Desired temperature: B
 * Hot water available: X (increases temp by 1 per litre)
 * Cold water available: Y (decreases temp by 1 per litre)
 */

void solve() {
    long long A, B, X, Y;
    cin >> A >> B >> X >> Y;

    if (A < B) {
        // Need to increase temperature
        long long diff = B - A;
        if (X >= diff) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else if (A > B) {
        // Need to decrease temperature
        long long diff = A - B;
        if (Y >= diff) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // A == B, already at desired temperature
        cout << "YES" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```