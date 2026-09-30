# [Determine the Winner (WINNERR)](https://www.codechef.com/problems/WINNERR)

- **Difficulty Rating**: 626
- **Solved in**: 1 attempt(s)

## Problem Summary
Two participants, P and Q, each solve two problems. We are given the time taken by P to solve their two problems ($P_A, P_B$) and the time taken by Q to solve their two problems ($Q_A, Q_B$). The participant who finishes both their problems earlier (i.e., has the smaller maximum time among their two problems) is declared the winner. If both finish at the same time, it is a tie.

## Intuition & Mathematical Observation
To determine the winner, we must identify the moment each participant completes their final task. Since a participant can only be considered "finished" once both of their problems are solved, the completion time for each participant is the **maximum** of the times taken for their two individual problems.

Let:
- $Penalty_P = \max(P_A, P_B)$
- $Penalty_Q = \max(Q_A, Q_B)$

By comparing these two values:
1. If $Penalty_P < Penalty_Q$, participant **P** wins.
2. If $Penalty_Q < Penalty_P$, participant **Q** wins.
3. If $Penalty_P = Penalty_Q$, it is a **TIE**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of comparisons and arithmetic operations, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the calculated penalties.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The time penalty for a participant is the time at which they have solved both problems.
 * Since they solve both problems at P_A and P_B (or Q_A and Q_B), the time they
 * finish both is the maximum of the two submission times.
 * 
 * Penalty_P = max(P_A, P_B)
 * Penalty_Q = max(Q_A, Q_B)
 * 
 * We compare Penalty_P and Penalty_Q:
 * - If Penalty_P < Penalty_Q, P wins.
 * - If Penalty_Q < Penalty_P, Q wins.
 * - If Penalty_P == Penalty_Q, it's a TIE.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int pa, pb, qa, qb;
        cin >> pa >> pb >> qa >> qb;
        
        // Calculate the time penalty for each participant
        int penalty_p = max(pa, pb);
        int penalty_q = max(qa, qb);
        
        // Compare penalties and output the result
        if (penalty_p < penalty_q) {
            cout << "P" << "\n";
        } else if (penalty_q < penalty_p) {
            cout << "Q" << "\n";
        } else {
            cout << "TIE" << "\n";
        }
    }
    
    return 0;
}
```