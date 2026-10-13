# [Dice Number (DICENUM)](https://www.codechef.com/problems/DICENUM)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each roll three six-sided dice. For each person, the three dice values are used to form a three-digit number. The goal is to form the largest possible number using the three digits rolled. We must determine if Alice wins (forms a larger number), Bob wins, or if the game results in a tie.

## Intuition & Mathematical Observation
To maximize a three-digit number formed by three given digits, the largest digit must be placed in the hundreds place, the second largest in the tens place, and the smallest in the units place.

1. **Sorting**: For any set of three digits $\{d_1, d_2, d_3\}$, sorting them in descending order (e.g., $d_{max}, d_{mid}, d_{min}$) allows us to construct the maximum number using the formula:
   $$\text{Number} = (d_{max} \times 100) + (d_{mid} \times 10) + d_{min}$$
2. **Comparison**: Once we calculate the maximum possible number for both Alice and Bob, we simply compare the two integers. If Alice's number is greater, she wins; if Bob's is greater, he wins; otherwise, it is a tie.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Sorting three elements takes constant time, and the arithmetic operations are also constant. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$. We only use a small, fixed amount of extra space to store the three dice values for each player.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the maximum number from three digits, we should sort the digits 
 * in descending order and concatenate them.
 * For example, if Alice rolls 3, 2, 5, the maximum number is 532.
 * We calculate the maximum number for both Alice and Bob and compare them.
 */

int get_max_score(int d1, int d2, int d3) {
    vector<int> dice = {d1, d2, d3};
    // Sort in descending order to form the largest possible number
    sort(dice.begin(), dice.end(), greater<int>());
    
    // Construct the number: digit1 * 100 + digit2 * 10 + digit3
    return dice[0] * 100 + dice[1] * 10 + dice[2];
}

void solve() {
    int a1, a2, a3, b1, b2, b3;
    if (!(cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3)) return;
    
    int alice_score = get_max_score(a1, a2, a3);
    int bob_score = get_max_score(b1, b2, b3);
    
    if (alice_score > bob_score) {
        cout << "Alice" << "\n";
    } else if (bob_score > alice_score) {
        cout << "Bob" << "\n";
    } else {
        cout << "Tie" << "\n";
    }
}

int main() {
    // Fast I/O setup
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