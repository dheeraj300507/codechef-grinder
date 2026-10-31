#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to buy N cakes.
 * Option 1: No bribe. Cost = N * 100.
 * Option 2: Bribe. Cost = K + (N * 60).
 * We want to minimize the cost: min(N * 100, K + N * 60).
 * 
 * The previous TLE was likely due to the input stream handling or 
 * environment-specific issues with the conditional check.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    // Read N and K directly
    if (!(cin >> n >> k)) return 0;

    // Calculate costs
    long long cost_no_bribe = n * 100;
    long long cost_with_bribe = k + (n * 60);

    // Output the minimum of the two options
    cout << min(cost_no_bribe, cost_with_bribe) << endl;

    return 0;
}