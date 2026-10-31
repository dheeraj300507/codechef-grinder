# [Bakery Problem (BAKERY7)](https://www.codechef.com/problems/BAKERY7)

- **Difficulty Rating**: 284
- **Solved in**: 3 attempt(s)

## Problem Summary
You need to purchase $N$ cakes. You are presented with two pricing options:
1. **Standard Price**: Each cake costs 100 units. Total cost = $N \times 100$.
2. **Bribe Price**: You pay a fixed bribe of $K$ units, and each cake then costs 60 units. Total cost = $K + (N \times 60)$.

The goal is to determine the minimum cost required to obtain $N$ cakes.

## Intuition & Mathematical Observation
The problem is a simple comparison between two linear functions. Since we want to minimize the total expenditure, we simply need to calculate the cost for both scenarios and select the smaller value.

- **Option 1**: $C_1 = N \times 100$
- **Option 2**: $C_2 = K + (N \times 60)$

The answer is $\min(C_1, C_2)$. 

**Note on implementation**: Using `long long` is a good practice to prevent potential integer overflow, although given the constraints of typical beginner problems, standard `int` might suffice. The use of `ios_base::sync_with_stdio(false); cin.tie(NULL);` ensures that I/O operations are handled efficiently, which is a best practice for competitive programming.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$ — We only store a few variables (`n`, `k`, and the calculated costs), requiring constant extra space.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to buy N cakes.
 * Option 1: No bribe. Cost = N * 100.
 * Option 2: Bribe. Cost = K + (N * 60).
 * We want to minimize the cost: min(N * 100, K + N * 60).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    
    // Read N (number of cakes) and K (bribe amount)
    if (!(cin >> n >> k)) return 0;

    // Calculate costs for both options
    long long cost_no_bribe = n * 100;
    long long cost_with_bribe = k + (n * 60);

    // Output the minimum of the two options
    cout << min(cost_no_bribe, cost_with_bribe) << endl;

    return 0;
}
```