#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to place these zeros such that there are at least K ones between any two zeros.
 * If we have X zeros, there are (X - 1) gaps between them.
 * Let the number of ones in each gap be g_1, g_2, ..., g_{X-1}.
 * The condition is that g_i >= K for all i = 1 to X-1.
 * The total number of ones used in these gaps is sum(g_i) = G.
 * Since we have Y ones in total, we must have G <= Y.
 * To maximize K, we want to distribute the ones as evenly as possible or simply 
 * satisfy the minimum requirement.
 * The minimum number of ones required to satisfy the condition is K * (X - 1).
 * Therefore, we need K * (X - 1) <= Y.
 * Solving for K: K <= Y / (X - 1).
 * Since K must be an integer, the largest K is floor(Y / (X - 1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // X is the number of 0s.
        // There are X-1 gaps between the X zeros.
        // We need at least K ones in each of the X-1 gaps.
        // Total ones required = K * (X - 1).
        // Condition: K * (X - 1) <= Y.
        // Largest K = Y / (X - 1).
        
        long long K = Y / (X - 1);
        cout << K << "\n";
    }

    return 0;
}