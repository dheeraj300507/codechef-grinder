#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition is A_i - A_j = i - j
 * Rearranging the terms:
 * A_i - i = A_j - j
 * 
 * Let B_k = A_k - k for all 1 <= k <= N.
 * The condition becomes B_i = B_j for i < j.
 * 
 * We need to count the number of pairs (i, j) such that i < j and B_i = B_j.
 * This is equivalent to counting the frequency of each value in the array B.
 * If a value x appears 'count' times in B, it contributes (count * (count - 1)) / 2 
 * pairs to the total.
 * 
 * Constraints:
 * N <= 4 * 10^4, sum of N <= 2 * 10^5.
 * A_i - i can range from (1 - N) to (N - 1).
 * We can use a map or an offset array to store frequencies.
 * Since the range is roughly -40000 to 40000, an offset of 40000 is sufficient.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    // The values of A_i - i range from 1 - N to N - 1.
    // To use an array as a frequency map, we add an offset of N.
    // Max value of N is 40000, so offset 40000 is enough.
    // Using a map is safer and fits within time limits given the constraints.
    map<int, long long> freq;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        int val = A[i] - (i + 1);
        freq[val]++;
    }
    
    long long total_pairs = 0;
    for (auto const& [val, count] : freq) {
        if (count >= 2) {
            total_pairs += (count * (count - 1)) / 2;
        }
    }
    
    cout << total_pairs << "\n";
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