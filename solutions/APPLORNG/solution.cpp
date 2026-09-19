#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Apples and Oranges
 * Logic: Bob needs to buy at least 1kg of apples (cost A) and 1kg of oranges (cost B).
 * Total cost = A + B.
 * Bob can afford this if X >= A + B.
 * Constraints: X, A, B <= 10^5. A + B <= 2 * 10^5, which fits in a standard 32-bit integer.
 * Using long long is safe practice to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X;
    if (!(cin >> X)) return 0;
    
    long long A, B;
    cin >> A >> B;

    // Check if the total cost is less than or equal to the money Bob has
    if (X >= (A + B)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}