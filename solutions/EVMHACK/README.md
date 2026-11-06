# [EVM Hacking (EVMHACK)](https://www.codechef.com/problems/EVMHACK)

- **Difficulty Rating**: 1223
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is participating in an election across three cities. For each city, we are given the number of votes Chef received ($A, B, C$) and the total number of votes cast in that city ($P, Q, R$). Chef can choose to hack at most one EVM, which would result in them receiving all the votes cast in that specific city. Chef wins if their total votes are strictly greater than half of the total votes cast across all three cities ($P + Q + R$). We need to determine if it is possible for Chef to win.

## Intuition & Mathematical Observation
To win, Chef needs:
$$\text{Total Votes} > \frac{P + Q + R}{2}$$

To avoid floating-point precision issues, we can multiply both sides by 2:
$$2 \times \text{Total Votes} > P + Q + R$$

Chef has four possible scenarios:
1. **No hack:** Total votes = $A + B + C$
2. **Hack City 1:** Total votes = $P + B + C$
3. **Hack City 2:** Total votes = $A + Q + C$
4. **Hack City 3:** Total votes = $A + B + R$

We simply calculate the total votes for each scenario and check if any of them satisfy the winning condition. If at least one scenario results in a win, the answer is "YES"; otherwise, it is "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. Given $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate sums.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has votes A, B, C in three cities with total votes P, Q, R.
 * Total votes cast = P + Q + R.
 * To win, Chef needs > (P + Q + R) / 2 votes.
 * Chef can hack at most one EVM.
 * 
 * Options:
 * 1. Hack no EVM: Total votes = A + B + C
 * 2. Hack EVM 1: Total votes = P + B + C
 * 3. Hack EVM 2: Total votes = A + Q + C
 * 4. Hack EVM 3: Total votes = A + B + R
 * 
 * We check if any of these sums are strictly greater than (P + Q + R) / 2.0.
 * Using integer arithmetic: 2 * sum > (P + Q + R)
 */

void solve() {
    long long A, B, C, P, Q, R;
    if (!(cin >> A >> B >> C >> P >> Q >> R)) return;

    long long total_cast = P + Q + R;
    
    // Possible vote counts after hacking at most one EVM
    long long option0 = A + B + C;
    long long option1 = P + B + C;
    long long option2 = A + Q + C;
    long long option3 = A + B + R;

    // Condition: 2 * current_votes > total_cast
    if ((2 * option0 > total_cast) || 
        (2 * option1 > total_cast) || 
        (2 * option2 > total_cast) || 
        (2 * option3 > total_cast)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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