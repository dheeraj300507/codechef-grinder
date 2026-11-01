#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. We are given an array A of size N.
 * 2. First, calculate the frequency of each distinct number in A.
 * 3. Second, calculate the frequency of these frequencies (i.e., how many numbers appear X times).
 * 4. Find the frequency value that appears the most times in the second step.
 * 5. If there's a tie, pick the smallest frequency value.
 * 
 * Constraints:
 * N <= 10000, A_i <= 10000 (though problem says A_i <= 10, we should handle up to N).
 * Time complexity per test case: O(N) to count frequencies, O(N) to count frequency of frequencies.
 * Total time complexity: O(T * N), which fits well within 1s.
 */

void solve() {
    int N;
    cin >> N;
    
    // Map to store frequency of each number
    // Since A_i can be up to 10000, a map or an array of size 10001 works.
    map<int, int> counts;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        counts[val]++;
    }
    
    // Map to store how many numbers have a specific frequency
    map<int, int> freq_of_freq;
    for (auto const& [val, count] : counts) {
        freq_of_freq[count]++;
    }
    
    int max_occurrences = 0;
    int result_freq = -1;
    
    // Find the frequency that appears the most times
    // If there's a tie, we want the smallest frequency value.
    // Iterating through the map (which is sorted by key) ensures we handle ties correctly.
    for (auto const& [freq, occurrences] : freq_of_freq) {
        if (occurrences > max_occurrences) {
            max_occurrences = occurrences;
            result_freq = freq;
        }
    }
    
    cout << result_freq << "\n";
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