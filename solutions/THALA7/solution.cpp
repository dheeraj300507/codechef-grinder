#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: THALA7
 * Logic: Check if the input integer N is equal to 7.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        if (n == 7) {
            cout << "THALA" << "\n";
        } else {
            cout << "SADGE" << "\n";
        }
    }

    return 0;
}