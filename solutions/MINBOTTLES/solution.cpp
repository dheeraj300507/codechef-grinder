#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * Problem Analysis:
 * We have N bottles with capacity X. We want to store the total volume of water
 * S = sum(A_i) in the minimum number of bottles.
 * Since we can transfer water freely, we simply fill bottles to capacity X one by one.
 * The number of bottles needed is ceil(S / X).
 */

void solve() {
    int N;
    long long X;
    if (!(cin >> N >> X)) return;

    long long total_water = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        total_water += a;
    }

    // Calculate ceil(total_water / X) using integer division
    // Formula: (total_water + X - 1) / X
    long long min_bottles = (total_water + X - 1) / X;

    cout << min_bottles << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}