#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Investor 1: Offers A for 10% of the company.
 * Valuation 1 = A / 0.10 = A * 10
 * 
 * Investor 2: Offers B for 20% of the company.
 * Valuation 2 = B / 0.20 = B * 5
 * 
 * We need to compare (A * 10) and (B * 5).
 * Since A and B are up to 10,000, the valuations will be up to 100,000.
 * This fits comfortably within a standard 32-bit integer, but we use 
 * long long to be safe and follow best practices.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        // Calculate valuations
        long long val1 = a * 10;
        long long val2 = b * 5;
        
        if (val1 > val2) {
            cout << "FIRST" << "\n";
        } else if (val2 > val1) {
            cout << "SECOND" << "\n";
        } else {
            cout << "ANY" << "\n";
        }
    }
    
    return 0;
}