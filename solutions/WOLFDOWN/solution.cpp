#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A wolf at position x eats a bird at x+1 and moves to x+1.
 * This effectively means a wolf can eat a bird if it can "reach" it.
 * Let's track the position of each wolf.
 * Since N is small (up to 100), we can simulate the process.
 * 
 * Simulation approach:
 * 1. Store the state of the forest as a vector/array.
 * 2. In each second, identify which wolves can eat a bird.
 * 3. A wolf at 'x' eats a bird at 'x+1' if 'x+1' is a bird.
 * 4. Since multiple wolves might move, we must be careful about the order.
 *    The problem states: "For every position x such that there is a wolf at position x 
 *    and a bird at position x+1, the wolf at position x will eat the bird."
 *    This happens simultaneously.
 * 5. We can simulate for N seconds (since a wolf can move at most N positions).
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // current_state[i] = 1 if wolf, 0 if bird, -1 if empty (eaten)
    vector<int> state(N);
    for (int i = 0; i < N; ++i) {
        state[i] = S[i] - '0';
    }

    // A bird is safe if it is never eaten.
    // We can track which birds are eaten.
    vector<bool> eaten(N, false);

    // Simulation: Max N seconds is sufficient as wolves only move right.
    for (int t = 0; t < N; ++t) {
        vector<int> next_state = state;
        bool moved = false;
        
        // Identify moves
        vector<int> wolf_moves(N, -1);
        for (int i = 0; i < N - 1; ++i) {
            if (state[i] == 1 && state[i + 1] == 0) {
                wolf_moves[i] = i + 1;
                moved = true;
            }
        }

        if (!moved) break;

        // Apply moves
        for (int i = 0; i < N - 1; ++i) {
            if (wolf_moves[i] != -1) {
                eaten[wolf_moves[i]] = true;
                next_state[i] = -1; // Wolf left this spot
                next_state[wolf_moves[i]] = 1; // Wolf arrived here
            }
        }
        state = next_state;
    }

    int safe_birds = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0' && !eaten[i]) {
            safe_birds++;
        }
    }
    cout << safe_birds << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}