#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 5 weekdays. For each day i, he has A_i hours of work to do at the office.
 * 1 hour of office work = P hours of work at home.
 * Total work required at home for the week = (A1 + A2 + A3 + A4 + A5) * P.
 * There are 5 weekdays, and each day has 24 hours.
 * Total available hours in 5 weekdays = 5 * 24 = 120 hours.
 * 
 * If the total work required at home exceeds 120 hours, Chef must work on the weekend.
 * Otherwise, he can complete the work within the 5 weekdays.
 * 
 * Constraints:
 * A_i <= 24, P <= 24.
 * Max total work = (24 * 5) * 24 = 120 * 24 = 2880.
 * This fits comfortably within a standard integer, but using long long is safe.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a1, a2, a3, a4, a5, p;
        cin >> a1 >> a2 >> a3 >> a4 >> a5 >> p;
        
        long long total_work_hours = (a1 + a2 + a3 + a4 + a5) * p;
        long long total_available_hours = 5 * 24;
        
        // If total work required is greater than available hours, he must work on weekends.
        if (total_work_hours > total_available_hours) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}