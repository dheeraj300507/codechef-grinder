# [Clearance Sale (CLEARANCE)](https://www.codechef.com/problems/CLEARANCE)

- **Difficulty Rating**: 392
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef is participating in a clearance sale where for every 2 t-shirts he purchases, he receives 1 additional t-shirt for free. Given that Chef pays for $X$ t-shirts, we need to calculate the total number of t-shirts he will possess after the sale.

## Intuition & Mathematical Observation
The problem states that for every 2 t-shirts paid, 1 is given for free. This implies a simple ratio:
- If Chef pays for $X$ t-shirts, the number of free t-shirts he receives is $\lfloor X / 2 \rfloor$.
- The total number of t-shirts is the sum of the paid t-shirts and the free t-shirts:
  $$\text{Total} = X + \lfloor X / 2 \rfloor$$

Since the problem constraints guarantee that $X$ is an even number, $X / 2$ will always result in an integer, making the calculation straightforward.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — Only a few integer variables are used to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef pays for X t-shirts.
 * For every 2 t-shirts paid, he gets 1 free.
 * Number of free t-shirts = X / 2.
 * Total t-shirts = X + (X / 2).
 * 
 * Input Format:
 * The input contains a single integer X.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the single integer X
    if (cin >> X) {
        // Calculate total t-shirts
        // Since X is guaranteed to be even, X/2 is always an integer.
        int free_shirts = X / 2;
        int total_shirts = X + free_shirts;
        
        cout << total_shirts << endl;
    }

    return 0;
}
```