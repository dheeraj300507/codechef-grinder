#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We are given a 2-digit integer X (10 <= X <= 99).
 * We need to determine if the tens digit and the units digit are different.
 * 
 * Logic:
 * Tens digit = X / 10
 * Units digit = X % 10
 * If (tens != units), output "Yes", else "No".
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    int tens = X / 10;
    int units = X % 10;

    if (tens != units) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}