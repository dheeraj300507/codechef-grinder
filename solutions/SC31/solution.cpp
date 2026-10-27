#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that when two contestants battle, weapons of the same type
 * are destroyed (XOR operation). The winner collects the remaining weapons of the loser.
 * This implies that the final set of weapons held by the winner is the XOR sum
 * of the initial weapon sets of all N participants.
 * 
 * Let S_i be the binary string representing the weapons of participant i.
 * The final state is S_1 XOR S_2 XOR ... XOR S_N.
 * Since the XOR operation is associative and commutative, the order of battles
 * does not matter. The final result is always the same regardless of the tournament bracket.
 * 
 * Complexity:
 * Time: O(T * N * L), where L = 10 (length of string).
 * Space: O(L) to store the current XOR sum.
 */

void solve() {
    int N;
    cin >> N;
    
    // We can represent the 10 weapons as a bitmask or an integer array.
    // Since the length is fixed at 10, an integer XOR sum is sufficient.
    int result_mask = 0;
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        // Convert binary string to integer bitmask
        int current_mask = 0;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == '1') {
                current_mask |= (1 << (9 - j));
            }
        }
        
        // XOR the current participant's weapons into the total
        result_mask ^= current_mask;
    }
    
    // Count the number of set bits in the final mask
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if ((result_mask >> i) & 1) {
            count++;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}