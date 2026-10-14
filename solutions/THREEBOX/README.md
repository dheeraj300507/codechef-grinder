# [Three Boxes (THREEBOX)](https://www.codechef.com/problems/THREEBOX)

- **Difficulty Rating**: 1183
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given three items with sizes $A, B,$ and $C$, and a bag with a maximum capacity $D$. We need to determine the minimum number of bags required to carry all three items, given that each bag can hold any combination of items as long as their total size does not exceed $D$.

## Intuition & Mathematical Observation
Since we want to minimize the number of bags, we should try to pack as many items as possible into each bag. Given the constraints $A \le B \le C \le D$:

1.  **Check for 1 bag**: If the sum of all items $(A + B + C)$ is less than or equal to $D$, we can fit everything into a single bag.
2.  **Check for 2 bags**: If we cannot fit everything in one bag, we check if we can fit them into two. Since $C$ is the largest item, the most efficient way to check if two bags suffice is to see if we can pair the smaller items with $C$ or with each other such that at least one bag contains two items and the other contains the remaining item. Specifically, if $(A + B \le D)$ or $(A + C \le D)$, we can group at least two items together, leaving the third in a second bag.
3.  **Default to 3 bags**: If neither of the above conditions is met, it is impossible to group any two items together, meaning each item must be placed in its own individual bag.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three boxes A, B, C and bags of size D.
 * Constraints: 1 <= A <= B <= C <= D <= 100.
 * 
 * Logic:
 * 1. If A + B + C <= D, we can fit all in 1 bag.
 * 2. If A + B + C > D, we check if we can fit at least two boxes in one bag.
 *    - If (A + B <= D) or (A + C <= D), we can use 2 bags.
 * 3. Otherwise, we need 3 bags.
 */

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (A + B + C <= D) {
        cout << 1 << "\n";
    } else if (A + B <= D || A + C <= D) {
        // We can fit at least two in one bag, leaving the third in another
        cout << 2 << "\n";
    } else {
        // Must put each in its own bag
        cout << 3 << "\n";
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