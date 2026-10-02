#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Rivalry
 * The task is to compare the final ratings of two individuals after a contest.
 * Final Rating = Initial Rating + Rating Change.
 * We use long long to prevent any potential overflow, although int is sufficient
 * given the constraints (max 3000 + 200 = 3200).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long R1, R2;
    long long D1, D2;

    // Read initial ratings
    if (!(cin >> R1 >> R2)) return 0;
    // Read rating changes
    if (!(cin >> D1 >> D2)) return 0;

    // Calculate final ratings
    long long final_dominater = R1 + D1;
    long long final_everule = R2 + D2;

    // Compare and output the winner
    if (final_dominater > final_everule) {
        cout << "Dominater" << "\n";
    } else {
        cout << "Everule" << "\n";
    }

    return 0;
}