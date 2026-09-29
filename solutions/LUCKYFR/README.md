# [Lucky Four (LUCKYFR)](https://www.codechef.com/problems/LUCKYFR)

- **Difficulty Rating**: 998
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, the task is to count the total number of occurrences of the digit '4' in its decimal representation. This process must be repeated for $T$ test cases.

## Intuition & Mathematical Observation
The most efficient way to process the digits of a number is to treat the input as a **string** rather than an integer. 
1. By reading the input as a `std::string`, we avoid the overhead of repeated modulo (`% 10`) and division (`/ 10`) operations.
2. We can simply iterate through the string character by character and increment a counter whenever the character matches `'4'`.
3. This approach handles numbers of any length (within memory limits) and is highly readable.

## Complexity Analysis
- **Time Complexity**: $O(T \times D)$, where $T$ is the number of test cases and $D$ is the number of digits in the integer. Since $D \le 10$ for the given constraints, this is effectively $O(T)$, which easily passes within the 1-second time limit.
- **Space Complexity**: $O(D)$, as we store the number as a string of length $D$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYFR - Lucky Four
 * Approach:
 * For each test case, we read the number as a string. This allows us to easily
 * iterate through each digit of the number regardless of its size.
 * We count the occurrences of the character '4' in the string.
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

        int count = 0;
        for (char c : s) {
            if (c == '4') {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}
```