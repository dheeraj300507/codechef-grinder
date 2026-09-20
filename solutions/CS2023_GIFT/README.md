# [The Gift (CS2023_GIFT)](https://www.codechef.com/problems/CS2023_GIFT)

- **Difficulty Rating**: 390
- **Solved in**: 1 attempt(s)

## Problem Summary
Om wants to buy a laptop that costs $N$ rupees. He currently has $X$ rupees in his pocket. Additionally, he has access to a Gymkhana fund which contains $M$ rupees. Om can use as much of the Gymkhana fund as he needs. We need to determine if Om can afford the laptop, i.e., if his total available money ($X + M$) is greater than or equal to the cost of the laptop ($N$).

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. 
1. Om's total purchasing power is the sum of his personal savings ($X$) and the available fund ($M$).
2. The condition to purchase the laptop is:
   $$\text{Total Money} \ge \text{Cost of Laptop}$$
   $$X + M \ge N$$
3. If this condition holds true, output "YES"; otherwise, output "NO".
4. Given the constraints ($1 \le X, N, M \le 10^3$), the maximum possible sum is $2000$, which easily fits within a standard 32-bit integer, though `long long` is used here for robust coding practices.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic and comparison operations regardless of the input size.
- **Space Complexity**: $O(1)$ — The solution uses a fixed amount of memory to store the three input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Om has X rupees.
 * Laptop costs N rupees.
 * Gymkhana fund has M rupees.
 * Om can use the fund as much as he wants.
 * Therefore, the total money Om can have is X + M.
 * Om can buy the laptop if X + M >= N.
 * 
 * Constraints: 1 <= X, N, M <= 10^3.
 * The sum X + M will be at most 2000, which fits in a standard integer.
 * Using long long is safe practice for competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, N, M;
    
    // Read the three space-separated integers
    if (cin >> X >> N >> M) {
        // Check if total money is sufficient
        if (X + M >= N) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```