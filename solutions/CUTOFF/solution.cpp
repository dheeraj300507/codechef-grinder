#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N students with distinct scores A_i.
 * Exactly X students pass the test.
 * A student passes if their score > passing_mark.
 * We want the maximum possible passing_mark.
 * 
 * To have exactly X students pass, we need the X students with the highest 
 * scores to be the ones who pass.
 * If we sort the scores in descending order: S_1 > S_2 > ... > S_N.
 * The students who pass are the ones with scores S_1, S_2, ..., S_X.
 * The student who barely passed is the one with the X-th highest score (S_X).
 * Any score P such that S_X > P >= S_{X+1} (if X < N) would result in exactly X students passing.
 * To maximize P, we choose P = S_X - 1.
 * 
 * If X = N, all students pass. The condition is that all scores must be > P.
 * The smallest score is S_N. So we need S_N > P. The maximum P is S_N - 1.
 * Since the problem constraints say A_i >= 1, if S_N = 1, P could be 0.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to easily pick the X-th highest score
    sort(A.begin(), A.end(), greater<int>());

    // The X-th student (index X-1) is the one with the lowest score among those who passed.
    // Let this score be S_X.
    // To have exactly X students pass, the passing mark P must satisfy:
    // P < S_X AND P >= S_{X+1} (if X < N).
    // The maximum such integer P is S_X - 1.
    
    int passing_mark = A[X - 1] - 1;
    cout << passing_mark << "\n";
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