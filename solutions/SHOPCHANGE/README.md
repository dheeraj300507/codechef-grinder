# [Shopping Change (SHOPCHANGE)](https://www.codechef.com/problems/SHOPCHANGE)

- **Difficulty Rating**: 526
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef goes to the market to buy items worth $X$ rupees. He pays the shopkeeper a 100-rupee note. The task is to calculate the amount of change Chef should receive back from the shopkeeper.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. Since Chef pays a fixed amount of 100 rupees and the cost of the items is $X$, the change received is simply the difference between the amount paid and the cost of the items.

Mathematically, the change can be represented as:
$$\text{Change} = 100 - X$$

Given the constraints ($1 \le X \le 100$), the result will always be a non-negative integer, representing the remaining balance.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ time using simple subtraction.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef pays 100 rupees for items worth X rupees.
 * The change to be received is 100 - X.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X <= 100
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the change: 100 - X
        int change = 100 - x;
        
        cout << change << "\n";
    }
    
    return 0;
}
```