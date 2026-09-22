#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks to determine the scholarship percentage based on rank R.
 * - If 1 <= R <= 50, scholarship is 100%.
 * - If 51 <= R <= 100, scholarship is 50%.
 * - If R > 100, scholarship is 0%.
 * 
 * Constraints:
 * 1 <= R <= 10^9.
 * Since R can be up to 10^9, a standard 32-bit integer (int) is sufficient, 
 * but using long long is safer practice for competitive programming.
 * Time complexity: O(1) per test case.
 * Space complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long R;
    if (!(cin >> R)) return 0;

    if (R >= 1 && R <= 50) {
        cout << 100 << "\n";
    } else if (R >= 51 && R <= 100) {
        cout << 50 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}