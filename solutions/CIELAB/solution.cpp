#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to calculate A - B and output a result that differs by exactly one digit.
 * Let the correct result be X = A - B.
 * If we change the last digit of X, we must ensure:
 * 1. The number of digits remains the same.
 * 2. The result is positive.
 * 3. The result is not 0 (though the problem implies A > B, so X >= 1).
 * 
 * A simple strategy:
 * Calculate X = A - B.
 * If X % 10 == 9, change the last digit to 8 (X - 1).
 * Otherwise, change the last digit to X + 1.
 * This ensures the number of digits remains the same and the result is different.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (!(cin >> a >> b)) return 0;

    int diff = a - b;

    // We need to change exactly one digit.
    // If we add 1 to the last digit, we must ensure we don't cause a carry
    // that changes the number of digits (e.g., 9 -> 10).
    // If the last digit is 9, subtracting 1 is safer.
    if (diff % 10 == 9) {
        diff -= 1;
    } else {
        diff += 1;
    }

    cout << diff << "\n";

    return 0;
}