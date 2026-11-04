#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 26 types of viruses ('a' through 'z').
 * For each virus type, let count[char] be the number of people infected by that virus.
 * We have C isolation centers.
 * For a specific virus type with count[char] people:
 * - Each isolation center can hold at most 1 person of this virus type.
 * - If we have C isolation centers, we can place min(count[char], C) people in isolation.
 * - The remaining people, max(0, count[char] - C), must go to the pending queue.
 * 
 * Total people in the pending queue = sum over all 26 characters of max(0, count[char] - C).
 * 
 * Time Complexity:
 * - Preprocessing: O(N) to count character frequencies.
 * - Query: O(26) per query.
 * - Total: O(T * (N + Q * 26)), which fits well within the 2s time limit for 10^5 constraints.
 */

void solve() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    // Count frequency of each character
    vector<long long> freq(26, 0);
    for (char c : S) {
        freq[c - 'a']++;
    }

    // Process each query
    while (Q--) {
        long long C;
        cin >> C;
        
        long long pending_queue_size = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > C) {
                pending_queue_size += (freq[i] - C);
            }
        }
        cout << pending_queue_size << "\n";
    }
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