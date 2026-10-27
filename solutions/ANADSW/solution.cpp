#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can swap any two elements A[i] and A[j] if |i - j| > 1.
 * 
 * Case N = 1: Always sorted. YES.
 * Case N = 2: If A[1] <= A[2], YES. If A[1] > A[2], we cannot swap (distance is 1), so NO.
 * Case N = 3: We can swap (1, 3). We can reach any permutation that can be formed by 
 * swapping (1, 3). Specifically, we can swap A[1] and A[3]. 
 * If we have indices {1, 2, 3}, we can swap (1, 3). 
 * This allows us to sort any array of size 3 or more.
 * Why? 
 * If N >= 4:
 * We can swap any A[i], A[j] where |i-j| > 1.
 * This is equivalent to saying we can swap any two elements except adjacent ones.
 * With N >= 4, we can always use an intermediate element to swap any two adjacent elements.
 * For example, to swap A[i] and A[i+1]:
 * If N >= 4, there exists some index k such that k != i, k != i+1, k != i-1 (if exists), etc.
 * Actually, for N >= 4, we can always perform a 3-cycle or swap any two elements using 
 * an auxiliary element.
 * 
 * Summary:
 * - If N = 1: YES
 * - If N = 2: YES if sorted, NO otherwise.
 * - If N = 3: YES (always possible to sort by swapping 1 and 3 if needed, then 
 *   checking if the resulting array is sorted). Actually, for N=3, we can reach 
 *   permutations (1,2,3), (3,2,1), (1,3,2) is not possible? Wait.
 *   Let's re-check N=3:
 *   Indices {1, 2, 3}. Swaps allowed: (1, 3).
 *   We can reach:
 *   (A1, A2, A3) -> (A3, A2, A1)
 *   If the array is already sorted, YES.
 *   If swapping (1, 3) makes it sorted, YES.
 *   If neither, NO.
 * - If N >= 4: Always YES. Any permutation can be reached because we can swap 
 *   any non-adjacent elements, which is sufficient to generate the symmetric group S_N.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        // Check original
        bool sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i + 1]) sorted = false;
        if (sorted) {
            cout << "YES" << "\n";
            return;
        }
        // Check after swapping 1 and 3
        swap(A[0], A[2]);
        sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i + 1]) sorted = false;
        if (sorted) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, it is always possible to sort the array.
        cout << "YES" << "\n";
    }
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