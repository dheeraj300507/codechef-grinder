# [Max Binary (MAX_BIN)](https://www.codechef.com/problems/MAX_BIN)

- **Difficulty Rating**: 1143
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, we are allowed to perform two types of operations:
1. **Flip**: Change a '0' to a '1' (costs 1 operation).
2. **Append**: Add a '0' to the end of the string (costs 1 operation).

The goal is to maximize the value of the binary string after performing exactly $K$ operations.

## Intuition & Mathematical Observation
To maximize the value of a binary number, we prioritize the most significant bits:
1. **Prioritize the Most Significant Bit (MSB):** If the first character of the string is '0', flipping it to '1' significantly increases the value of the number (effectively adding $2^{N-1}$). This is always the most optimal first move if $K \ge 1$.
2. **Append Zeros:** Once the MSB is '1', any remaining operations are best spent appending '0's to the end of the string. Appending a '0' effectively multiplies the current value by 2. Since we want to maximize the number, shifting the existing bits to the left (by appending zeros) is more efficient than flipping any remaining '0's to '1's at lower significance positions.

**Strategy:**
- If $S[0] == '0'$, flip it to '1' and decrement $K$.
- Append the remaining $K$ zeros to the end of the string.

## Complexity Analysis
- **Time Complexity**: $O(N + K)$, where $N$ is the length of the string and $K$ is the number of operations. We iterate through the string once and perform a string construction of length $K$.
- **Space Complexity**: $O(N + K)$ to store the resulting string.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * To maximize the value:
 * 1. The most significant bit (the leftmost bit) should be '1'. If S[0] is '0', 
 *    use 1 operation to flip it to '1'.
 * 2. Any remaining operations should be used to append '0's at the end. 
 *    Appending a '0' is equivalent to multiplying the current value by 2, 
 *    which is always better than flipping a '0' to '1' at a lower significance position.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // Step 1: If the first bit is '0', flip it to '1' using 1 operation.
    if (S[0] == '0') {
        S[0] = '1';
        K--;
    }

    // Step 2: Append K zeros at the end.
    // Each Type 1 operation adds a '0'. We have K operations left.
    string zeros(K, '0');
    cout << S << zeros << "\n";
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