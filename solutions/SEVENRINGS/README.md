# [7 Rings (SEVENRINGS)](https://www.codechef.com/problems/SEVENRINGS)

- **Difficulty Rating**: 568
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a phone number is valid based on the total cost of items purchased. A phone number is considered valid if it consists of exactly 5 digits and does not contain a leading zero. Given the number of items $N$ and the cost per item $X$, we need to calculate the total bill $B = N \times X$ and check if it satisfies the criteria for a 5-digit number.

## Intuition & Mathematical Observation
A 5-digit number without a leading zero must fall within the inclusive range $[10000, 99999]$. 
- Any number less than $10000$ has 4 or fewer digits.
- Any number greater than $99999$ has 6 or more digits.
- Since the problem specifies no leading zeros, the smallest possible 5-digit number is $10000$.

Given the constraints $1 \le N, X \le 1000$, the maximum possible bill is $1000 \times 1000 = 1,000,000$. This value fits comfortably within a standard 32-bit integer, though `long long` is used for safety. The logic simply requires calculating the product and verifying if it lies within the specified range.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated bill, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A valid phone number consists of exactly 5 digits with no leading zeros.
 * This means the number must be in the range [10000, 99999].
 * 
 * Given N items at cost X, the total bill is B = N * X.
 * Constraints: 1 <= N, X <= 1000.
 * Max B = 1000 * 1000 = 1,000,000.
 * Since the max value fits in a standard 32-bit integer, 'long long' is safe.
 * 
 * Logic:
 * Check if 10000 <= B <= 99999.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        long long total_bill = n * x;
        
        // A 5-digit number with no leading zeros is exactly in [10000, 99999]
        if (total_bill >= 10000 && total_bill <= 99999) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```