#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of A[i] is different from A[i+1] for all i.
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Starts with Odd (Odd, Even, Odd, Even, ...)
 * Pattern 2: Starts with Even (Even, Odd, Even, Odd, ...)
 * 
 * We calculate the number of changes required to match Pattern 1 and Pattern 2,
 * then take the minimum of the two.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // count1: changes needed if we force the pattern: Odd, Even, Odd, Even...
    // count2: changes needed if we force the pattern: Even, Odd, Even, Odd...
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < N; ++i) {
        int parity = A[i] % 2; // 1 for Odd, 0 for Even
        
        // Pattern 1: index 0 should be Odd (1), index 1 should be Even (0)...
        // Expected parity at index i is (i % 2 == 0) ? 1 : 0
        int expected1 = (i % 2 == 0) ? 1 : 0;
        if (parity != expected1) {
            count1++;
        }

        // Pattern 2: index 0 should be Even (0), index 1 should be Odd (1)...
        // Expected parity at index i is (i % 2 == 0) ? 0 : 1
        int expected2 = (i % 2 == 0) ? 0 : 1;
        if (parity != expected2) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
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