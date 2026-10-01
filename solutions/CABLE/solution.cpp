#include <iostream>

using namespace std;

/**
 * Problem: CABLE
 * Logic: 
 * 1. Calculate volume of cuboid: V_cuboid = A * B * C
 * 2. Calculate volume of cube: V_cube = X * X * X
 * 3. Compare V_cuboid and V_cube and print the corresponding result.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, X;
    // Read the four integers
    if (!(cin >> A >> B >> C >> X)) return 0;

    long long vol_cuboid = (long long)A * B * C;
    long long vol_cube = (long long)X * X * X;

    if (vol_cuboid > vol_cube) {
        cout << "Cuboid" << "\n";
    } else if (vol_cube > vol_cuboid) {
        cout << "Cube" << "\n";
    } else {
        cout << "Equal" << "\n";
    }

    return 0;
}