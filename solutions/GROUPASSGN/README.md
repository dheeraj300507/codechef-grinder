# [Group Assignment (GROUPASSGN)](https://www.codechef.com/problems/GROUPASSGN)

- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $2N$ students in a class, numbered from $1$ to $2N$. The students are paired into $N$ groups based on a specific pattern:
- Group 1: $(1, 2N)$
- Group 2: $(2, 2N - 1)$
- ...
- Group $k$: $(k, 2N - k + 1)$

Given the total number of groups $N$ and Chef's roll number $X$, we need to determine the roll number of Chef's partner.

## Intuition & Mathematical Observation
By observing the pairs, we can see that for any group $k$, the sum of the two roll numbers is always constant:
$$k + (2N - k + 1) = 2N + 1$$

If Chef's roll number is $X$, let his partner's roll number be $Y$. Based on the pattern, $X$ and $Y$ must satisfy the equation:
$$X + Y = 2N + 1$$

Rearranging this to solve for $Y$:
$$Y = 2N + 1 - X$$

Since $N$ can be up to $10^8$, the value of $2N+1$ can reach approximately $2 \times 10^8$. This fits within a standard 32-bit integer, but using `long long` is a best practice to prevent potential overflow issues in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are 2N students with roll numbers 1 to 2N.
 * The groups are formed as:
 * Group 1: (1, 2N)
 * Group 2: (2, 2N - 1)
 * ...
 * Group k: (k, 2N - k + 1)
 * ...
 * Group N: (N, N + 1)
 * 
 * Given Chef's roll number X, we need to find his partner Y.
 * From the pattern, for any roll number X, the partner Y satisfies:
 * X + Y = 2N + 1
 * Therefore, Y = 2N + 1 - X.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        // Calculate partner using the derived formula: Y = 2N + 1 - X
        long long partner = (2 * n + 1) - x;
        
        cout << partner << "\n";
    }
    
    return 0;
}
```