# [Elections in Chefland (ELECTIONS)](https://www.codechef.com/problems/ELECTIONS)

- **Difficulty Rating**: 1034
- **Solved in**: 1 attempt(s)

## Problem Summary
In an election with 101 citizens, three parties (A, B, and C) compete for votes. A party is declared the winner only if they secure **strictly more than 50 votes**. If no party manages to secure more than 50 votes, the result is "NOTA" (None of the Above). Given the vote counts for each party, determine the winner or if the result is NOTA.

## Intuition & Mathematical Observation
The total number of votes is fixed at 101. 
- A party needs $> 50$ votes to win.
- Since $50 + 50 = 100$, it is mathematically impossible for two different parties to both have more than 50 votes simultaneously (as the sum would exceed 101).
- Therefore, we simply need to check the condition for each party individually. If $X_A > 50$, party A wins; if $X_B > 50$, party B wins; if $X_C > 50$, party C wins. If none of these conditions are met, the output is "NOTA".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are 101 citizens. A party wins if they receive strictly more than 50 votes.
 * Since 50 * 2 = 100, and the total is 101, it is mathematically impossible for 
 * two parties to have > 50 votes simultaneously.
 * We simply check if X_A > 50, X_B > 50, or X_C > 50.
 * If none satisfy this, output NOTA.
 */

void solve() {
    long long XA, XB, XC;
    if (!(cin >> XA >> XB >> XC)) return;

    if (XA > 50) {
        cout << "A" << "\n";
    } else if (XB > 50) {
        cout << "B" << "\n";
    } else if (XC > 50) {
        cout << "C" << "\n";
    } else {
        cout << "NOTA" << "\n";
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