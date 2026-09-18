#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Mutated Minions (CHN15A)
 * Approach:
 * For each minion with characteristic value V, the new value becomes V + K.
 * We count how many minions satisfy (V + K) % 7 == 0.
 * 
 * Complexity Analysis:
 * Time Complexity: O(T * N), where T is the number of test cases and N is the number of minions.
 * With T=100 and N=100, total operations are ~10^4, well within the 1s time limit.
 * Space Complexity: O(1), as we process each minion value on the fly.
 */

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    int wolverine_count = 0;
    for (int i = 0; i < n; ++i) {
        long long v;
        cin >> v;
        
        // Check if the transmogrified value is divisible by 7
        if ((v + k) % 7 == 0) {
            wolverine_count++;
        }
    }

    cout << wolverine_count << "\n";
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}