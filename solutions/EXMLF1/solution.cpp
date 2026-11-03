#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N cars with distance d_i and time t_i.
 * Speed v_i = d_i / t_i.
 * We need to find the car with the maximum speed.
 * If multiple cars have the same maximum speed, choose the one with the smallest label (index).
 * 
 * Constraints:
 * T <= 100, N <= 100, d_i, t_i <= 100.
 * Since d_i and t_i are small, we can use simple integer division.
 * Time complexity per test case: O(N).
 * Total time complexity: O(T * N), which is well within the 1s limit.
 */

void solve() {
    int N;
    cin >> N;
    
    int best_label = -1;
    int max_speed = -1;
    
    for (int i = 1; i <= N; ++i) {
        int d, t;
        cin >> d >> t;
        int current_speed = d / t;
        
        // If current car is faster, update max_speed and best_label
        if (current_speed > max_speed) {
            max_speed = current_speed;
            best_label = i;
        }
        // If speeds are equal, we keep the existing best_label because 
        // we are iterating from 1 to N, so the first one encountered 
        // is already the minimum label.
    }
    
    cout << best_label << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}