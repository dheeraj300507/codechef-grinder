#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given n distinct integers a1, a2, ..., an.
 * We need to find the number of pairs (i, j) such that 1 <= i, j <= n, i != j, and ai < aj.
 * 
 * Since all elements are distinct, for any two distinct indices i and j, 
 * either ai < aj or aj < ai.
 * The total number of pairs (i, j) with i != j is n * (n - 1).
 * Because exactly one of the two conditions (ai < aj) or (aj < ai) must hold for any pair {i, j},
 * the number of pairs where ai < aj is exactly half of the total number of pairs with i != j.
 * 
 * Number of pairs = (n * (n - 1)) / 2.
 * 
 * Constraints:
 * n <= 100,000.
 * n * (n - 1) / 2 can be up to ~5 * 10^9, which exceeds the range of a 32-bit integer.
 * We must use long long to store the result.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Read the array elements. 
        // Note: Since all elements are distinct, the actual values don't affect the count,
        // only the fact that there are n distinct elements matters.
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // The number of pairs (i, j) such that i != j and ai < aj is nC2.
        // nC2 = n * (n - 1) / 2
        long long result = (n * (n - 1)) / 2;
        
        cout << result << "\n";
    }

    return 0;
}