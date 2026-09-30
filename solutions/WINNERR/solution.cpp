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