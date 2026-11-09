#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs to pick boxes in order from 1 to N.
 * He can pick a sequence of boxes as long as their sum <= K.
 * If any single box weight > K, it's impossible to move it, return -1.
 * Otherwise, we greedily pack as many boxes as possible into one trip.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store weights.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }

    // Check if any single box is heavier than K
    for (int i = 0; i < N; ++i) {
        if (W[i] > K) {
            cout << -1 << "\n";
            return;
        }
    }

    int trips = 0;
    int current_weight = 0;
    int i = 0;
    
    while (i < N) {
        // Start a new trip
        trips++;
        current_weight = 0;
        
        // Fill the current trip as much as possible
        while (i < N && current_weight + W[i] <= K) {
            current_weight += W[i];
            i++;
        }
    }

    cout << trips << "\n";
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