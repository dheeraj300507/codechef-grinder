#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/**
 * Problem Analysis:
 * The probability of rolling A is (count of A) / N.
 * The probability of rolling B is (count of B) / N.
 * Since the tosses are independent, the probability of both occurring is:
 * ((count of A) / N) * ((count of B) / N)
 * 
 * Constraints:
 * N <= 10^4, T <= 70. An O(N) approach per test case is well within limits.
 */

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;
    
    vector<int> x(N);
    double countA = 0;
    double countB = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        if (x[i] == A) {
            countA++;
        }
        if (x[i] == B) {
            countB++;
        }
    }
    
    double probA = countA / (double)N;
    double probB = countB / (double)N;
    
    cout << fixed << setprecision(10) << (probA * probB) << endl;
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