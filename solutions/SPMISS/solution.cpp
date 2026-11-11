#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two types of missions:
 * 1. Normal missions (S_i = '0'): Can be completed anytime.
 * 2. Special missions (S_i = '1'): Require paying a one-time fee C.
 * 
 * To pay the fee C, we must have accumulated at least C coins from 
 * missions completed *before* paying the fee.
 * 
 * Strategy:
 * - Let 'normal_sum' be the sum of all A_i where S_i == '0'.
 * - Let 'special_sum' be the sum of all A_i where S_i == '1'.
 * - Option 1: Don't unlock special missions. Total = normal_sum.
 * - Option 2: Unlock special missions. We need to pay C.
 *   We can pay C if (sum of some subset of missions) >= C.
 *   To maximize profit, we should complete all missions.
 *   The total profit would be (normal_sum + special_sum - C).
 *   This is valid if and only if we can reach a balance of C using 
 *   a subset of missions before paying.
 *   Since we want to maximize profit, we should complete all normal missions 
 *   first. If normal_sum >= C, we can definitely unlock the special missions 
 *   and get (normal_sum + special_sum - C).
 *   If normal_sum < C, we might still be able to unlock if we complete 
 *   some special missions first, but the problem says we need to pay the fee 
 *   to access special missions. This implies we must use normal missions 
 *   to reach C. Wait, re-reading: "to access them you need to pay... 
 *   you must have at least C coins with you beforehand."
 *   This means we can only use normal missions to reach C.
 * 
 * Correct Logic:
 * 1. Calculate sum of all normal missions (S_i == '0').
 * 2. Calculate sum of all special missions (S_i == '1').
 * 3. If normal_sum >= C, we can take all missions: profit = normal_sum + special_sum - C.
 * 4. If normal_sum < C, we cannot unlock special missions. Profit = normal_sum.
 */

void solve() {
    int N;
    long long C;
    cin >> N >> C;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    string S;
    cin >> S;

    long long normal_sum = 0;
    long long special_sum = 0;
    bool has_special = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            normal_sum += A[i];
        } else {
            special_sum += A[i];
            has_special = true;
        }
    }

    if (!has_special) {
        cout << normal_sum << "\n";
    } else {
        if (normal_sum >= C) {
            cout << max(normal_sum, normal_sum + special_sum - C) << "\n";
        } else {
            cout << normal_sum << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}