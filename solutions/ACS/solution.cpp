#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are 10 problems total.
 * Each problem is worth either 1 or 100 points.
 * Let x be the number of problems worth 100 points.
 * Let y be the number of problems worth 1 point.
 * Total problems: x + y <= 10
 * Total score: 100*x + 1*y = P
 * 
 * From the equations:
 * y = P - 100*x
 * Substituting into the first:
 * x + (P - 100*x) <= 10
 * P - 99*x <= 10
 * P - 10 <= 99*x
 * x = P / 100 (integer division)
 * 
 * We need to check if this x satisfies the conditions:
 * 1. 0 <= x <= 10
 * 2. y = P - 100*x
 * 3. 0 <= y <= 10 - x
 * 
 * If these hold, the total problems solved is x + y.
 * Otherwise, it is impossible, so output -1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int P;
        cin >> P;

        int x = P / 100;
        int y = P % 100;

        // Check if the number of problems solved is within the limit of 10
        if (x + y <= 10) {
            cout << (x + y) << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}