#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * The problem asks for the total capacity of N cars (5 seats each) 
 * and M cars (7 seats each).
 * Total capacity = (N * 5) + (M * 7).
 * 
 * Constraints:
 * T <= 100
 * 0 <= N, M <= 100
 * Max capacity = 1200, which fits in a standard 32-bit integer.
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n, m;
        if (cin >> n >> m) {
            // Calculate total capacity: 5 seats per N-car, 7 seats per M-car
            int total_capacity = (n * 5) + (m * 7);
            cout << total_capacity << "\n";
        }
    }

    return 0;
}