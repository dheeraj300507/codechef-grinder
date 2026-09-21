#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef participates in two races: X and Y.
 * The rival participates in two races: A and B.
 * Chef can win a race if the rival is not participating in that specific race.
 * 
 * We need to count how many of {X, Y} are NOT in {A, B}.
 * 
 * Complexity:
 * Time: O(1) per test case, O(T) total.
 * Space: O(1).
 */

void solve() {
    int X, Y, A, B;
    if (!(cin >> X >> Y >> A >> B)) return;

    int gold_medals = 0;

    // Check if Chef wins race X
    if (X != A && X != B) {
        gold_medals++;
    }

    // Check if Chef wins race Y
    if (Y != A && Y != B) {
        gold_medals++;
    }

    cout << gold_medals << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}