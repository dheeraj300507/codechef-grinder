#include <iostream>
#include <vector>

using namespace std;

/**
 * The condition P[i] >= (P[i+1] - P[i-1])^2 is satisfied if 
 * |P[i+1] - P[i-1]| is small.
 * By interleaving the first half and the second half of the 
 * range [1, N], we ensure that the difference between 
 * adjacent elements in the interleaved sequence is roughly N/2, 
 * but the difference between elements at distance 2 is very small (usually 1).
 */

void solve() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << 1 << "\n";
        return;
    }
    
    vector<int> p(N);
    int mid = (N + 1) / 2;
    int left = 1;
    int right = mid + 1;
    
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            p[i] = left++;
        } else {
            p[i] = right++;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << p[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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