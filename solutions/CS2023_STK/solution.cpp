#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Function to calculate the maximum streak of days with > 0 problems solved.
 */
long long getMaxStreak(int n, const vector<long long>& problems) {
    long long max_streak = 0;
    long long current_streak = 0;
    for (int i = 0; i < n; ++i) {
        if (problems[i] > 0) {
            current_streak++;
        } else {
            max_streak = max(max_streak, current_streak);
            current_streak = 0;
        }
    }
    max_streak = max(max_streak, current_streak);
    return max_streak;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> om(n), addy(n);
    for (int i = 0; i < n; ++i) cin >> om[i];
    for (int i = 0; i < n; ++i) cin >> addy[i];

    long long om_max = getMaxStreak(n, om);
    long long addy_max = getMaxStreak(n, addy);

    if (om_max > addy_max) {
        cout << "Om" << endl;
    } else if (addy_max > om_max) {
        cout << "Addy" << endl;
    } else {
        cout << "Draw" << endl;
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