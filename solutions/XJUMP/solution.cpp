#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to reach stair X using moves of size Y or 1.
 * To minimize the number of moves, we should use the largest possible move (Y)
 * as many times as possible.
 * 
 * Let 'a' be the number of moves of size Y, and 'b' be the number of moves of size 1.
 * We want to minimize (a + b) such that a*Y + b*1 = X.
 * 
 * To minimize the total moves, we maximize 'a'.
 * The maximum number of times we can use move Y is floor(X / Y).
 * Let a = X / Y.
 * The remaining distance is X % Y.
 * Since we can always use moves of size 1 to cover the remainder,
 * the number of moves of size 1 will be exactly X % Y.
 * 
 * Total moves = (X / Y) + (X % Y).
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

        // Calculate the number of moves of size Y
        long long moves_y = x / y;
        
        // Calculate the remaining distance to be covered by moves of size 1
        long long moves_1 = x % y;

        // The total minimum moves is the sum of both
        long long total_moves = moves_y + moves_1;

        cout << total_moves << "\n";
    }

    return 0;
}