#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N dice with values A_i.
 * Flipping a die changes its value from x to (7 - x).
 * We can perform at most K flips.
 * To maximize the sum, we should prioritize flipping dice where (7 - A_i) > A_i.
 * This inequality simplifies to 7 > 2 * A_i, or A_i < 3.5.
 * Thus, we should flip dice with values 1, 2, or 3.
 * 
 * Strategy:
 * 1. Calculate the initial sum of all dice.
 * 2. Identify all dice that can be improved by flipping (i.e., A_i < 7 - A_i).
 *    These are dice with values 1, 2, and 3.
 * 3. Sort these "improvable" dice in ascending order of their current value.
 *    Actually, since we want to maximize the gain (7 - A_i) - A_i, 
 *    we should flip the smallest values first (1 becomes 6, 2 becomes 5, 3 becomes 4).
 * 4. Perform up to K flips on the smallest available values.
 * 5. If we still have flips remaining after flipping all dice with A_i < 4, 
 *    we should only flip if it doesn't decrease the sum. However, 
 *    flipping a 4, 5, or 6 results in 3, 2, or 1, which always decreases the sum.
 *    Therefore, we only flip if (7 - A_i) > A_i.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    long long current_sum = 0;
    vector<int> to_flip;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        current_sum += A[i];
        // A die is worth flipping if 7 - A[i] > A[i]
        // i.e., A[i] < 3.5, so A[i] is 1, 2, or 3.
        if (7 - A[i] > A[i]) {
            to_flip.push_back(A[i]);
        }
    }

    // Sort to flip the most beneficial ones first (though any 1, 2, 3 is beneficial)
    sort(to_flip.begin(), to_flip.end());

    int flips_done = 0;
    for (int val : to_flip) {
        if (flips_done < K) {
            current_sum += (7 - val) - val;
            flips_done++;
        } else {
            break;
        }
    }

    cout << current_sum << "\n";
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