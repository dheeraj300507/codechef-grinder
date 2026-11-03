#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs to pick one defender (type 0) and one forward (type 1).
 * He already spent S dollars.
 * Total budget is 100.
 * So, we need to find min_defender_price + min_forward_price + S <= 100.
 * 
 * Constraints:
 * N <= 100, P_i <= 100.
 * We can iterate through all players, find the minimum price for a defender
 * and the minimum price for a forward.
 * If both exist, check the condition.
 */

void solve() {
    int N, S;
    cin >> N >> S;
    
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    
    int min_defender = 101; // Initialize with a value > max possible price
    int min_forward = 101;
    
    bool found_defender = false;
    bool found_forward = false;
    
    for (int i = 0; i < N; ++i) {
        if (T[i] == 0) { // Defender
            if (P[i] < min_defender) {
                min_defender = P[i];
                found_defender = true;
            }
        } else { // Forward
            if (P[i] < min_forward) {
                min_forward = P[i];
                found_forward = true;
            }
        }
    }
    
    if (found_defender && found_forward && (S + min_defender + min_forward <= 100)) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}