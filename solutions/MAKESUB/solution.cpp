#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make all black cells (1s) form a single contiguous block.
 * We can only change 0s to 1s.
 * 
 * Let the first occurrence of '1' be at index 'first' and the last 
 * occurrence of '1' be at index 'last'.
 * If there are no '1's, the cost is 0.
 * If there are '1's, all cells between 'first' and 'last' must be '1'.
 * Any '0' in the range [first, last] must be changed to '1'.
 * 
 * The number of changes required is simply the count of '0's 
 * between the first '1' and the last '1'.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int first = -1;
    int last = -1;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    // If no '1's exist, condition is already satisfied.
    if (first == -1) {
        cout << 0 << "\n";
        return;
    }

    // Count '0's between first and last '1'
    int changes = 0;
    for (int i = first; i <= last; ++i) {
        if (S[i] == '0') {
            changes++;
        }
    }

    cout << changes << "\n";
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