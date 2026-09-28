#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N players. When player i is eliminated, A_i is added to the pool.
 * If we choose player k to be the winner, they are NOT eliminated.
 * Therefore, the prize pool will contain the sum of all A_i except A_k.
 * To maximize the prize pool, we need to choose k such that the sum of all A_i 
 * excluding A_k is maximized.
 * This is equivalent to (Total Sum of all A_i) - (Minimum A_i).
 * 
 * Complexity:
 * Time: O(N) per test case, O(sum of N) total.
 * Space: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N;
    cin >> N;
    
    long long total_sum = 0;
    long long min_val = -1;
    
    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        total_sum += val;
        
        if (i == 0) {
            min_val = val;
        } else {
            if (val < min_val) {
                min_val = val;
            }
        }
    }
    
    // The winner gets the sum of all A_i except the one that would have been 
    // added if the winner were eliminated. To maximize the prize, we exclude 
    // the smallest value.
    cout << (total_sum - min_val) << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}