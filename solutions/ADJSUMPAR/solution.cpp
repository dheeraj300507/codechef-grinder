#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given B_i = (A_i + A_{i+1}) % 2 for 1 <= i < N
 * and B_N = (A_N + A_1) % 2.
 * 
 * Let's consider the sum of all elements in B:
 * Sum(B) = (A_1 + A_2) + (A_2 + A_3) + ... + (A_{N-1} + A_N) + (A_N + A_1) (mod 2)
 * Sum(B) = 2 * (A_1 + A_2 + ... + A_N) (mod 2)
 * 
 * Since 2 * (anything) is always even, the sum of all elements in B must be 0 (mod 2).
 * That is, the number of 1s in array B must be even.
 * 
 * If the number of 1s in B is even, we can always construct A.
 * Proof sketch:
 * Pick A_1 = 0.
 * Then A_2 = (B_1 - A_1) % 2
 * A_3 = (B_2 - A_2) % 2
 * ...
 * A_N = (B_{N-1} - A_{N-1}) % 2
 * The condition B_N = (A_N + A_1) % 2 will be satisfied if and only if 
 * the sum of B is even.
 */

void solve() {
    int N;
    cin >> N;
    int ones_count = 0;
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        if (b == 1) {
            ones_count++;
        }
    }

    if (ones_count % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}