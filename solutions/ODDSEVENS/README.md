# [Odds and Evens (ODDSEVENS)](https://www.codechef.com/problems/ODDSEVENS)

- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob play a game where Alice chooses an integer $a$ and Bob chooses an integer $b$ (where $1 \le a, b \le 5$). They calculate the sum $S = a + b$. 
- If $S$ is **odd**, Alice wins.
- If $S$ is **even**, Bob wins.
Given $a$ and $b$, determine the winner of the game.

## Intuition & Mathematical Observation
The problem boils down to checking the parity of the sum of two integers. 
- The sum of two numbers is **odd** if one number is even and the other is odd.
- The sum of two numbers is **even** if both numbers are even or both numbers are odd.

In programming, we can determine this efficiently using the modulo operator (`%`). If `(a + b) % 2 != 0`, the sum is odd (Alice wins); otherwise, the sum is even (Bob wins).

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob play a game where they choose numbers a and b (1 <= a, b <= 5).
 * Sum = a + b.
 * If Sum is odd, Alice wins.
 * If Sum is even, Bob wins.
 * 
 * Constraints:
 * T <= 1000
 * 1 <= a, b <= 5
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 * Space complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int sum = a + b;
        
        // Check if the sum is odd or even
        if (sum % 2 != 0) {
            // Sum is odd, Alice wins
            cout << "Alice" << "\n";
        } else {
            // Sum is even, Bob wins
            cout << "Bob" << "\n";
        }
    }
    
    return 0;
}
```