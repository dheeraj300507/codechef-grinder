# [Processing a string (KOL15A)](https://www.codechef.com/problems/KOL15A)

- **Difficulty Rating**: 1125
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ containing both alphabetic characters and digits, the task is to calculate the sum of all the individual digits present in the string.

## Intuition & Mathematical Observation
The problem requires us to traverse the string and identify characters that represent numerical digits. 
1. **Character Identification**: In C++, characters are represented by their ASCII values. The digits '0' through '9' are stored contiguously in the ASCII table.
2. **Conversion**: To convert a character digit (e.g., '5') into its actual integer value (5), we can subtract the character '0' from it: `int value = c - '0'`.
3. **Summation**: We maintain a running total variable initialized to zero and add the integer value of every digit encountered during the iteration.

## Complexity Analysis
- **Time Complexity**: $O(T \times |S|)$, where $T$ is the number of test cases and $|S|$ is the length of the string. We perform a single pass over each string.
- **Space Complexity**: $O(|S|)$ to store the input string for each test case.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Processing a string (KOL15A)
 * Approach: Iterate through each character of the string. If the character is a digit
 * (checked using ASCII range '0'-'9'), convert it to its integer value by 
 * subtracting '0' and add it to a running sum.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string s;
        cin >> s;

        long long sum = 0;
        for (char c : s) {
            // Check if the character is a digit '0'-'9'
            if (c >= '0' && c <= '9') {
                sum += (c - '0');
            }
        }

        cout << sum << "\n";
    }

    return 0;
}
```