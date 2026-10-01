#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Devendra has Z total money and has already spent Y.
 * Remaining money = Z - Y.
 * He needs to spend A + B + C on sports.
 * Condition: (Z - Y) >= (A + B + C).
 * 
 * Constraints:
 * Z, Y, A, B, C fit within standard integer types (max 10^5).
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

void solve() {
    int Z, Y, A, B, C;
    if (!(cin >> Z >> Y >> A >> B >> C)) return;

    int remaining = Z - Y;
    int total_cost = A + B + C;

    if (remaining >= total_cost) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }

    return 0;
}