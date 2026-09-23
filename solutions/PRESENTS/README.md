# [Presents for Cheffina (PRESENTS)](https://www.codechef.com/problems/PRESENTS)

- **Difficulty Rating**: 757
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef wants to buy $N$ gifts for Cheffina. The shop has a special offer: for every 5 gifts purchased, the customer only needs to pay for 4 (the 5th one is free). We need to calculate the minimum total cost to acquire exactly $N$ gifts.

## Intuition & Mathematical Observation
The problem follows a repeating pattern of 5 gifts. 
- In every group of 5 gifts, the cost is 4 units.
- If we have $N$ gifts, we can divide them into complete groups of 5 using integer division: `sets = N / 5`.
- The cost for these complete sets is `sets * 4`.
- Any remaining gifts that do not form a full group of 5 must be paid for individually. The number of remaining gifts is `remainder = N % 5`.
- Therefore, the total cost is calculated as:
  $$\text{Total Cost} = (N / 5) \times 4 + (N \% 5)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Logic:
 * For every 5 gifts, Chef pays for 4.
 * Number of full sets of 5 = N / 5.
 * Remaining gifts = N % 5.
 * Total cost = (N / 5) * 4 + (N % 5).
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;

    // Calculate how many groups of 5 are in N
    long long sets = n / 5;
    // Calculate the remaining gifts that don't form a full group of 5
    long long remainder = n % 5;
    
    // Total cost is 4 per set + 1 per remaining gift
    long long total_cost = (sets * 4) + remainder;
    
    cout << total_cost << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
```