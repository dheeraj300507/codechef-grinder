#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has score C_score, Chefina has score B_score.
 * We want to find the minimum number of rounds to change such that C_score > B_score.
 * 
 * Let:
 * - W: number of rounds Chef already wins.
 * - L: number of rounds Chefina wins.
 * - D: number of rounds that are draws.
 * 
 * If we change a round where Chefina won (L), we can turn it into a win for Chef.
 * This increases Chef's score by 1 and decreases Chefina's score by 1.
 * Net change in (C_score - B_score) is +2.
 * 
 * If we change a round that was a draw (D), we can turn it into a win for Chef.
 * This increases Chef's score by 1.
 * Net change in (C_score - B_score) is +1.
 * 
 * If we change a round where Chef already won (W), it's counter-productive.
 * 
 * Strategy:
 * 1. Calculate initial W, L, D.
 * 2. Current difference diff = W - L.
 * 3. We need diff > 0.
 * 4. While diff <= 0:
 *    - If L > 0, changing a loss to a win gives +2 to diff.
 *    - Else if D > 0, changing a draw to a win gives +1 to diff.
 *    - Increment count of changes.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int W = 0, L = 0, D = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == B[i]) {
            D++;
        } else if ((A[i] == 'R' && B[i] == 'S') || 
                   (A[i] == 'S' && B[i] == 'P') || 
                   (A[i] == 'P' && B[i] == 'R')) {
            W++;
        } else {
            L++;
        }
    }

    int diff = W - L;
    int changes = 0;

    while (diff <= 0) {
        if (L > 0) {
            diff += 2;
            L--;
            changes++;
        } else if (D > 0) {
            diff += 1;
            D--;
            changes++;
        } else {
            // This case should not be reachable given the problem constraints
            break;
        }
    }

    cout << changes << "\n";
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