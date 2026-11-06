#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ved gets the tallest chair (max(A_i)).
 * Varun gets all other chairs.
 * Ved's total height = K + max(A_i)
 * Varun's total height = P + (sum of all A_i - max(A_i))
 * 
 * We need to compare these two values and print Ved, Varun, or Equal.
 * Constraints: N <= 100, K, P <= 10^4, A_i <= 100.
 * The maximum possible height is 10^4 + 100*100 = 20,000, 
 * which fits comfortably in a standard 32-bit integer.
 */

void solve() {
    int N;
    long long K, P;
    cin >> N >> K >> P;

    vector<long long> A(N);
    long long max_val = -1;
    long long sum_val = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > max_val) {
            max_val = A[i];
        }
        sum_val += A[i];
    }

    // Ved gets the tallest chair
    long long ved_height = K + max_val;
    
    // Varun gets all chairs except the tallest one
    long long varun_height = P + (sum_val - max_val);

    if (ved_height > varun_height) {
        cout << "Ved" << "\n";
    } else if (varun_height > ved_height) {
        cout << "Varun" << "\n";
    } else {
        cout << "Equal" << "\n";
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