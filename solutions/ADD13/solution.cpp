#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let 'a' be the number of times we add 1, and 'b' be the number of times we add 3.
 * We are given:
 * 1) a + b = N  (Total number of turns)
 * 2) 1*a + 3*b = M (Final sum)
 * 
 * From (1), a = N - b.
 * Substitute into (2):
 * (N - b) + 3b = M
 * N + 2b = M
 * 2b = M - N
 * 
 * For a valid solution:
 * 1) b must be non-negative: M - N >= 0 => M >= N
 * 2) b must be an integer: (M - N) must be divisible by 2 (i.e., M - N is even)
 * 3) a must be non-negative: a = N - b >= 0 => N >= b
 *    Substitute b = (M - N) / 2:
 *    N >= (M - N) / 2
 *    2N >= M - N
 *    3N >= M
 * 
 * So, the conditions are:
 * 1) M >= N
 * 2) (M - N) % 2 == 0
 * 3) M <= 3 * N
 */

void solve() {
    long long N, M;
    cin >> N >> M;

    // Condition 1: M must be at least N (since we add at least 1 each turn)
    // Condition 2: M - N must be even (since 2b = M - N)
    // Condition 3: M must be at most 3*N (since we add at most 3 each turn)
    
    if (M >= N && (M - N) % 2 == 0 && M <= 3 * N) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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