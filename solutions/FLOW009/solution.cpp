#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Problem: FLOW009 - Total Expenses
 * Logic: If quantity > 1000, total = quantity * price * 0.9
 * Otherwise, total = quantity * price
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
        double quantity, price;
        cin >> quantity >> price;

        double total;
        if (quantity > 1000) {
            total = (quantity * price) * 0.9;
        } else {
            total = quantity * price;
        }

        // Output with 6 decimal places as per sample output
        cout << fixed << setprecision(6) << total << "\n";
    }

    return 0;
}