#include <iostream>

using namespace std;

/**
 * Problem: TYRES
 * Logic: 
 * Chef makes maximum cars first. 
 * Remaining tyres = N % 4.
 * If remaining tyres == 2, he can make 1 bike.
 * If remaining tyres == 0, he makes 0 bikes.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        // If N % 4 is 2, it means after making max cars, 2 tyres are left.
        // These 2 tyres are used to make exactly one bike.
        if (n % 4 == 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}