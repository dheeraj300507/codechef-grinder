#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N dice, each with faces {1, 2, 3, 4, 5, 6}.
 * We need to choose x_1, ..., x_N such that sum(x_i) = S and 1 <= x_i <= 6.
 * After choosing, these x_i are replaced by 0.
 * The new faces of die i are {0, 1, 2, 3, 4, 5, 6} \ {x_i}.
 * We want to maximize the sum of the new choices y_i, where y_i is from the new set of faces.
 * 
 * To maximize sum(y_i), we want each y_i to be as large as possible.
 * For a specific die i, if we chose x_i, the available values are {0, 1, 2, 3, 4, 5, 6} \ {x_i}.
 * The maximum value we can pick for y_i is:
 * - If x_i < 6, we can pick 6.
 * - If x_i = 6, we can pick 5.
 * 
 * So, y_i = 6 if x_i != 6, and y_i = 5 if x_i = 6.
 * Total score = sum(y_i) = sum_{i=1}^N (6 if x_i != 6 else 5)
 * Let k be the number of dice where we chose 6.
 * Then sum(x_i) = (N - k) * (average value of non-6 choices) + k * 6 = S.
 * To maximize the score (N-k)*6 + k*5 = 6N - k, we need to minimize k.
 * 
 * We need to choose x_i such that sum(x_i) = S and the number of 6s (k) is minimized.
 * To minimize k, we should make the other (N-k) dice as large as possible (i.e., 5).
 * So, S = (N-k)*5 + k*6 = 5N - 5k + 6k = 5N + k.
 * Thus, k = S - 5N.
 * However, k must be at least 0. Also, since each x_i <= 6, we have S <= 6N.
 * If S <= 5N, we can pick all x_i <= 5, so k = 0.
 * If S > 5N, we must pick at least S - 5N dice to be 6.
 * 
 * Therefore, the minimum number of 6s required is k = max(0, S - 5N).
 * The maximum score is 6*(N - k) + 5*k = 6N - 6k + 5k = 6N - k.
 */

void solve() {
    long long N, S;
    cin >> N >> S;
    
    // k is the minimum number of 6s we must use to reach sum S
    // Each die can contribute at most 5 if it's not a 6.
    // If we use k dice as 6, the remaining N-k dice can contribute at most 5 each.
    // S <= (N-k)*5 + k*6 = 5N + k
    // k >= S - 5N
    long long k = max(0LL, S - 5 * N);
    
    long long max_score = 6 * (N - k) + 5 * k;
    cout << max_score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}