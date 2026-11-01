# [Range Odd (RNGEODD)](https://www.codechef.com/problems/RNGEODD)

- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two integers $L$ and $R$, the task is to print all odd numbers in the range $[L, R]$ (inclusive) in increasing order, separated by spaces.

## Intuition & Mathematical Observation
To solve this efficiently, we avoid checking every number in the range $[L, R]$ for parity using the modulo operator. Instead, we identify the first odd number in the range and then increment by 2.

1. **Finding the Start**: 
   - If $L$ is odd, the first odd number is $L$.
   - If $L$ is even, the first odd number is $L + 1$.
   - This can be expressed as: `start = (L % 2 != 0) ? L : L + 1`.
2. **Iteration**: Starting from `start`, we iterate through the range by adding 2 in each step (`i += 2`). This ensures that every number visited is odd, effectively skipping all even numbers and reducing the number of loop iterations by half.
3. **Output Formatting**: A boolean flag `first` is used to handle the spacing requirement, ensuring no trailing space is printed after the last number.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of odd integers in the range $[L, R]$. Since we increment by 2, we perform approximately $(R - L) / 2$ operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: Range Odd
 * Optimized approach:
 * 1. Find the first odd number >= L.
 * 2. Iterate by adding 2 until R is reached.
 * This reduces the number of iterations and eliminates the modulo check.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, R;
    if (!(cin >> L >> R)) return 0;

    // If L is even, the first odd number is L + 1.
    // If L is odd, the first odd number is L.
    int start = (L % 2 != 0) ? L : L + 1;

    bool first = true;
    for (int i = start; i <= R; i += 2) {
        if (!first) {
            cout << " ";
        }
        cout << i;
        first = false;
    }
    cout << "\n";

    return 0;
}
```