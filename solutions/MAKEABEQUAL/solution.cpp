#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two arrays A and B of length N.
 * In one operation, we pick A[i] and B[j] and increment both by 1.
 * Let the final state of the arrays be A' and B' where A'[k] = B'[k] for all k.
 * Let x_i be the total amount added to A[i] and y_j be the total amount added to B[j].
 * Since we perform the same number of operations (say K) on A and B,
 * the sum of increments for A must equal the sum of increments for B:
 * Sum(x_i) = K and Sum(y_j) = K.
 * 
 * For each index i, the final value must be V_i = A[i] + x_i = B[i] + y_i.
 * This implies x_i - y_i = B[i] - A[i].
 * 
 * Let diff_i = B[i] - A[i].
 * If A[i] > B[i], we MUST add at least (A[i] - B[i]) to B[i] to catch up.
 * If B[i] > A[i], we MUST add at least (B[i] - A[i]) to A[i] to catch up.
 * 
 * Let pos_diff = sum of (B[i] - A[i]) for all i where B[i] > A[i].
 * Let neg_diff = sum of (A[i] - B[i]) for all i where A[i] > B[i].
 * 
 * If A[i] > B[i], we need to add at least (A[i] - B[i]) to B.
 * If B[i] > A[i], we need to add at least (B[i] - A[i]) to A.
 * 
 * For a solution to exist, we must be able to satisfy all requirements.
 * The total operations K must be at least max(pos_diff, neg_diff).
 * Also, since we can always add to any index, if pos_diff == neg_diff, 
 * then K = pos_diff = neg_diff is sufficient.
 * If pos_diff != neg_diff, it is impossible to make them equal because 
 * the total increments applied to A must equal total increments applied to B.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long pos_diff = 0; // Sum of (B[i] - A[i]) where B[i] > A[i]
    long long neg_diff = 0; // Sum of (A[i] - B[i]) where A[i] > B[i]

    for (int i = 0; i < N; ++i) {
        if (B[i] > A[i]) {
            pos_diff += (B[i] - A[i]);
        } else if (A[i] > B[i]) {
            neg_diff += (A[i] - B[i]);
        }
    }

    if (pos_diff == neg_diff) {
        cout << pos_diff << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}