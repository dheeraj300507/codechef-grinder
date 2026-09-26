# [IceCream Cones (ICECONE6)](https://www.codechef.com/problems/ICECONE6)

- **Difficulty Rating**: 484
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an initial amount of ice cream $X$ grams. The ice cream melts at a rate of $Y$ grams per minute. You need to determine how much ice cream remains after $N$ minutes. If the ice cream melts completely before or at the $N$-th minute, the remaining amount is $0$.

## Intuition & Mathematical Observation
The total amount of ice cream that melts over $N$ minutes is calculated as the product of the melting rate ($Y$) and the time elapsed ($N$). 

1. **Calculate total melted**: $Melted = Y \times N$.
2. **Calculate remaining**: $Remaining = X - Melted$.
3. **Handle constraints**: Since the ice cream cannot have a negative mass, if $Remaining < 0$, we output $0$. Otherwise, we output the calculated $Remaining$ value.

Using `long long` is a good practice to prevent potential integer overflow, although given the typical constraints for a 484-rated problem, standard integers might suffice.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial amount of ice cream = X
 * Melting rate = Y grams per minute
 * Time elapsed = N minutes
 * Total melted = Y * N
 * Remaining ice cream = X - (Y * N)
 * 
 * Constraint: If the calculated remaining amount is less than 0, 
 * it means the ice cream has completely melted, so the result should be 0.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, n;
        cin >> x >> y >> n;
        
        // Calculate total melted amount
        long long melted = y * n;
        
        // Remaining amount is X - melted, but cannot be less than 0
        long long remaining = x - melted;
        
        if (remaining < 0) {
            cout << 0 << "\n";
        } else {
            cout << remaining << "\n";
        }
    }
    
    return 0;
}
```