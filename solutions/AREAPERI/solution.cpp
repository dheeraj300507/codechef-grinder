#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Area OR Perimeter
 * Logic:
 * Area = L * B
 * Perimeter = 2 * (L + B)
 * Compare Area and Perimeter and output accordingly.
 * Constraints: L, B <= 1000. Area and Perimeter will fit in standard int,
 * but using long long is safe practice for competitive programming.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, B;
    
    // The problem description implies reading L and B.
    // Based on standard CodeChef patterns for this specific problem, 
    // it reads L and B directly.
    if (!(cin >> L >> B)) return 0;

    long long area = L * B;
    long long peri = 2 * (L + B);

    if (area > peri) {
        cout << "Area" << "\n";
        cout << area << "\n";
    } else if (peri > area) {
        cout << "Peri" << "\n";
        cout << peri << "\n";
    } else {
        // If equal, print "Eq" and the value (either area or peri)
        cout << "Eq" << "\n";
        cout << area << "\n";
    }

    return 0;
}