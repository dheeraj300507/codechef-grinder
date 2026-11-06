# [Construct String (CONSTR)](https://www.codechef.com/problems/CONSTR)

- **Difficulty Rating**: 1307
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $U$ of length $N$, we are allowed to perform an operation where any character can be replaced by three identical copies of itself (e.g., 'a' becomes 'aaa'). We need to find the shortest string $S$ such that $U$ can be constructed from $S$ by repeatedly applying this operation.

## Intuition & Mathematical Observation
The core of the problem lies in understanding how the operation affects the count of consecutive identical characters.
1.  **The Operation**: Replacing one character with three increases the count of that character by 2 (1 becomes 3, 3 becomes 5, and so on).
2.  **Parity Rule**: 
    *   If we start with a single character, we can generate any odd number of consecutive identical characters ($1, 3, 5, \dots$).
    *   If we start with two identical characters, we can generate any even number of consecutive identical characters ($2, 4, 6, \dots$) by applying the operation to one of the two characters (e.g., $2 \to 1+3 = 4$).
3.  **Strategy**: We can process the string $U$ by grouping consecutive identical characters into blocks of length $L$.
    *   If $L$ is odd, the block can be reduced to a single character.
    *   If $L$ is even, the block can be reduced to two identical characters.
4.  **Conclusion**: By iterating through the string and identifying these blocks, we can construct the shortest string $S$ by appending one character if the block length is odd, and two characters if the block length is even.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We traverse the string exactly once to identify blocks of consecutive characters.
- **Space Complexity**: $O(N)$ in the worst case to store the resulting string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Any block of identical consecutive characters of length L can be reduced
 * to a single character if L is odd, or two characters if L is even.
 * This is because the operation (1 -> 3) adds 2 to the count, preserving parity.
 */

void solve() {
    int N;
    cin >> N;
    string U;
    cin >> U;

    string S = "";
    int i = 0;
    while (i < N) {
        int count = 0;
        char current = U[i];
        
        // Count the length of the current block of identical characters
        while (i < N && U[i] == current) {
            count++;
            i++;
        }
        
        // If count is odd, we need 1 char. If even, we need 2.
        if (count % 2 != 0) {
            S += current;
        } else {
            S += current;
            S += current;
        }
    }
    cout << S << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```