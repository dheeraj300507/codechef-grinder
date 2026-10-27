# [Two Different Palindromes (TWODIFFPALIN)](https://www.codechef.com/problems/TWODIFFPALIN)

- **Difficulty Rating**: 1216
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $A$ zeros and $B$ ones, determine if it is possible to construct at least two distinct palindromic binary strings using exactly all the given zeros and ones.

## Intuition & Mathematical Observation
To form a palindrome, at most one character type can have an odd count. If both $A$ and $B$ are odd, it is impossible to form even a single palindrome, because a palindrome requires a single "center" element, and having two odd counts would require two centers.

Furthermore, we must consider the constraint of creating **two different** palindromes:
1. **Case: Both $A$ and $B$ are odd**: Impossible to form any palindrome. Output: `No`.
2. **Case: $A=1$ or $B=1$**: If one of the counts is 1, the placement of that single character is restricted to the center of the palindrome. This severely limits the permutations, making it impossible to form two distinct palindromes. Output: `No`.
3. **Case: Otherwise**: If at least one count is even and both are greater than 1, we have enough flexibility to arrange the bits in at least two distinct palindromic patterns (e.g., by swapping the positions of blocks of bits). Output: `Yes`.

**Logic Summary:**
- If $(A \% 2 \neq 0 \text{ and } B \% 2 \neq 0)$ OR $(A == 1 \text{ or } B == 1)$: Output `No`.
- Else: Output `Yes`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic and conditional checks.
- **Space Complexity**: $O(1)$, as we use a constant amount of extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct two different palindromic binary strings with A zeros and B ones.
 * 
 * Logic:
 * 1. If both A and B are odd, we cannot form a palindrome at all.
 * 2. If A=1 or B=1, the single character must be in the middle, 
 *    leaving no room to create a second distinct palindrome.
 * 3. Otherwise, we have enough parity and count to form at least two.
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    // Check the conditions derived from the mathematical observation
    if ((A % 2 != 0 && B % 2 != 0) || (A == 1 || B == 1)) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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