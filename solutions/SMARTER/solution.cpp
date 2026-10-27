#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tortoise time: T_tortoise = ceil(L / V1)
 * Since V1 is an integer and L is an integer, ceil(L / V1) is equivalent to (L + V1 - 1) / V1 using integer division.
 * 
 * Hare time: If the hare waits for 'w' seconds, the hare starts at time 'w'.
 * The hare finishes at time (w + L / V2).
 * The reported time is ceil(w + L / V2).
 * 
 * Condition to win: ceil(w + L / V2) < T_tortoise
 * Let T_tortoise = T_t.
 * We need ceil(w + L / V2) <= T_t - 1.
 * 
 * Since w is an integer, ceil(w + L / V2) = w + ceil(L / V2).
 * Let T_h_base = ceil(L / V2) = (L + V2 - 1) / V2.
 * The condition becomes: w + T_h_base <= T_t - 1
 * w <= T_t - 1 - T_h_base.
 * 
 * The maximum integer w is T_t - 1 - T_h_base.
 * If this value is < 0, the hare cannot win, so output -1.
 */

void solve() {
    long long L, V1, V2;
    cin >> L >> V1 >> V2;

    // Calculate tortoise time (rounded up)
    long long t_tortoise = (L + V1 - 1) / V1;
    
    // Calculate hare base time (rounded up)
    long long t_hare_base = (L + V2 - 1) / V2;

    // We need: w + t_hare_base < t_tortoise
    // Which is: w <= t_tortoise - t_hare_base - 1
    long long max_w = t_tortoise - t_hare_base - 1;

    if (max_w < 0) {
        cout << -1 << "\n";
    } else {
        cout << max_w << "\n";
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