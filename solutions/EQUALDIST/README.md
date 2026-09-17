# [Equal Distribution (EQUALDIST)](https://www.codechef.com/problems/EQUALDIST)

- **Difficulty Rating**: 330
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has $A$ chocolates and Bob has $B$ chocolates. We need to determine if it is possible to distribute the total number of chocolates equally between Alice and Bob. In other words, can we divide the sum $(A + B)$ into two equal integer parts?

## Intuition & Mathematical Observation
To distribute the total number of chocolates equally between two people, the total sum $(A + B)$ must be an **even number**. 
- If $(A + B)$ is even, each person receives exactly $\frac{A + B}{2}$ chocolates.
- If $(A + B)$ is odd, it is impossible to divide the chocolates into two equal integer amounts without breaking them.

Therefore, the condition for a "YES" output is simply checking if `(A + B) % 2 == 0`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time addition and modulo operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A chocolates and Bob has B chocolates.
 * Total chocolates = A + B.
 * To distribute them equally between two people, the total number of chocolates
 * must be divisible by 2.
 * If (A + B) % 2 == 0, then each person gets (A + B) / 2 chocolates.
 * Since we cannot break chocolates, this is the only condition required.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= A, B <= 10^5
 * A + B will be at most 2 * 10^5, which fits comfortably in a standard 32-bit integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        // Check if the sum of chocolates is even
        if ((a + b) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```