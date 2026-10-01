#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Sushil is at the N-th position (index N-1 in 0-indexed array).
 * His wealth is A[N-1].
 * He can bully the person directly in front of him if that person's wealth 
 * is <= (Sushil's wealth / 2).
 * Since he only bullies the person directly in front of him, we check from 
 * the person at index N-2 down to 0.
 * As soon as he encounters someone he cannot bully, he stops moving forward.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int sushil_wealth = A[N - 1];
    int current_pos = N; // 1-based position

    // Check people from the one directly in front of Sushil backwards
    for (int i = N - 2; i >= 0; --i) {
        // Condition: wealth <= sushil_wealth / 2
        // Using integer division as per problem statement (A_i <= X/2)
        if (A[i] <= (sushil_wealth / 2)) {
            current_pos--;
        } else {
            // Cannot bully this person, stop moving forward
            break;
        }
    }

    cout << current_pos << "\n";
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