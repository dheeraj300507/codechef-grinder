# [Small Palindrome (SMLPAL)](https://www.codechef.com/problems/SMLPAL)

- **Difficulty Rating**: 706
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two integers $X$ and $Y$ (where $X$ and $Y$ are both even), we need to construct the smallest possible palindrome using exactly $X$ ones and $Y$ twos.

## Intuition & Mathematical Observation
To construct the smallest palindrome:
1. **Symmetry**: Since the total number of digits is $X+Y$ (which is even), the palindrome will consist of a "first half" and its reverse as the "second half".
2. **Minimization**: To make the number as small as possible, we want the smallest digits at the most significant positions (the beginning of the string). 
3. **Construction**: 
   - We take half of the available ones ($X/2$) and half of the available twos ($Y/2$).
   - To keep the number small, we place all the ones before the twos in the first half.
   - The first half will look like: `(X/2 ones) + (Y/2 twos)`.
   - The second half is simply the reverse of the first half: `(Y/2 twos) + (X/2 ones)`.
   - Concatenating these results in the smallest possible palindrome.

**Example**: $X=4, Y=2$
- Half: $X/2 = 2$ ones, $Y/2 = 1$ two.
- First half: `112`
- Second half: `211`
- Result: `112211`

## Complexity Analysis
- **Time Complexity**: $O(X + Y)$ per test case, as we iterate to build the string based on the counts of $X$ and $Y$.
- **Space Complexity**: $O(X + Y)$ to store the resulting string before printing.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to form the smallest palindrome using X ones and Y twos.
 * Since X and Y are even, we can split them into two equal halves.
 * To minimize the number, we place all available 1s before the 2s in the first half.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;

    int half_ones = X / 2;
    int half_twos = Y / 2;

    string first_half = "";
    
    // Build the first half: 1s followed by 2s to keep the number small
    for (int i = 0; i < half_ones; ++i) {
        first_half += '1';
    }
    for (int i = 0; i < half_twos; ++i) {
        first_half += '2';
    }

    // The second half is the reverse of the first half
    string second_half = first_half;
    reverse(second_half.begin(), second_half.end());
    
    cout << first_half << second_half << endl;
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