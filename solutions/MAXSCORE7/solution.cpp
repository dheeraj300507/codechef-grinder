#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a binary array A of length N (even).
 * We perform N/2 operations. In each operation, we pick adjacent elements A_i, A_{i+1},
 * add |A_i - A_{i+1}| to the score, and remove them.
 * 
 * Since the array is binary (0s and 1s), |A_i - A_{i+1}| is 1 if the pair is (0, 1) or (1, 0),
 * and 0 if the pair is (0, 0) or (1, 1).
 * 
 * We want to maximize the number of (0, 1) or (1, 0) pairs we can form.
 * Let c0 be the count of 0s and c1 be the count of 1s in the array.
 * Each operation removes one 0 and one 1 (if we pick a pair with difference 1),
 * or two 0s, or two 1s.
 * 
 * To maximize the score, we want to pair as many 0s with 1s as possible.
 * Each such pair contributes 1 to the score and reduces both c0 and c1 by 1.
 * If we have c0 zeros and c1 ones, we can form at most min(c0, c1) pairs of (0, 1).
 * Since we can always choose to remove adjacent elements, we can effectively
 * bring any 0 and any 1 together by removing the elements between them.
 * Thus, the maximum score is simply min(c0, c1).
 */

void solve() {
    int N;
    cin >> N;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 0) {
            c0++;
        } else {
            c1++;
        }
    }
    cout << min(c0, c1) << "\n";
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