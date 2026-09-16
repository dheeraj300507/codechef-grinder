#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Bone Appetit
 * The total number of treats is the sum of treats from "Bones" and "Blood".
 * Total = (N * X) + (M * Y)
 * 
 * Constraints:
 * N, M <= 100
 * X, Y <= 1000
 * Maximum possible value = (100 * 1000) + (100 * 1000) = 200,000
 * This fits comfortably within a standard 32-bit integer, but we use long long 
 * for safety and best practices in competitive programming.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    long long X, Y;

    // Reading the input as per the problem description
    if (!(cin >> N >> M)) return 0;
    if (!(cin >> X >> Y)) return 0;

    // Calculating the total treats
    long long total_treats = (N * X) + (M * Y);

    // Output the result
    cout << total_treats << "\n";

    return 0;
}