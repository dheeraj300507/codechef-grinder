# [Is it a VOWEL or CONSONANT (VOWELTB)](https://www.codechef.com/problems/VOWELTB)

- **Difficulty Rating**: 840
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine whether a given single uppercase English alphabet character is a vowel or a consonant. The vowels are defined as 'A', 'E', 'I', 'O', and 'U'. Any other uppercase English letter is considered a consonant.

## Intuition & Mathematical Observation
Since the input is restricted to a single uppercase English character, we do not need complex data structures. We can simply check the input character against the set of defined vowels. If the character matches any of the five vowels, we output "Vowel"; otherwise, we output "Consonant". Using a simple conditional `if-else` statement or a `switch` case is the most efficient approach.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input character.
- **Space Complexity**: $O(1)$ — We only store a single character variable, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Is it a VOWEL or CONSONANT
 * The problem asks to identify if a given uppercase English alphabet is a vowel.
 * Vowels are defined as 'A', 'E', 'I', 'O', 'U'.
 * Time Complexity: O(1) per character
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    // Read the input character
    if (!(cin >> c)) return 0;

    // Check if the character is one of the vowels
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        cout << "Vowel" << "\n";
    } else {
        cout << "Consonant" << "\n";
    }

    return 0;
}
```