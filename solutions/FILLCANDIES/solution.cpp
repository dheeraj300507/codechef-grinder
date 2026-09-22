#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each bag has K pockets.
 * Each pocket can hold at most M candies.
 * Therefore, one bag can hold at most (K * M) candies.
 * To find the minimum number of bags needed for N candies,
 * we need to calculate ceil(N / (K * M)).
 * 
 * Using integer arithmetic, ceil(a / b) can be calculated as (a + b - 1) / b.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k, m;
        cin >> n >> k >> m;

        // Capacity of one bag
        long long capacity_per_bag = k * m;

        // Calculate minimum bags needed using integer ceiling division
        // bags = (n + capacity_per_bag - 1) / capacity_per_bag
        long long bags = (n + capacity_per_bag - 1) / capacity_per_bag;

        cout << bags << "\n";
    }

    return 0;
}