#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs 2 popcorns and 3 drinks.
 * Options:
 * 1. Buy everything individually: 2*X + 3*Y
 * 2. Buy 1 combo (1X + 1Y) and remaining (1X + 2Y): Z + X + 2*Y
 * 3. Buy 2 combos (2X + 2Y) and remaining (1Y): 2*Z + Y
 * 
 * Since we need 2 popcorns and 3 drinks, we can use at most 2 combos 
 * (because we only need 2 popcorns).
 * 
 * We compare these three scenarios to find the minimum cost.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    // Option 1: No combos
    long long cost1 = 2 * X + 3 * Y;
    
    // Option 2: 1 combo
    long long cost2 = Z + X + 2 * Y;
    
    // Option 3: 2 combos
    long long cost3 = 2 * Z + Y;
    
    // The minimum of these three options is the answer
    long long ans = min({cost1, cost2, cost3});
    cout << ans << endl;

    return 0;
}