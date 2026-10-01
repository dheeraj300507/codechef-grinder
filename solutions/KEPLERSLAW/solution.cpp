#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Kepler's Law
 * Kepler's 3rd Law states: T^2 / R^3 = constant
 * We need to check if (T1^2 / R1^3) == (T2^2 / R2^3)
 * To avoid floating point precision issues, we can cross-multiply:
 * T1^2 * R2^3 == T2^2 * R1^3
 * 
 * Constraints are small (up to 10), so standard integer types are sufficient.
 * Using long long to be safe against any potential overflow, though not strictly 
 * necessary given the constraints (10^2 * 10^3 = 10^5).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long t1, t2, r1, r2;
        cin >> t1 >> t2 >> r1 >> r2;
        
        // Calculate T1^2 * R2^3 and T2^2 * R1^3
        long long lhs = (t1 * t1) * (r2 * r2 * r2);
        long long rhs = (t2 * t2) * (r1 * r1 * r1);
        
        if (lhs == rhs) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}