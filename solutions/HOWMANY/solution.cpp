#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HOW MANY DIGITS DO I HAVE
 * Approach: Read the input as a string to easily determine the number of digits,
 * or read as an integer and check ranges. Since the constraint is up to 1,000,000,
 * reading as a string is robust and handles the digit count logic efficiently.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    if (!(cin >> n)) return 0;

    int len = n.length();

    if (len == 1) {
        cout << "1" << "\n";
    } else if (len == 2) {
        cout << "2" << "\n";
    } else if (len == 3) {
        cout << "3" << "\n";
    } else {
        cout << "More than 3 digits" << "\n";
    }

    return 0;
}