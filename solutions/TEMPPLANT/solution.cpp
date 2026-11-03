#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We are given N days with temperatures A_1, A_2, ..., A_N.
 * We need to choose two consecutive days (i, i+1) to plant the seed.
 * The height of the tree is min(A_i, A_{i+1}).
 * We want to maximize this value over all possible i from 0 to N-2.
 * 
 * Complexity:
 * Time: O(N) per test case. With N=100 and T=100, total operations ~10^4.
 * Space: O(N) to store the temperatures.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Initialize max_height with the smallest possible value
    // Since A_i >= 1, 0 is a safe initial value.
    int max_height = 0;
    
    // Iterate through all possible pairs of consecutive days
    // There are N-1 such pairs.
    for (int i = 0; i < N - 1; ++i) {
        int current_height = min(A[i], A[i + 1]);
        if (current_height > max_height) {
            max_height = current_height;
        }
    }
    
    cout << max_height << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}