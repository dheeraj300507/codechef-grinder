#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: ADVITIYA1
 * The fest runs on the 16th, 17th, and 18th of February.
 * Given N (1 <= N <= 18), we need to check if N is 16, 17, or 18.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Check if the date is within the range [16, 18]
    if (n >= 16 && n <= 18) {
        cout << "ADVITIYA" << "\n";
    } else {
        cout << "WAITING FOR ADVITIYA" << "\n";
    }

    return 0;
}