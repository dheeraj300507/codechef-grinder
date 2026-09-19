#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at floor A with speed X. Time taken = A / X.
 * Chefina is at floor B with speed Y. Time taken = B / Y.
 * We need to compare A/X and B/Y.
 * To avoid floating point precision issues, we can compare A/X and B/Y 
 * by cross-multiplying: compare A * Y and B * X.
 * 
 * If A * Y < B * X, then A/X < B/Y (Chef is faster).
 * If A * Y > B * X, then A/X > B/Y (Chefina is faster).
 * If A * Y == B * X, then A/X == B/Y (Both reach at the same time).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, x, y;
        cin >> a >> b >> x >> y;

        // Using cross-multiplication to compare fractions A/X and B/Y
        // Time_Chef = a / x
        // Time_Chefina = b / y
        // Compare (a * y) and (b * x)
        long long time_chef_scaled = a * y;
        long long time_chefina_scaled = b * x;

        if (time_chef_scaled < time_chefina_scaled) {
            cout << "Chef" << "\n";
        } else if (time_chef_scaled > time_chefina_scaled) {
            cout << "Chefina" << "\n";
        } else {
            cout << "Both" << "\n";
        }
    }

    return 0;
}