# [Double Strings (DOUBLE)](https://www.codechef.com/problems/DOUBLE)

- **Difficulty Rating**: 1134
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to find the length of the longest "double string" that can be formed given a length $N$. A double string is defined as a string of length $L = 2k$ where the first half is identical to the second half. Essentially, we need to find the largest even integer less than or equal to $N$.

## Intuition & Mathematical Observation
A double string of length $L$ requires every character to appear an even number of times (specifically, each character in the first half must be mirrored in the second half). 

- If $N$ is **even**, the entire length $N$ can form a double string (e.g., if $N=4$, we can have "abab").
- If $N$ is **odd**, we cannot use all $N$ characters because at least one character would have an odd frequency. By removing exactly one character, we are left with $N-1$, which is even and satisfies the condition.

Mathematically, the largest even integer less than or equal to $N$ can be calculated using integer division: `(N / 2) * 2`. This effectively truncates any odd remainder.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are performing a simple arithmetic operation, the time taken does not scale with the magnitude of $N$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * A "double string" of length L = 2k requires the first half to equal the second half.
 * This implies every character used must appear an even number of times.
 * 
 * The formula (N / 2) * 2 correctly computes the largest even integer <= N.
 */

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            long long n;
            cin >> n;
            
            // The maximal length is the largest even number <= N
            // This is equivalent to n - (n % 2)
            cout << (n / 2) * 2 << "\n";
        }
    }
    return 0;
}
```