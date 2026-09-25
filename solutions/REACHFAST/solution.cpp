#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at A, Chefina is at B.
 * In one step, Chef can move at most K units.
 * The distance between them is |A - B|.
 * To minimize the number of steps, Chef should always move K units 
 * towards Chefina until the remaining distance is <= K.
 * 
 * If distance D = |A - B|, the number of steps is ceil(D / K).
 * Using integer arithmetic, ceil(D / K) can be calculated as (D + K - 1) / K.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, k;
        cin >> a >> b >> k;

        // Calculate absolute distance
        long long dist = abs(a - b);

        // If distance is 0, 0 steps are needed
        if (dist == 0) {
            cout << 0 << "\n";
        } else {
            // Calculate ceil(dist / k)
            // Using integer division: (dist + k - 1) / k
            long long steps = (dist + k - 1) / k;
            cout << steps << "\n";
        }
    }

    return 0;
}