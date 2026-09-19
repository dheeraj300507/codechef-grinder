#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 10 airplanes.
 * Each airplane has a capacity of X.
 * Total capacity = 10 * X.
 * Number of people willing to book = Y.
 * Number of seats actually sold = min(Total capacity, Y).
 * Price per seat = Z.
 * Total earnings = min(10 * X, Y) * Z.
 * 
 * Constraints:
 * X, Y, Z <= 100.
 * Max possible earnings = 10 * 100 * 100 = 100,000.
 * This fits within a standard 32-bit integer, but using long long is safer 
 * and good practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Total capacity of all 10 airplanes
        long long total_capacity = 10 * x;
        
        // Number of people who can actually book a seat
        long long seats_sold = min(total_capacity, y);
        
        // Total earnings
        long long earnings = seats_sold * z;
        
        cout << earnings << "\n";
    }
    
    return 0;
}