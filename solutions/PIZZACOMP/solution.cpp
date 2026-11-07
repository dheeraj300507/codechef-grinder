#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Small pizza: side = 10, area = 10 * 10 = 100. Cost = A.
 * Amount per rupee for Small = 100 / A.
 * Large pizza: side = 15, area = 15 * 15 = 225. Cost = B.
 * Amount per rupee for Large = 225 / B.
 * 
 * We need to compare 100/A and 225/B.
 * To avoid floating point precision issues, we compare the cross-products:
 * 100/A > 225/B  <=>  100 * B > 225 * A
 * 100/A < 225/B  <=>  100 * B < 225 * A
 * 100/A == 225/B <=>  100 * B == 225 * A
 * 
 * Given constraints: A, B <= 400.
 * 100 * 400 = 40,000, which fits easily in a standard 32-bit integer.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long A, B;
        cin >> A >> B;

        // Calculate cross products
        long long small_val = 100 * B;
        long long large_val = 225 * A;

        if (small_val > large_val) {
            cout << "Small" << "\n";
        } else if (large_val > small_val) {
            cout << "Large" << "\n";
        } else {
            cout << "Equal" << "\n";
        }
    }

    return 0;
}