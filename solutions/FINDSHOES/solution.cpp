#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs N pairs of shoes. Each pair consists of 1 left and 1 right shoe.
 * Total shoes needed: N left shoes and N right shoes.
 * 
 * If M >= N:
 * Chef has enough left shoes. He only needs to buy N right shoes.
 * Total to buy = N.
 * 
 * If M < N:
 * Chef needs (N - M) more left shoes and N right shoes.
 * Total to buy = (N - M) + N = 2*N - M.
 */

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    if (m >= n) {
        // Chef has enough left shoes, just needs N right shoes
        cout << n << "\n";
    } else {
        // Chef needs (n - m) more left shoes and n right shoes
        cout << (n - m) + n << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}