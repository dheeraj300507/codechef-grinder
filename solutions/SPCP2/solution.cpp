#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Each plane carries 100 passengers.
 * Total planes required = ceil(N / 100.0).
 * Using integer arithmetic, ceil(N / 100) is (N + 99) / 100.
 * Let R be the required number of planes.
 * If R <= X, we need 0 new planes.
 * If R > X, we need (R - X) new planes.
 * 
 * Constraints:
 * T <= 1000, X, N <= 10^6.
 * The logic is O(1) per test case, O(T) total.
 */

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, n;
        cin >> x >> n;

        // Calculate total planes needed using integer ceiling division.
        // (n + 99) / 100 is the standard way to perform ceil(n/100)
        // for positive integers.
        long long required_planes = (n + 99) / 100;

        // Calculate how many more are needed.
        // If the airline already has enough planes, the result is 0.
        if (required_planes <= x) {
            cout << 0 << "\n";
        } else {
            cout << (required_planes - x) << "\n";
        }
    }

    return 0;
}