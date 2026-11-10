#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to count how many times a button is pressed 3 consecutive times.
 * Once a streak of 3 is reached, the counter resets.
 * 
 * Approach:
 * Iterate through the string and maintain a current streak count.
 * If the current character matches the previous one, increment the streak.
 * If it doesn't match, reset the streak to 1.
 * If the streak reaches 3, increment the answer and reset the streak to 0.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count = 0;
    int streak = 0;
    char last_char = '\0';

    for (int i = 0; i < N; ++i) {
        if (S[i] == last_char) {
            streak++;
        } else {
            streak = 1;
            last_char = S[i];
        }

        if (streak == 3) {
            count++;
            streak = 0;
            last_char = '\0'; // Reset after opening
        }
    }

    cout << count << "\n";
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