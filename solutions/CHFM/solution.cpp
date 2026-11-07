#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the sum of all N coins. The original mean is M = S / N.
 * If we remove a coin with value A_i, the new sum is S - A_i and the new count is N - 1.
 * We want the new mean to be equal to the original mean:
 * (S - A_i) / (N - 1) = S / N
 * 
 * Multiplying both sides by N * (N - 1):
 * N * (S - A_i) = S * (N - 1)
 * N * S - N * A_i = S * N - S
 * -N * A_i = -S
 * A_i = S / N
 * 
 * This means the value of the coin to be removed must be exactly equal to the original mean.
 * Since the mean S/N might not be an integer, we check if S is divisible by N.
 * If S % N != 0, the mean is not an integer, so no coin can equal the mean.
 * If S % N == 0, we look for the first index i such that A_i == S / N.
 * 
 * Constraints:
 * N <= 10^5, A_i <= 10^9.
 * The sum S can be up to 10^5 * 10^9 = 10^14, which fits in a 64-bit integer (long long).
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    // Check if the mean is an integer
    if (sum % N != 0) {
        cout << "Impossible" << "\n";
        return;
    }

    long long target = sum / N;
    // Find the first index i such that A[i] == target
    for (int i = 0; i < N; ++i) {
        if (A[i] == target) {
            cout << (i + 1) << "\n";
            return;
        }
    }

    cout << "Impossible" << "\n";
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