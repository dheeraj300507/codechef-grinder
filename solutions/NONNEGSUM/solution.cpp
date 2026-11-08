#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Problem Analysis:
 * We want to find the largest subsequence with a non-negative sum.
 * 1. Calculate the total sum of the array.
 * 2. If total_sum >= 0, the largest subsequence is the entire array (size N).
 * 3. If total_sum < 0, we must remove elements to make the sum >= 0.
 *    To maximize the size of the remaining subsequence, we should remove 
 *    the minimum number of elements. Removing a negative number x increases 
 *    the sum by |x|. To reach a non-negative sum with the fewest removals, 
 *    we remove the most negative numbers (smallest values) first.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    long long total_sum = 0;
    vector<long long> negatives;
    int pos_count = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
        if (A[i] < 0) {
            negatives.push_back(A[i]);
        } else if (A[i] > 0) {
            pos_count++;
        }
    }

    // If total sum is already non-negative, the whole array is the answer.
    if (total_sum >= 0) {
        cout << N << "\n";
        return;
    }

    // Sort negative numbers ascending (e.g., -10, -5, -2)
    sort(negatives.begin(), negatives.end());

    int removed = 0;
    for (long long val : negatives) {
        total_sum -= val; // Removing a negative value increases the sum
        removed++;
        if (total_sum >= 0) {
            cout << N - removed << "\n";
            return;
        }
    }

    // If we removed all negative numbers and the sum is still < 0,
    // it means there were no positive numbers to keep the sum non-negative.
    // The only way to have a non-negative sum is an empty subsequence (sum 0).
    cout << 0 << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}