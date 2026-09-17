# [Chef and Happy String (HAPPYSTR)](https://www.codechef.com/problems/HAPPYSTR)

- **Difficulty Rating**: 956
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given string $S$ is "Happy" or "Sad". A string is considered "Happy" if it contains a contiguous substring of vowels with a length strictly greater than 2 (i.e., at least 3 consecutive vowels). Otherwise, the string is "Sad".

## Intuition & Mathematical Observation
To solve this, we need to track the number of consecutive vowels as we traverse the string from left to right:
1. **Identify Vowels**: Define a helper function or a condition to check if a character is one of the five English vowels: `a, e, i, o, u`.
2. **Tracking State**: Maintain a counter (`consecutive_vowels`) that increments whenever we encounter a vowel.
3. **Reset Condition**: If we encounter a consonant, the sequence of consecutive vowels is broken, so we reset the counter to 0.
4. **Early Exit**: If the counter reaches 3 at any point during the iteration, we can immediately conclude the string is "Happy" and stop processing. If we finish the entire string without the counter reaching 3, the string is "Sad".

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the count and state, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to check if there exists a contiguous substring of vowels with length > 2.
 * This is equivalent to checking if there are 3 or more consecutive vowels in the string.
 */

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solve() {
    string s;
    cin >> s;
    
    int consecutive_vowels = 0;
    bool happy = false;
    
    for (char c : s) {
        if (isVowel(c)) {
            consecutive_vowels++;
            // If we find 3 consecutive vowels, the string is Happy
            if (consecutive_vowels > 2) {
                happy = true;
                break;
            }
        } else {
            // Reset counter if a consonant is encountered
            consecutive_vowels = 0;
        }
    }
    
    if (happy) {
        cout << "Happy" << "\n";
    } else {
        cout << "Sad" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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