# [Codechef Round (CODECHEF)](https://www.codechef.com/problems/CODECHEF)

- **Difficulty Rating**: 232
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given day of the week corresponds to a "Codechef Round." We are given an integer $N$ representing the day of the week (where 1 is Sunday, 2 is Monday, ..., 7 is Saturday). We are told that Codechef rounds are held exclusively on **Wednesday**, which corresponds to the integer **4**. We must output "YES" if $N = 4$ and "NO" otherwise.

## Intuition & Mathematical Observation
The problem maps days of the week to integers from 1 to 7. Since the condition for a Codechef round is fixed to Wednesday, and Wednesday is explicitly defined as the 4th day in the sequence, the logic simplifies to a basic equality check:
- If $N = 4$, the condition is satisfied.
- For any other value of $N$ ($1, 2, 3, 5, 6, 7$), the condition is not satisfied.

This is a constant-time operation requiring no complex data structures or algorithms.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and output operation, which takes constant time regardless of the input.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that Codechef rounds are held only on Wednesday.
 * The input N represents the day of the week:
 * 1: Sunday, 2: Monday, 3: Tuesday, 4: Wednesday, 5: Thursday, 6: Friday, 7: Saturday
 * 
 * Therefore, we output "YES" if N == 4, and "NO" otherwise.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the input day
    if (!(cin >> n)) return 0;

    // Check if the day is Wednesday (4)
    if (n == 4) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```