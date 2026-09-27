#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards with values A_i. We want to keep only cards that have the same value.
 * To minimize the number of moves (removals), we should maximize the number of cards 
 * we keep.
 * 
 * If we decide to keep all cards with value 'x', the number of cards we keep is 
 * equal to the frequency of 'x' in the input array.
 * The number of moves required would then be N - (frequency of 'x').
 * 
 * To minimize the moves, we need to maximize the frequency of 'x'.
 * Therefore, the answer is N - (maximum frequency of any value present in the array).
 * 
 * Constraints:
 * N <= 100, A_i <= 10.
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) since the range of A_i is small (1-10).
 */

void solve() {
    int N;
    cin >> N;
    
    // Since A_i is between 1 and 10, we can use a frequency array of size 11.
    int freq[11] = {0};
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        freq[val]++;
    }
    
    int max_freq = 0;
    for (int i = 1; i <= 10; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }
    
    // The minimum moves is total cards minus the count of the most frequent card.
    cout << (N - max_freq) << "\n";
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