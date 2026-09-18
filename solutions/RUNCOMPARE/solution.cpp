#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice is happy if Bob <= 2 * Alice.
 * Bob is happy if Alice <= 2 * Bob.
 * Both are happy if (Bob <= 2 * Alice) AND (Alice <= 2 * Bob).
 * 
 * Constraints:
 * N <= 100, T <= 1000.
 * A_i, B_i <= 10^5.
 * Since 2 * 10^5 fits in a standard 32-bit integer, 'int' is sufficient, 
 * but 'long long' is used for safety against potential overflow in intermediate calculations.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int happy_days = 0;
    for (int i = 0; i < N; ++i) {
        // Alice is happy if B[i] <= 2 * A[i]
        // Bob is happy if A[i] <= 2 * B[i]
        bool alice_happy = (B[i] <= 2 * A[i]);
        bool bob_happy = (A[i] <= 2 * B[i]);

        if (alice_happy && bob_happy) {
            happy_days++;
        }
    }
    cout << happy_days << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}