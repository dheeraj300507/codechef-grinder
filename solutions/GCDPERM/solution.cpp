#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to find a subset of size K from {1, 2, ..., N} such that the GCD of the subset is maximized.
 * Let the GCD be 'g'. If a subset has GCD 'g', then every element in the subset must be a multiple of 'g'.
 * The multiples of 'g' in the range [1, N] are {g, 2g, 3g, ..., m*g} where m*g <= N.
 * The number of such multiples is floor(N/g).
 * For a subset of size K to have a GCD of at least 'g', we must have at least K multiples of 'g' 
 * available in the set {1, ..., N}.
 * Thus, floor(N/g) >= K.
 * To maximize 'g', we want the largest 'g' such that floor(N/g) >= K.
 * This is equivalent to g <= N/K.
 * The maximum such integer 'g' is floor(N/K).
 * 
 * Once we have the optimal 'g', we simply pick the first K multiples of 'g':
 * {g, 2g, 3g, ..., Kg}.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    // The maximum possible GCD is floor(N/K).
    // Let g = N / K.
    // The multiples of g are g, 2g, 3g, ..., Kg.
    // Since Kg <= (N/K)*K <= N, these are all <= N.
    int g = N / K;

    for (int i = 1; i <= K; ++i) {
        cout << (long long)i * g << (i == K ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}