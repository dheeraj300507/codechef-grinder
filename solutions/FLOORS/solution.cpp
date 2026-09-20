#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each floor has 10 rooms.
 * Floor 1: 1-10
 * Floor 2: 11-20
 * ...
 * Floor i: 10*(i-1) + 1 to 10*i
 * 
 * To find the floor number for a room X:
 * Floor(X) = (X - 1) / 10 + 1
 * 
 * The number of floors to travel is the absolute difference between the floor numbers.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y;
        cin >> x >> y;

        // Calculate floor numbers
        // Using integer division: (x-1)/10 gives 0 for 1-10, 1 for 11-20, etc.
        // Adding 1 shifts it to 1-based floor indexing.
        int floor_x = (x - 1) / 10 + 1;
        int floor_y = (y - 1) / 10 + 1;

        // The number of floors to travel is the absolute difference
        int result = abs(floor_x - floor_y);

        cout << result << "\n";
    }

    return 0;
}