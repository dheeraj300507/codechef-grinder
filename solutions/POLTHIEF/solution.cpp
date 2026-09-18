#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Policeman is at X with speed 2.
 * Thief is at Y with speed 1.
 * Let t be the time taken to catch the thief.
 * The policeman's position at time t will be X + 2t (if moving right) or X - 2t (if moving left).
 * The thief's position at time t will be Y + t (if moving right) or Y - t (if moving left).
 * 
 * To catch the thief, the policeman must reach the same position as the thief.
 * The relative speed of the policeman with respect to the thief is |2 - 1| = 1 unit per second.
 * The distance between them is |X - Y|.
 * Time taken = Distance / Relative Speed = |X - Y| / 1 = |X - Y|.
 * 
 * Since the policeman is faster (speed 2 > speed 1), he will always be able to catch the thief.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The time taken is simply the absolute difference between their positions
        // because the policeman's relative speed to the thief is 1 unit/sec.
        long long time_taken = abs(x - y);
        
        cout << time_taken << "\n";
    }

    return 0;
}