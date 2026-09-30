#include <iostream>
#include <vector>

/**
 * Problem Analysis:
 * Chef needs H hours. He has x hours.
 * He can choose one time zone T_i to gain T_i extra hours.
 * Total time available = x + T_i.
 * Condition to solve: x + T_i >= H.
 * 
 * Complexity:
 * Time: O(N) - We iterate through the N time zones once.
 * Space: O(1) - We only store the current T_i value.
 */

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, H, x;
    if (!(cin >> N >> H >> x)) return 0;

    bool possible = false;
    for (int i = 0; i < N; ++i) {
        int T;
        cin >> T;
        // Check if this specific time zone allows Chef to meet the requirement
        if (x + T >= H) {
            possible = true;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}