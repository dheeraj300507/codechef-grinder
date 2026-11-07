#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * N customers, M cakes.
 * Every customer needs at least 1 cake.
 * Remaining cakes = M - N.
 * Each additional cake given to a customer makes them happy.
 * We can make at most M - N customers happy.
 * Also, we cannot make more than N customers happy.
 * Max happy = min(N, M - N).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    // Reading until EOF as the problem description implies 
    // the input structure might not start with T.
    while (cin >> N >> M) {
        long long ans = min(N, M - N);
        cout << ans << "\n";
    }
    return 0;
}