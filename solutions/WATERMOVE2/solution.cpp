#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cups with amounts A_i.
 * In one operation, we move all water from cup i to cup j.
 * We must perform exactly K operations.
 * To maximize the water in a single cup, we want to aggregate as much water
 * as possible into one cup.
 * 
 * Each operation reduces the number of non-empty cups by 1.
 * We can perform at most N-1 operations to merge all water into one cup.
 * If K <= N-1, we can pick the largest cup and merge K other cups into it.
 * If K >= N, we can merge all N cups into one (using N-1 operations),
 * and then we have to perform the remaining operations.
 * Since we need to perform exactly K operations, and we have empty cups
 * available after the first N-1 operations, we can move the total sum
 * back and forth between two cups (or move 0 from an empty cup to the full one).
 * Effectively, if K >= N-1, the maximum amount is the sum of all A_i.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    if (K >= N - 1) {
        // We can merge everything into one cup.
        // Even if K > N-1, we can keep moving the total sum between two cups
        // or move 0 from an empty cup to the full one.
        cout << total_sum << "\n";
    } else {
        // We can only perform K merges.
        // To maximize the result, we should pick the largest cup and add
        // the K largest other cups to it.
        sort(A.begin(), A.end(), greater<long long>());
        long long max_val = A[0];
        for (int i = 1; i <= K; ++i) {
            max_val += A[i];
        }
        cout << max_val << "\n";
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