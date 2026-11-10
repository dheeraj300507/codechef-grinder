#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Train A reaches station i+1 at time T_A[i] = sum(P[0...i-1]).
 * Train B starts from station i at time max(arrival_time_of_B_at_i, arrival_time_of_A_at_i+1).
 * Let B[i] be the time train B reaches station i+1.
 * B[0] = P[0] (since A reaches station 2 at P[0], B starts at P[0] and takes P[0] to reach station 2).
 * For i > 0:
 * B[i] = max(B[i-1], A_arrival_at_i+1) + P[i]
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store P, or O(1) if processed on the fly.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> P(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> P[i];
    }

    long long current_time_A = 0;
    long long current_time_B = 0;

    for (int i = 0; i < N - 1; ++i) {
        // Train A reaches the next station
        current_time_A += P[i];
        
        // Train B can only depart from current station if A has reached the next station
        // B's arrival at the next station is max(B's current time, A's arrival at next) + travel time
        if (current_time_B < current_time_A) {
            current_time_B = current_time_A + P[i];
        } else {
            current_time_B = current_time_B + P[i];
        }
    }

    cout << current_time_B << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}