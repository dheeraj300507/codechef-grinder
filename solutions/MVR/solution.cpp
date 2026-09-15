#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Messi's points = A * 2 + B
 * Ronaldo's points = X * 2 + Y
 * We need to compare these two values and output "Messi", "Ronaldo", or "Equal".
 * 
 * Constraints: 0 <= A, B, X, Y <= 100.
 * Max points = 100 * 2 + 100 = 300.
 * Standard 'int' is sufficient as 300 fits well within the range.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, X, Y;
    // Reading the four space-separated integers
    if (!(cin >> A >> B >> X >> Y)) return 0;

    // Calculate total points
    int messi_points = (A * 2) + B;
    int ronaldo_points = (X * 2) + Y;

    // Compare and output the result
    if (messi_points > ronaldo_points) {
        cout << "Messi" << "\n";
    } else if (ronaldo_points > messi_points) {
        cout << "Ronaldo" << "\n";
    } else {
        cout << "Equal" << "\n";
    }

    return 0;
}