#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - X: Fine per passenger without a ticket.
 * - P: Total number of passengers.
 * - Q: Total number of tickets.
 * - Passengers without tickets = P - Q.
 * - Total fine = (P - Q) * X.
 * 
 * Complexity:
 * - Time: O(T), where T is the number of test cases.
 * - Space: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, p, q;
        if (!(cin >> x >> p >> q)) break;
        
        // Calculate number of passengers without tickets
        long long passengers_without_tickets = p - q;
        
        // Calculate total fine
        long long total_fine = passengers_without_tickets * x;
        
        // Output the result
        cout << total_fine << "\n";
    }

    return 0;
}