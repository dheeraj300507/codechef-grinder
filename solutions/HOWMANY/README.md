# [HOW MANY DIGITS DO I HAVE (HOWMANY)](https://www.codechef.com/problems/HOWMANY)

- **Difficulty Rating**: 908
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine the number of digits in a given non-negative integer $N$. Specifically, we need to output:
- "1" if the number has 1 digit.
- "2" if the number has 2 digits.
- "3" if the number has 3 digits.
- "More than 3 digits" if the number has 4 or more digits.

The input $N$ is guaranteed to be between 0 and 1,000,000.

## Intuition & Mathematical Observation
While one could solve this using mathematical operations (repeated division by 10 or logarithmic functions), the simplest and most robust approach is to treat the input as a **string**.

1. **String Representation**: When we read the input as a `std::string`, the length of the string directly corresponds to the number of digits in the integer.
2. **Conditional Logic**: Once we have the length, we simply use an `if-else` block to map the length to the required output strings.
3. **Edge Cases**: Since the input is a non-negative integer, reading it as a string handles the digit count perfectly without worrying about integer overflow or complex math.

## Complexity Analysis
- **Time Complexity**: $O(D)$, where $D$ is the number of digits in the input. Since the maximum input is 1,000,000 (which has 7 digits), this is effectively $O(1)$.
- **Space Complexity**: $O(D)$, as we store the input as a string of length $D$. Given the constraints, this is effectively $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HOW MANY DIGITS DO I HAVE
 * Approach: Read the input as a string to easily determine the number of digits.
 * This approach is robust and handles the digit count logic efficiently.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    if (!(cin >> n)) return 0;

    int len = n.length();

    if (len == 1) {
        cout << "1" << "\n";
    } else if (len == 2) {
        cout << "2" << "\n";
    } else if (len == 3) {
        cout << "3" << "\n";
    } else {
        cout << "More than 3 digits" << "\n";
    }

    return 0;
}
```