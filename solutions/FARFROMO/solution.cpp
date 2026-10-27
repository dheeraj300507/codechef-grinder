#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The distance of a point (x, y) from the origin (0, 0) is given by the formula:
 * Distance = sqrt(x^2 + y^2)
 * To compare distances, we can compare the squared distances (x^2 + y^2) 
 * to avoid floating point precision issues and the expensive sqrt function.
 * 
 * Let D1^2 = X1^2 + Y1^2
 * Let D2^2 = X2^2 + Y2^2
 * 
 * If D1^2 > D2^2, Alex is farther.
 * If D2^2 > D1^2, Bob is farther.
 * If D1^2 == D2^2, they are at the same distance.
 * 
 * Constraints: -1000 <= X, Y <= 1000.
 * Max squared distance = 1000^2 + 1000^2 = 2,000,000.
 * This fits well within a standard 32-bit integer, but using long long is safer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long distSqAlex = (x1 * x1) + (y1 * y1);
        long long distSqBob = (x2 * x2) + (y2 * y2);

        if (distSqAlex > distSqBob) {
            cout << "ALEX" << "\n";
        } else if (distSqBob > distSqAlex) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }

    return 0;
}