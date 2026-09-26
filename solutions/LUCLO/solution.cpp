#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N clovers.
 * Exactly one is a four-leaf clover.
 * The remaining (N - 1) are three-leaf clovers.
 * Total leaves = (1 * 4) + ((N - 1) * 3)
 * Total leaves = 4 + 3N - 3
 * Total leaves = 3N + 1
 * 
 * Constraints: 1 <= N <= 10.
 * The formula 3N + 1 works for all N >= 1.
 * For N=1: 3(1) + 1 = 4. Correct.
 * For N=5: 3(5) + 1 = 16. Correct.
 * For N=10: 3(10) + 1 = 31. Correct.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // The problem description implies a single input N per run, 
    // but standard competitive programming practice often involves 
    // reading until EOF or handling a single case. 
    // Based on the prompt "The only line of input will contain a single integer N",
    // we read N once.
    if (cin >> N) {
        long long total_leaves = 3LL * N + 1;
        cout << total_leaves << "\n";
    }

    return 0;
}