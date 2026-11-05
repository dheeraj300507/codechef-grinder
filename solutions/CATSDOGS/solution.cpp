#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Total animals: C cats, D dogs.
 * - Each dog has 4 legs, each cat has 4 legs.
 * - Dogs cannot ride on anything.
 * - Cats can ride on dogs (max 2 cats per dog).
 * - If a cat rides on a dog, its legs are not counted.
 * 
 * Constraints on L:
 * 1. Minimum legs:
 *    - All dogs must be on the ground (4 * D legs).
 *    - Cats can ride on dogs. Each dog can carry up to 2 cats.
 *    - Max cats that can be carried = 2 * D.
 *    - Cats that must be on the ground = max(0, C - 2 * D).
 *    - Min legs = (4 * D) + (max(0, C - 2 * D) * 4).
 * 
 * 2. Maximum legs:
 *    - All animals are on the ground.
 *    - Max legs = (C + D) * 4.
 * 
 * 3. Divisibility:
 *    - Since every animal has 4 legs, the total number of legs L must be divisible by 4.
 * 
 * Edge cases:
 * - C=0, D=0: L must be 0.
 * - Large values: Use long long to prevent overflow.
 */

void solve() {
    long long C, D, L;
    cin >> C >> D >> L;

    // L must be a multiple of 4
    if (L % 4 != 0) {
        cout << "no" << "\n";
        return;
    }

    // Max legs possible: all cats and dogs on the ground
    long long max_legs = (C + D) * 4;

    // Min legs possible:
    // All dogs must be on the ground.
    // Cats can ride on dogs (up to 2 per dog).
    long long cats_on_ground = max(0LL, C - 2 * D);
    long long min_legs = (D + cats_on_ground) * 4;

    if (L >= min_legs && L <= max_legs) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}