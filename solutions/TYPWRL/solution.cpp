#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Typing World
 * Approach:
 * 1. Store the left-hand keys in a boolean array or a hash set for O(1) lookup.
 * 2. Iterate through the string S. For each character, determine if it's typed by the left hand (L) or right hand (R).
 * 3. Keep track of the current hand being used and the current streak length.
 * 4. If the current character's hand matches the previous one, increment the streak.
 * 5. If it differs, reset the streak to 1 and update the current hand.
 * 6. Maintain a global maximum of these streaks.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string S, L;
    cin >> S >> L;

    // Use a boolean array to mark left-hand keys for O(1) access
    bool is_left[26] = {false};
    for (char c : L) {
        is_left[c - 'a'] = true;
    }

    int max_streak = 0;
    int current_streak = 0;
    char last_hand = ' '; // 'L' for left, 'R' for right

    for (int i = 0; i < N; ++i) {
        char current_hand = is_left[S[i] - 'a'] ? 'L' : 'R';

        if (current_hand == last_hand) {
            current_streak++;
        } else {
            current_streak = 1;
            last_hand = current_hand;
        }

        if (current_streak > max_streak) {
            max_streak = current_streak;
        }
    }

    cout << max_streak << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}