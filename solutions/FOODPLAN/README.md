# [Online or Offline (FOODPLAN)](https://www.codechef.com/problems/FOODPLAN)

- **Difficulty Rating**: 713
- **Solved in**: 2 attempt(s)

## Problem Summary
The goal is to determine the cheapest way to order food. You are given two prices:
1. **$N$**: The original price of food when ordering online. A 10% discount is applied to this price.
2. **$M$**: The price of food when dining at the restaurant.

You must output "ONLINE" if the discounted online price is strictly less than the dining price, "DINING" if the dining price is strictly less, and "EITHER" if both prices are equal.

## Intuition & Mathematical Observation
The discounted online price is calculated as:
$$\text{Online Price} = N - (0.10 \times N) = 0.9 \times N$$

To compare $0.9 \times N$ with $M$ without dealing with floating-point precision errors (which can lead to incorrect results), we can multiply both sides of the inequality by 10:
- Compare $(9 \times N)$ with $(10 \times M)$.

This transformation allows us to use integer arithmetic, which is both faster and safer. Given the constraints $N, M \le 1000$, the maximum value will be $10,000$, which easily fits within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs and calculated values.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Online cost after 10% discount = N - (0.1 * N) = 0.9 * N
 * We need to compare 0.9 * N with M.
 * To avoid floating point precision issues, multiply both sides by 10:
 * Compare (9 * N) with (10 * M).
 * 
 * Constraints: N, M <= 1000.
 * 9 * 1000 = 9000, which fits in a standard 32-bit integer.
 */

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // Compare 0.9 * N vs M by comparing 9 * N vs 10 * M
    int online_scaled = 9 * n;
    int dining_scaled = 10 * m;

    if (online_scaled < dining_scaled) {
        cout << "ONLINE" << "\n";
    } else if (online_scaled > dining_scaled) {
        cout << "DINING" << "\n";
    } else {
        cout << "EITHER" << "\n";
    }
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