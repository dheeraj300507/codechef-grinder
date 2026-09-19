#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Dominant Army
 * Logic: An army is dominant if its size is strictly greater than the sum of the other two.
 * We check this condition for all three kingdoms (A, B, and C).
 * If any of them satisfy the condition, output YES, otherwise NO.
 */

void solve() {
    long long na, nb, nc;
    if (!(cin >> na >> nb >> nc)) return;

    // Check if A is dominant
    bool a_dominant = (na > (nb + nc));
    // Check if B is dominant
    bool b_dominant = (nb > (na + nc));
    // Check if C is dominant
    bool c_dominant = (nc > (na + nb));

    if (a_dominant || b_dominant || c_dominant) {
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