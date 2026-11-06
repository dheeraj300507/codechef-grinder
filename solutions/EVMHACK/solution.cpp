#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has votes A, B, C in three cities with total votes P, Q, R.
 * Total votes cast = P + Q + R.
 * To win, Chef needs > (P + Q + R) / 2 votes.
 * Chef can hack at most one EVM.
 * 
 * Options:
 * 1. Hack no EVM: Total votes = A + B + C
 * 2. Hack EVM 1: Total votes = P + B + C
 * 3. Hack EVM 2: Total votes = A + Q + C
 * 4. Hack EVM 3: Total votes = A + B + R
 * 
 * We check if any of these sums are strictly greater than (P + Q + R) / 2.0.
 * Using floating point comparison: sum > (P + Q + R) / 2.0
 * Or using integer arithmetic: 2 * sum > (P + Q + R)
 */

void solve() {
    long long A, B, C, P, Q, R;
    if (!(cin >> A >> B >> C >> P >> Q >> R)) return;

    long long total_cast = P + Q + R;
    
    // Possible vote counts after hacking at most one EVM
    long long option0 = A + B + C;
    long long option1 = P + B + C;
    long long option2 = A + Q + C;
    long long option3 = A + B + R;

    // Condition: 2 * current_votes > total_cast
    if ((2 * option0 > total_cast) || 
        (2 * option1 > total_cast) || 
        (2 * option2 > total_cast) || 
        (2 * option3 > total_cast)) {
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