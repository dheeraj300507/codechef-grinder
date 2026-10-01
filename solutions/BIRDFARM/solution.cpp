#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X (legs per chicken), Y (legs per duck), and Z (total legs).
 * A farm can have chickens if Z is divisible by X (Z % X == 0).
 * A farm can have ducks if Z is divisible by Y (Z % Y == 0).
 * 
 * Logic:
 * - If both are divisible: ANY
 * - If only chicken is divisible: CHICKEN
 * - If only duck is divisible: DUCK
 * - If neither is divisible: NONE
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        bool can_chicken = (z % x == 0);
        bool can_duck = (z % y == 0);

        if (can_chicken && can_duck) {
            cout << "ANY" << "\n";
        } else if (can_chicken) {
            cout << "CHICKEN" << "\n";
        } else if (can_duck) {
            cout << "DUCK" << "\n";
        } else {
            cout << "NONE" << "\n";
        }
    }

    return 0;
}