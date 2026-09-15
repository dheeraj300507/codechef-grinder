# [Tour of King (KNGTOR)](https://www.codechef.com/problems/KNGTOR)

- **Difficulty Rating**: 283
- **Solved in**: 2 attempt(s)

## Problem Summary
The King wants to take his people on a tour. He has $N$ cars that can seat 5 people each and $M$ cars that can seat 7 people each. The goal is to calculate the total maximum number of people that can be accommodated in all the cars combined.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. Since each of the $N$ cars holds 5 people and each of the $M$ cars holds 7 people, the total capacity is simply the sum of the products of the number of cars and their respective capacities:

$$\text{Total Capacity} = (N \times 5) + (M \times 7)$$

Given the constraints ($N, M \le 100$), the maximum possible result is $(100 \times 5) + (100 \times 7) = 1200$, which easily fits within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * The problem asks for the total capacity of N cars (5 seats each) 
 * and M cars (7 seats each).
 * Total capacity = (N * 5) + (M * 7).
 * 
 * Constraints:
 * T <= 100
 * 0 <= N, M <= 100
 * Max capacity = 1200, which fits in a standard 32-bit integer.
 */

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n, m;
        if (cin >> n >> m) {
            // Calculate total capacity: 5 seats per N-car, 7 seats per M-car
            int total_capacity = (n * 5) + (m * 7);
            cout << total_capacity << "\n";
        }
    }

    return 0;
}
```