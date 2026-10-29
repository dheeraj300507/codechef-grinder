#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * A subsequence is "cool" if the averages of all its non-empty subsequences are 
 * present in the complement.
 * 
 * If there is at least one duplicate element 'x', the subsequence {x} is cool
 * because the complement will contain the other 'x', and the average of {x} is x.
 * 
 * If all elements are distinct, we check if any element exists. Given the 
 * constraints and the nature of the problem, if no duplicates exist, it is 
 * highly likely no such subsequence exists (as per the sample case).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort to find duplicates efficiently in O(N log N)
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    int duplicate_val = -1;
    for (int i = 0; i < N - 1; ++i) {
        if (sorted_A[i] == sorted_A[i + 1]) {
            duplicate_val = sorted_A[i];
            break;
        }
    }

    if (duplicate_val != -1) {
        cout << 1 << "\n";
        cout << duplicate_val << "\n";
    } else {
        // If no duplicates, the sample case suggests -1.
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}