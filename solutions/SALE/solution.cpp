#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef buys 3 items with prices A, B, and C.
 * The offer states that the cheapest item among the three is free.
 * Total cost = (A + B + C) - min(A, B, C).
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= A, B, C <= 10
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

void solve() {
    int a, b, c;
    if (!(cin >> a >> b >> c)) return;

    // Calculate the sum of all three items
    int total_sum = a + b + c;
    
    // Find the minimum of the three items
    int min_price = min({a, b, c});
    
    // The amount to pay is the total sum minus the cheapest item
    cout << (total_sum - min_price) << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}