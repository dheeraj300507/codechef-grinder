# [Sasta Shark Tank (SST)](https://www.codechef.com/problems/SST)

- **Difficulty Rating**: 592
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two investment offers for a company:
1. **Offer 1**: $A$ dollars for 10% of the company.
2. **Offer 2**: $B$ dollars for 20% of the company.

We need to determine which offer results in a higher total valuation of the company. If the valuations are equal, we output "ANY".

## Intuition & Mathematical Observation
To compare the offers, we must calculate the total valuation of the company based on each offer:

*   **Valuation 1**: If 10% of the company is worth $A$, then 100% is worth $A \times \frac{100}{10} = A \times 10$.
*   **Valuation 2**: If 20% of the company is worth $B$, then 100% is worth $B \times \frac{100}{20} = B \times 5$.

By comparing $(A \times 10)$ and $(B \times 5)$, we can determine which investor provides a better deal. Since the input values for $A$ and $B$ are up to 10,000, the maximum valuation is 100,000, which fits easily within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves constant time arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated valuations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Investor 1: Offers A for 10% of the company.
 * Valuation 1 = A / 0.10 = A * 10
 * 
 * Investor 2: Offers B for 20% of the company.
 * Valuation 2 = B / 0.20 = B * 5
 * 
 * We compare (A * 10) and (B * 5).
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
        
        // Calculate valuations
        long long val1 = a * 10;
        long long val2 = b * 5;
        
        if (val1 > val2) {
            cout << "FIRST" << "\n";
        } else if (val2 > val1) {
            cout << "SECOND" << "\n";
        } else {
            cout << "ANY" << "\n";
        }
    }
    
    return 0;
}
```