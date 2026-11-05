#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(i) = A_1 + A_2 + ... + A_i
 * g(i) = A_i + A_{i+1} + ... + A_N
 * B_i = f(i) + g(i) = (A_1 + ... + A_i) + (A_i + ... + A_N)
 * B_i = (A_1 + ... + A_N) + A_i
 * Let S = A_1 + A_2 + ... + A_N.
 * Then B_i = S + A_i.
 * 
 * Summing all B_i:
 * sum(B) = sum(S + A_i) = N * S + sum(A_i)
 * Since sum(A_i) = S, we have:
 * sum(B) = N * S + S = S * (N + 1)
 * Therefore, S = sum(B) / (N + 1).
 * 
 * Once S is found, A_i = B_i - S.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> B(N);
    long long sum_B = 0;
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        sum_B += B[i];
    }

    long long S = sum_B / (N + 1);
    
    for (int i = 0; i < N; ++i) {
        cout << (B[i] - S) << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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