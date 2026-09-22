#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Gross Salary
 * Logic:
 * If basic salary < 1500:
 *   HRA = 0.10 * basic
 *   DA = 0.90 * basic
 *   Gross = basic + 0.10 * basic + 0.90 * basic = 2.0 * basic
 * 
 * If basic salary >= 1500:
 *   HRA = 500
 *   DA = 0.98 * basic
 *   Gross = basic + 500 + 0.98 * basic = 1.98 * basic + 500
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        double salary;
        cin >> salary;

        double gross;
        if (salary < 1500) {
            gross = salary + (0.10 * salary) + (0.90 * salary);
        } else {
            gross = salary + 500 + (0.98 * salary);
        }

        // Set precision to 2 decimal places as per sample output requirements
        cout << fixed << setprecision(2) << gross << "\n";
    }

    return 0;
}