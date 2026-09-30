#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's weight = 60 kg
 * Chef's height = 130 cm
 * 
 * Condition for entry:
 * 1. Weight <= W
 * 2. Height >= H
 * 
 * Given constraints: 1 <= W, H <= 1000
 * Since the values are small, standard 'int' is sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W, H;
    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves reading until EOF
    // or handling a specific number of test cases. Given the problem description:
    // "The first and only line of input will contain two space-separated integers W and H."
    if (cin >> W >> H) {
        // Chef's stats
        int chefWeight = 60;
        int chefHeight = 130;

        // Check conditions
        if (chefWeight <= W && chefHeight >= H) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}