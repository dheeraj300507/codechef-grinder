#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef chooses one from {a, b} and one from {c, d}.
 * The total tastiness is the sum of the two chosen ingredients.
 * To maximize the sum, we pick the maximum of {a, b} and the maximum of {c, d}.
 * Max Tastiness = max(a, b) + max(c, d).
 * 
 * Constraints: 1 <= a, b, c, d <= 100.
 * The sum will not exceed 200, so 'int' is sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Calculate the maximum possible tastiness
        int max_first = max(a, b);
        int max_second = max(c, d);
        int result = max_first + max_second;

        cout << result << "\n";
    }

    return 0;
}