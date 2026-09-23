#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial temperature: A
 * Desired temperature: B
 * Hot water available: X (increases temp by 1 per litre)
 * Cold water available: Y (decreases temp by 1 per litre)
 * 
 * If A < B:
 * We need to increase the temperature by (B - A).
 * This requires (B - A) litres of hot water.
 * We can achieve this if X >= (B - A).
 * 
 * If A > B:
 * We need to decrease the temperature by (A - B).
 * This requires (A - B) litres of cold water.
 * We can achieve this if Y >= (A - B).
 * 
 * If A == B:
 * We need 0 litres of water, which is always possible.
 */

void solve() {
    long long A, B, X, Y;
    cin >> A >> B >> X >> Y;

    if (A < B) {
        // Need to increase temperature
        long long diff = B - A;
        if (X >= diff) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else if (A > B) {
        // Need to decrease temperature
        long long diff = A - B;
        if (Y >= diff) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // A == B, already at desired temperature
        cout << "YES" << "\n";
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