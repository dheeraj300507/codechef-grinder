#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with X people. We iterate through the array A.
 * At each step i, the number of people changes by A[i].
 * We need to track the current number of people and maintain the maximum value observed.
 * 
 * Constraints:
 * T <= 100, N <= 100, X <= 100, A_i between -100 and 100.
 * The maximum possible number of people will not exceed 100 + (100 * 100) = 10100.
 * Standard 'int' is sufficient, but 'long long' is used for safety as per instructions.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;

    long long current_people = X;
    long long max_people = X;

    for (int i = 0; i < N; ++i) {
        long long change;
        cin >> change;
        current_people += change;
        if (current_people > max_people) {
            max_people = current_people;
        }
    }

    cout << max_people << "\n";
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