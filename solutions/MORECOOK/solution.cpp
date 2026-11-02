#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has C cookies. Friends have A_1, A_2, ..., A_N cookies.
 * Alice is happy if:
 * 1. There exists at least one friend with A_i < C.
 * 2. There is no friend with A_i == C.
 * 
 * We need to find the minimum extra cookies 'x' such that (C + x) satisfies the conditions.
 * Since N, C, A_i are small (up to 100), we can simply iterate x starting from 0 upwards.
 * For each x, check if (C + x) satisfies the conditions:
 * - Condition 1: Check if there is any A_i < (C + x).
 * - Condition 2: Check if there is no A_i == (C + x).
 */

void solve() {
    int N, C;
    cin >> N >> C;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int x = 0;
    while (true) {
        int current_C = C + x;
        
        // Check condition 2: No other friend has equal cookies
        bool equal_exists = false;
        for (int i = 0; i < N; ++i) {
            if (A[i] == current_C) {
                equal_exists = true;
                break;
            }
        }
        
        // Check condition 1: At least one friend has strictly less
        bool less_exists = false;
        for (int i = 0; i < N; ++i) {
            if (A[i] < current_C) {
                less_exists = true;
                break;
            }
        }
        
        if (!equal_exists && less_exists) {
            cout << x << "\n";
            return;
        }
        
        x++;
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