#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 3 bags with weights A, B, and C.
 * She must check-in 2 bags and carry 1 bag.
 * Constraints:
 * 1. Sum of checked-in bags <= D
 * 2. Weight of carried bag <= E
 * 
 * There are 3 possible scenarios for which bag is carried:
 * 1. Carry A: Check-in (B+C) <= D and A <= E
 * 2. Carry B: Check-in (A+C) <= D and B <= E
 * 3. Carry C: Check-in (A+B) <= D and C <= E
 * 
 * If any of these scenarios are true, output YES, otherwise NO.
 */

void solve() {
    int A, B, C, D, E;
    if (!(cin >> A >> B >> C >> D >> E)) return;

    bool possible = false;

    // Scenario 1: Carry A
    if ((B + C <= D) && (A <= E)) {
        possible = true;
    }
    // Scenario 2: Carry B
    else if ((A + C <= D) && (B <= E)) {
        possible = true;
    }
    // Scenario 3: Carry C
    else if ((A + B <= D) && (C <= E)) {
        possible = true;
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}