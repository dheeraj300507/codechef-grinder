# [Best of Two (DICEGAME2)](https://www.codechef.com/problems/DICEGAME2)

- **Difficulty Rating**: 789
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each roll a six-sided die three times. The score for each player is determined by the sum of their two highest rolls. We need to compare these scores and determine if Alice wins, Bob wins, or if the game results in a tie.

## Intuition & Mathematical Observation
To find the sum of the two highest numbers out of three, we don't necessarily need to sort the numbers. A more efficient mathematical approach is:
1. Calculate the total sum of all three rolls.
2. Identify the minimum roll among the three.
3. Subtract the minimum roll from the total sum.

Mathematically: 
$$\text{Score} = (\text{Roll}_1 + \text{Roll}_2 + \text{Roll}_3) - \min(\text{Roll}_1, \text{Roll}_2, \text{Roll}_3)$$

This approach works because removing the smallest value from the set of three numbers leaves exactly the two largest values remaining.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of arithmetic operations and comparisons regardless of the input values.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the rolls and calculated scores.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: DICEGAME2
 * The score is the sum of the two highest rolls.
 * Given 3 rolls, the sum of the two highest is (sum of all three) - (minimum roll).
 */

void solve() {
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    // Calculate Alice's score: sum of all three minus the minimum
    int alice_sum = a1 + a2 + a3;
    int alice_min = min({a1, a2, a3});
    int alice_score = alice_sum - alice_min;

    // Calculate Bob's score: sum of all three minus the minimum
    int bob_sum = b1 + b2 + b3;
    int bob_min = min({b1, b2, b3});
    int bob_score = bob_sum - bob_min;

    // Compare scores
    if (alice_score > bob_score) {
        cout << "Alice" << "\n";
    } else if (bob_score > alice_score) {
        cout << "Bob" << "\n";
    } else {
        cout << "Tie" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```